<?php
/**
 * @file
 * Theme and preprocess functions for html template
 */

use Drupal\Component\Utility\Html;

/**
 * Implements hook_preprocess_HOOK() for html.html.twig.
 */
function sitefarm_seed_preprocess_html(array &$variables) {
  // Add a Node ID variable.
  if ($node = \Drupal::request()->attributes->get('node')) {
    // Revisions pass $node as the id directly, but regular pages are an object.
    $variables['node_id'] = (is_object($node)) ? $node->id() : $node;
  }

  // Add a View ID for pages.
  if ($view_id = \Drupal::routeMatch()->getParameter('view_id')) {
    $variables['view_id'] = Html::cleanCssIdentifier($view_id);
  }
}
