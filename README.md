# Getting Started

This theme is not meant to be used as-is. It is just a starting place for building your own theme for [SiteFarm Seed](https://github.com/ucdavis/sitefarm_seed)

It is also assumed that you have created a Pattern Lab based on [SiteFarm Seed Pattern Lab](https://github.com/ucdavis/sitefarm-seed-patternlab) and will be importing styles from there.

## Prerequesites 

You'll need [node.js](http://nodejs.org).


## Install and setup
    
After cloning and changing into that directory, run this to install dependencies:

    $ npm install

You may have to run that again for updates; so it may be wise to save this: `$ npm install`. **If you have any problems; this is the first thing to run.**

Finally, to do an initial build of the site and start watching for changes run `gulp`. You should use the gulp version specific to your project by prefixing all your gulp commands with `npx`.

```
$ npx gulp
```

## Sync Pattern Lab styles by importing into site

1. Add the following code into a `gulp-config.local.yml` file and set the `src` to the location of the external Pattern Lab:

```yaml
themeSync:
  enabled: true
  src: /location/of/patternlab
```

2. Run the themesync gulp task to import styles from Pattern Lab:

```
$ npx gulp themesync
```

## Assets (CSS & JS)

Sass and Javascript will be automatically compiled into a `/dist/` directory.

To add either CSS or JS third party libraries, use one of these methods:


### NPM Dependencies

NPM is a Node package manager for the web. It is useful for adding third party libraries for both development and site inclusion.

Install any [NPM](https://www.npmjs.com/) component with the `--save` flag. You can search for anything that NPM can install and run:

    $ npm install {thing} --save

Use `--save` when a package needs to be added as a dependency to the browser.


### NPM CSS Dependencies

The CSS in NPM Dependencies *will* automatically be compiled to the `vendor.css` files.

If you don't want a file to be used then you can exclude it in the `gulp-config.yml` file.

```yaml
css:
  vendor:
    - '!node_modules/bootstrap/**/*.css'
```


#### Node Include Paths

If NPM (node.js) is used to add dependencies and libraries for Sass then it is helpful to add its `nodeFiles:includePaths` to the `gulp-config.yml` file. This allows shorter import names to work in Sass files.

With an `includePaths` added to the `gulp-config.yml` file a simple `@import "breakpoint";` can be used instead of `@import "../node_modules/breakpoint-sass/stylesheets/breakpoint";"`.

This also helps with any dependencies that a NPM package might rely on.


### NPM Javascript Dependencies

The JS in NPM Dependencies *will not* automatically be compiled and added to production javascript.

[Webpack](https://webpack.js.org/) is used to compile all Javascript. Adding a Javascript package into your code is as easy as using a `require()` or `import`.

```js
// ES5
var jQuery = require('jquery');
```

```js
// ES6
import jQuery from 'jquery';
```

If for some reason a file needs a package loaded to the `window` object in order to function, it is best to use `require()` so that Webpack doesn't move it before other code.

```js
import jQuery from 'jquery';
window.jQuery = jQuery;
require('superfish');
```

#### Externally loaded Javascript Dependencies

If a Javascript package will be loaded externally (perhaps by a CDN) then you can specify this in config so that Webpack will not add the package into the compiled Javascript file.

```yaml
js:
  externals:
    jquery: 'jQuery'
```


### Compiling of ES6 to ES5 Javascript

By default, all Javascript code will be compiled to ES5 with [Babel](https://babeljs.io/) so that it is safe for Browsers. This means that you can write modern Javascript and take advantage of modern practices.


## About Gulp

Gulp is a task/build runner for development. It allows you to do a lot of stuff within your development workflow. You can compile sass files, uglify and compress js files and much more.

- [Gulp Website](http://gulpjs.com/)
- Article from CSS Tricks: [Gulp for Beginners](https://css-tricks.com/gulp-for-beginners/)

### Local Gulp Configuration

Gulp configuration can be customized to a local environment by creating a `gulp-config.local.yml` file. Any custom config specific to a local setup can be placed in here and it will not be committed to Git.

Project configuration is found in `gulp-config.yml`. You can copy out config you want to change into your custom file. This file overrides default config in [https://github.com/ucdavis/ucd-theme-tasks/blob/master/config.default.js](https://github.com/ucdavis/ucd-theme-tasks/blob/master/config.default.js)

### Gulp Tasks

There are 4 main gulp tasks you should be aware of. Just add `npx gulp` before each task like `$ npx gulp help`.

1. **Help** - Displays a list of all the available tasks with a brief discription of each
2. **Default** - Generate the entire site and start watching for changes to live reload in the browser
3. **Compile** - Generate the entire site with all assets such as css and js
4. **Validate** - Validate CSS and JS by linting

`$ npx gulp` is the one most often used and is the same as `$ npx gulp default`

### Using Gulp with PHPStorm

PHPStorm has [Gulp Tool Window](https://www.jetbrains.com/phpstorm/help/gulp-tool-window.html) for easy use of Gulp tasks.
Right-click on the `gulpfile.js` file and choose `Show Gulp Tasks` to open the window.

Double click `default` to start gulp and begin watching files for changes.

You can double click `help` to see descriptions of available tasks

### BrowserSync

BrowserSync is being used by Gulp to allow live reloading so that changes will be injected automatically into the site without having to reload.

## Windows Users

If you are on Windows you may run into a few issues.

It is recommended you use [Git for Windows](http://git-for-windows.github.io/).

If you get an alert saying that Google Chrome can't run, try passing in a different browser string into your `gulp-config.local.yml` file.

```yaml
browserSync:
  browser: ['chrome']
```
