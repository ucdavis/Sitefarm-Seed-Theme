<?php
/**
 * @file
 * Theme and preprocess functions for fields
 */

use Drupal\taxonomy\Entity\Term;

/**
 * Implements hook_theme_suggestions_field_alter().
 */
function sfseed_theme_suggestions_field_alter(array &$suggestions, array $variables) {
  $element = $variables['element'];

  // Add a theme suggestion for the view mode display of a specific node type
  // field--node--field-name--full.html.twig
  $suggestions[] = 'field__' . $element['#entity_type'] . '__' . $element['#field_name'] . '__' . $element['#view_mode'];
  // field--node--field-name--bundle--full.html.twig
  $suggestions[] = 'field__' . $element['#entity_type'] . '__' . $element['#field_name'] . '__' . $element['#bundle'] . '__' . $element['#view_mode'];

  // Add a theme suggestion for term reference label field on an entity full display.
  if (_sfseed_is_full_taxonomy_term_label($element)) {
    // field--node--taxonomy-term-label--full.html.twig
    $suggestions[] = 'field__' . $element['#entity_type'] . '__taxonomy_term_label__full';
  }
}

/**
 * Implements hook_preprocess_field().
 */
function sfseed_preprocess_field(&$variables) {
  $element = $variables['element'];

  // Add a tags class for term reference label field on an entity full display.
  if (_sfseed_is_full_taxonomy_term_label($element)) {
    // Loop through each item since these are multi-item fields
    foreach ($variables['items'] as $key => $item) {
      // Add the tag class to the link
      $variables['items'][$key]['content']['#options']['attributes']['class'] = 'tags__tag';
    }
  }
}

/**
 * Check if field is a term reference label on an full entity display.
 *
 * @param array $element
 *
 * @return bool
 */
function _sfseed_is_full_taxonomy_term_label(array $element) {
  if ($element['#view_mode'] == 'full'
    && isset($element[0]['#options']['entity_type'])
    && $element[0]['#options']['entity_type'] == 'taxonomy_term'
    && $element['#formatter'] == 'entity_reference_label'
  ) {
    return TRUE;
  }

  return FALSE;
}
