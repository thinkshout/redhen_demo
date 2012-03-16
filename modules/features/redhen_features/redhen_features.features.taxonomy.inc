<?php
/**
 * @file
 * redhen_features.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function redhen_features_taxonomy_default_vocabularies() {
  return array(
    'note_type' => array(
      'name' => 'Type',
      'machine_name' => 'note_type',
      'description' => NULL,
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
