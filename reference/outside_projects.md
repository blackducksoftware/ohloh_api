##Outside Projects
Projects that are not part of an organization but are commtted to by its members


### Properties

+ __project__
	+ __name__ Name of the project
	+ __activity__ Project's activity level like low, high etc.. 
	+ __primary_language__ The primary language in which the projects repos have code in
	+ __i_use_this__ Number of people who mark that they use this
	+ __community_rating__ Average rating of the project as rated by openhub users
	+ __affiliates_contributing__ No of people that belong to the organization that commit to outside projects
	+ __commits_by_current_affiliates__ No of commits made by the organization people to outside projects
+ __detailed_page_url__ This page's relative url


### URL

```shell
https://www.openhub.net/orgs/{org_name}/outside_projects.xml?api_key={api_key}&page={number}
```

#### Example

```ruby
https://www.openhub.net/orgs/mozilla/outside_projects.xml?api_key=some_example_api_key&page=2
```
