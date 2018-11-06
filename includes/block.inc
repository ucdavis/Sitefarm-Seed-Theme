<?php

/**
 * @file
 * Theme and preprocess functions for block.
 */

use Drupal\block\Entity\Block;

/**
 * Implements hook_preprocess_block().
 */
function sitefarm_seed_preprocess_block(array &$variables) {
  // Apply styles based on region.
  _sitefarm_seed_block_region_styles($variables);
}


/**
 * Implements hook_theme_suggestions_block_alter().
 */
function sitefarm_seed_theme_suggestions_block_alter(array &$suggestions, array $variables) {
  // Add theme suggestions for custom blocks.
  if (isset($variables['elements']['content']['#block_content'])) {
    $pattern = 'block__' . $variables['elements']['content']['#block_content']->bundle();

    // Add the suggestion after normal block suggestions but before single
    // specific id suggestions.
    array_splice($suggestions, 2, 0, $pattern);
  }
}

/**
 * Style blocks within a region.
 *
 * @param array $variables
 */
function _sitefarm_seed_block_region_styles(array &$variables) {
  // Exit if there is no block ID (likely because it is a field block).
  if (empty($variables['elements']['#id'])) {
    return;
  }

  $block = Block::load($variables['elements']['#id']);

  // Exit out if a block can not be found.
  if (!$block) {
    return;
  }

  // Get the region.
  $region = $block->getRegion();

  // Add .panel and .o-box if Content or Sidebar regions.
  $box_regions = [
    'sidebar_first',
    'sidebar_second',
    'content',
  ];
  if (in_array($region, $box_regions)) {
    $variables['class_panel'] = (isset($variables['class_panel'])) ? $variables['class_panel'] : TRUE;
    $variables['class_box'] = (isset($variables['class_box'])) ? $variables['class_box'] : TRUE;
  }

}
