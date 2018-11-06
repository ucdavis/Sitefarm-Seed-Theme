# SASS Folder Structure

```
|-- sass
|   |-- 1_pattern_lab
|   |-- 2_pattern_lab_compatibility
|   |-- 3_component
|   |-- _hacks.scss
|   |-- _variables.scss
|   |-- style.scss
```

## 1. Pattern Lab
This folder contains all the sass imported from Pattern Lab. Do not edit these files!

## 2. Pattern Lab Compatibility
This folder should contain any overrides or extends that might need to happen to make Pattern Lab sass work with different markup. Hopefully there won't be much in this folder.

## 3. Components
**The majority of all styles will go here.** This folder is for any components not already styled by Pattern Lab. These could be site specific components. Each component should be completely isolated from any other component. There should not be any sharing of styles among components. As well, cascading order should not be required for any component.

In general, stay away from assuming any sort of HTML structure. Obviously this isn't always possible, but it's a good rule of thumb to follow.

Don't Use:
```scss
.block div ul li {
  margin: 0;
}
```
Instead Use:
```scss
.block__item {
  margin: 0;
}
```

## Files
**_hacks.scss**: this partial should be used sparingly when something needs to be done very quickly without time to put a style in its proper place. This file overrides everything so it should be cleaned up regularly so that styles go in their proper place.

**_variables.scss** This partial is for overriding default variables already set in **/sass/1_pattern_lab/_variables.scss**.

**style.scss**: This is the main file which will be rendered into **/dist/style.css**. It contains all of the SASS libraries and partials necessary to build CSS.

Don't put any styles directly into **style.scss**!


# CSS formatting guidelines
We use the [Drual CSS guidlines](https://www.drupal.org/node/1887862) and [Drupal CSS Architecture](https://www.drupal.org/coding-standards/css/architecture)

One item to note is that this guideline is for CSS and does not take SASS/SCSS syntax into account. Because of this we do have one specific change.

Place a space in between each class. This allows better readability since each SASS partial will only have a few classes per file.

Example
```scss
.block {
  padding: 1em;
}

.block--success {
  color: green;
}
```

> ID tags should NEVER be used! Only use classes.

## SASS formatting guidelines
The order of mixins and placeholders:

1. extend %placeholder
2. include mixin()
3. regular styles
4. include breakpoint() //media query

```scss
.block {
  // Placeholder is extended
  @extend %default-block;
  
  // Mixin is added
  @include font-size(16px);
  
  // Normal styles are used
  padding: 0;
  text-align: center;
  
  // Use a Media Query to augment for responsive design
  @include breakpoint(500px) {
    padding: 1em;
  }
}
```

## BEM naming format using SASS
```scss
.block {
  // Add any .block styles here
 
  &__element {
    // Add any elements styles here
  }
  
  &--modifier {
    // Add modifiers here
  }
}
```

This will render into CSS
```scss
.block {
  // .block styles here
}
 
.block__element {
  // .block__element styles here
}
  
.block--modifier {
  // .block--modifier styles here
}
```

## Validation

[Sass Lint](https://github.com/sasstools/sass-lint) is being used to validate Sass/Scss files via the [gulp-sass-lint](https://www.npmjs.com/package/gulp-sass-lint).

The gulp task `gulp validate:css` can be used to easily validate all Sass.



# Useful Articles and Links
Drupal CSS formating guides

* [Drual CSS guidlines](https://www.drupal.org/node/1887862)
* [Drupal CSS Architecture](https://www.drupal.org/coding-standards/css/architecture) - We are using a different folder structure, but if follows the same ideas.

BEM naming convention

* [http://csswizardry.com/2013/01/mindbemding-getting-your-head-round-bem-syntax/](http://csswizardry.com/2013/01/mindbemding-getting-your-head-round-bem-syntax/)
* [https://css-tricks.com/bem-101/](https://css-tricks.com/bem-101/)

Sass Info

* [http://sass-lang.com/guide](http://sass-lang.com/guide)
* [http://leveluptuts.com/tutorials/sass-tutorials](http://leveluptuts.com/tutorials/sass-tutorials)

Sass Libraries, Helpers, and Shortcut tools

* [Singularity](https://github.com/at-import/Singularity/wiki) - This is a very flexible grid system.
* [Breakpoint](http://breakpoint-sass.com/) & [Breakpoint Wiki](https://github.com/at-import/breakpoint/wiki) - Use Breakpoint for media queries in responsive design.
* [Toolkit](https://github.com/at-import/toolkit) - This is a library of cool mixins and helpers.

Sass Playground (use this to try things out)

* [SassMeister](http://sassmeister.com/)
* [CodePen](http://codepen.io/pen/)

