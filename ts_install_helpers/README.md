#### Common helper functions useful for Drupal 7.x installation profile development. See snippet below for more details.

    /**
     * ABOUT: The following code snippet shows how to use the CRUD tools in ts_install_helpers_crud.inc to quickly create placeholder nodes
     * and menu items in a Drupal 7.x installation profile. This is /not/ a working install profile. You can call the CRUD functions
     * anywhere in your install profile. We generally do so in a post_install tasks, to ensure any menu paths defined in modules have
     * been loaded into the database.
    
    /**
     * Implement hook_install_tasks_alter().
     */
    function example_profile_install_tasks_alter(&$tasks, $install_state) {
      $tasks += array(
        'example_profile_post_install' => array(
          'display_name' => st('Example Install Tasks'),
      ));
    }
    
    /**
     * Post install tasks.
     *
     * @param string $install_state 
     */
    function example_profile_post_install(&$install_state) {
      include_once 'ts/install_helpers/ts_install_helpers_crud.inc'; // Load helper functions. Note: assumes this file is placed in the same folder as the .install file.
      
      ///// Begin defining taxonomies, nodes and menu items. /////
      
      // Optionally, add terms to be created here.
      $stubbed_terms = array(); // @TODO.
      
      // Optionally, add the nodes to create on install here.
      // Include a 'link_title' to create a menu link for a given node.
      // Note: if this array references menus that do not exist yet, they will be created in ts_install_helpers_crud_menu_items().
      // Note: if setting a 'parent_path' make sure that your menu item has the same 'menu_name' as the parent link.
      $stubbed_nodes = array(
        'example/parent' => array('title' => 'This is a placeholder node', 'link_title' => 'Parent link'),
        'example/child' => array('title' => 'This is a placeholder node', 'link_title' => 'Child link', 'parent_path' => 'example/parent'),
      );
      
      // Optionally, add menu items to create/alter that point to codified URLs.
      // Note: if this array references menus that do not exist yet, they will be created in ts_install_helpers_crud_menu_items.
      // Note: if setting a 'parent_path' make sure that your menu item has the same 'menu_name' as the parent link.
      // In the example below we create a new footer menu.
      $coded_menu_items = array(
        'contact' => array('title' => 'Example link to contact form', 'link_title' => 'Contact Us', 'menu_name' => 'menu-footer'),
      );
      
      ///// End defining taxonomies, nodes and menu items. /////
    
      ts_install_helpers_crud_create_terms($stubbed_terms); // @TODO.
      $node_menu_items = ts_install_helpers_crud_create_content($stubbed_nodes); // Returns an array of menu items to be created.
      $stubbed_menu_items = array_merge($node_menu_items, $coded_menu_items); // Merges menu items for newly created nodes with additional menu items.
      ts_install_helpers_crud_create_menu_items($stubbed_menu_items); // Creates the menu items.
    
    }