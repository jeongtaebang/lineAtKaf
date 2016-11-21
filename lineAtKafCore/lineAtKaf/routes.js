// Router configuration
// Router.configure({
//   layoutTemplate: 'main',
//   loadingTemplate: 'loading'
// });

//Loading template hook
Router.onBeforeAction('loading');
//Home template, no data required
Router.route('/', {
  name: 'main',
  template: 'main',
});