<?php

/**
 * Helper function for creating taxonomy terms and vocabularies.
 */
function ts_install_helpers_crud_create_terms($stubbed_terms = array()) {
  // @TODO - Create terms.
}

/**
 * Helper function for creating placeholder content.
 *
 * Returns an associative array of menu link items.
 *
 * @param - $stubbed_nodes
 *   An associative array of nodes to be created, keyed off the path of each new node.
 *
 */
function ts_install_helpers_crud_create_content($stubbed_nodes = array()) {
  module_load_include('inc', 'devel_generate');
  module_load_include('inc', 'devel_generate', 'image.devel_generate');
  module_load_include('inc', 'devel_generate', 'devel_generate.fields');
  
  // First set default pathauto node pattern.
  // Note: Definited in features but repeated here b/c it doesn't get picked up prior to generating content.
  variable_set('pathauto_node_pattern', '[node:title]');
  
  // Default node definition - stuff not captured added the way we want in node_object_prepare().
  $default_node = array(
    'type' => 'page',
    'language' => LANGUAGE_NONE,
    'format' => filter_fallback_format(),
    'uid' => 1,
    'body' => devel_create_greeking(120),
    'link_title' => '',
    'menu_name' => 'main-menu',
    'weight' => 0,
    'parent_path' => '',
  );
  
  $prepared_nodes = array();
  foreach ($stubbed_nodes as $path => $stub) {
    // Merge nodes parameters defined in this install profile with some default values.
    $prepared_nodes[$path] = array_merge($default_node, $stub);
  }
  
  // Generate page nodes, optionally adding to an array of menu items to be created.
  $node_menu_items = array();
  foreach ($prepared_nodes as $path => $prepared_node) {
    $node = new stdClass();
    $node->type = $prepared_node['type'];
    node_object_prepare($node);
    $node->title = $prepared_node['title'];
    $node->uid = $prepared_node['uid'];
    $node->language = $prepared_node['language'];
    $node->body[$node->language][0]['value'] = $prepared_node['body'];
    $node->body[$node->language][0]['summary'] = text_summary($node->body[$node->language][0]['value']);
    $node->body[$node->language][0]['format'] = $prepared_node['format'];
    $node->pathauto_perform_alias = FALSE;
    $node->path = array('alias' => $path, 'pathauto' => FALSE);
    node_save($node);
    
    // If a 'link title' has been set for the node, prep menu link creation.
    if (!empty($prepared_node['link_title'])) {
      $node_menu_items[$path] = array(
        'type' => 'node',
        'link_title' => $prepared_node['link_title'],
        'menu_name' => $prepared_node['menu_name'],
        'weight' => $prepared_node['weight'],
        'parent_path' => $prepared_node['parent_path'],
      );
    }
  }
  
  return $node_menu_items;
}

/**
 * Helper function for creating menu items.
 *
 * @param - $stubbed_menu_items
 *   An associative array of menu items to be created, keyed off the path of each new menu item.
 *
 */
function ts_install_helpers_crud_create_menu_items($stubbed_menu_items = array()) {
  
  // Rebuild prior to starting menu creation to capture menu items built by other modules, like the contact module.
  menu_rebuild();
  
  $default_item = array(
    'type' => 'codefied', // Nodes created in the install profile have 'node' type. Otherwise, assume 'codefied' as default.
    'menu_name' => 'main-menu',
    'weight' => 0,
    'parent_path' => '',
  );
  
  $prepared_menu_items = array();
  $new_menus = array();
  $existing_menus = array_keys(menu_get_menus());
  foreach ($stubbed_menu_items as $path => $stubbed_item) {
    // Merge menu parameters defined in the install profile with some default values.
    $prepared_menu_items[$path] = array_merge($default_item, $stubbed_item);
    // Check if referenced menu exists - if not, we'll create it.
    if (!in_array($stubbed_item['menu_name'], $existing_menus)) {
      $new_menus[] = array('menu_name' => $stubbed_item['menu_name']);
    }
  }

  // Create new menus.

  foreach ($new_menus as $menu) {
    if (!empty($menu['menu_name'])) {
      $menu['title'] = ucwords(str_replace('-', ' ', $menu['menu_name']));
      menu_save($menu);
    }
  }
  
  foreach ($prepared_menu_items as $path => $item) { // First time around the horn, save menu links.
    $prepared_menu_items[$path]['link_path'] = drupal_get_normal_path($path);
    $prepared_menu_items[$path]['mlid'] = menu_link_save($prepared_menu_items[$path]);
  }
  
  foreach ($prepared_menu_items as $item) { // Second time around the horn, set an parent link ids need for menu hierarchy.
    if (!empty($item['parent_path'])) {
      $item['parent_path'] = drupal_get_normal_path($item['parent_path']);
      $plid = db_query("SELECT mlid FROM {menu_links} WHERE menu_name = :menu_name AND link_path = :link_path",
        array(
          ':menu_name' => $item['menu_name'],
          ':link_path' => $item['parent_path'],
        )
      )->fetchfield();
      $item['plid'] = $plid;
      menu_link_save($item);
    }
  }
  
  // Clear the menu cache to get rid of any funkiness.
  menu_cache_clear_all();
}