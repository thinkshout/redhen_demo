<?php
/**
 * @file
 * redhen_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function redhen_features_user_default_roles() {
  $roles = array();

  // Exported role: Premium
  $roles['Premium'] = array(
    'name' => 'Premium',
    'weight' => '2',
  );

  return $roles;
}
