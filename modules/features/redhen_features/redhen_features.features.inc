<?php
/**
 * @file
 * redhen_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function redhen_features_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function redhen_features_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An event that you can register for.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_redhen_contact_type().
 */
function redhen_features_default_redhen_contact_type() {
  $items = array();
  $items['staff'] = entity_import('redhen_contact_type', '{
    "name" : "staff",
    "label" : "Staff",
    "locked" : "0",
    "weight" : "0",
    "data" : null
  }');
  $items['volunteer'] = entity_import('redhen_contact_type', '{
    "name" : "volunteer",
    "label" : "Volunteer",
    "locked" : "0",
    "weight" : "0",
    "data" : null
  }');
  return $items;
}

/**
 * Implements hook_default_redhen_engagement_score().
 */
function redhen_features_default_redhen_engagement_score() {
  $items = array();
  $items['engagement_score_1'] = entity_import('redhen_engagement_score', '{
    "name" : "engagement_score_1",
    "label" : "High-value engagement",
    "locked" : null,
    "score" : "10"
  }');
  $items['engagement_score_2'] = entity_import('redhen_engagement_score', '{
    "name" : "engagement_score_2",
    "label" : "Standard-value engagement",
    "locked" : null,
    "score" : "5"
  }');
  return $items;
}

/**
 * Implements hook_default_redhen_membership_type().
 */
function redhen_features_default_redhen_membership_type() {
  $items = array();
  $items['premium'] = entity_import('redhen_membership_type', '{
    "name" : "premium",
    "label" : "Premium",
    "role_id" : "3",
    "locked" : "0",
    "weight" : "0",
    "data" : null
  }');
  $items['standard'] = entity_import('redhen_membership_type', '{
    "name" : "standard",
    "label" : "Standard",
    "role_id" : null,
    "locked" : "0",
    "weight" : "0",
    "data" : null
  }');
  return $items;
}

/**
 * Implements hook_default_redhen_org_type().
 */
function redhen_features_default_redhen_org_type() {
  $items = array();
  $items['foundation'] = entity_import('redhen_org_type', '{
    "name" : "foundation",
    "label" : "Foundation",
    "locked" : "0",
    "weight" : "0",
    "data" : null
  }');
  $items['shelter'] = entity_import('redhen_org_type', '{
    "name" : "shelter",
    "label" : "Shelter",
    "locked" : "0",
    "weight" : "0",
    "data" : null
  }');
  return $items;
}

/**
 * Implements hook_default_registration_type().
 */
function redhen_features_default_registration_type() {
  $items = array();
  $items['registration_type_1'] = entity_import('registration_type', '{
    "name" : "registration_type_1",
    "label" : "Standard registration",
    "locked" : "0",
    "weight" : "0",
    "data" : null
  }');
  return $items;
}
