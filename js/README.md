# Javascript

Each file in the **/js** directory will be concatenated into a single **/dist/scripts.js** file.

Please use multiple files rather than stuffing all javascript into a single file.

## Pattern Lab Files

Javascript imported from Pattern Lab will be in the **/js/1_pattern_lab/** directory. Do not edit files here or they will be changed on the next sync.

## Validation

[ESLint](http://eslint.org/) is being used to validate javascript.

The gulp task `gulp validate:js` can be used to easily validate all javascript.

By default, any javascript files in the `vendor` directory will not be validated since they will come from third parties.

## Vendor directory

The `vendor` directory can be used to add third party libraries that have not already been added via NPM. It is preferable to use NPM if at all possible.

## Useful Articles and Links

* [Drual JS Coding Standards](https://www.drupal.org/node/172169)
* [jQuery Coding Standards](https://www.drupal.org/node/1720586)