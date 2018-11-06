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
