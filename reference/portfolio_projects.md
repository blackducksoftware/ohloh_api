##Portfolio Projects
Projects that belong to a specific organization


### Properties

+ __project__
	+ __name__ Name of the project
	+ __activity__ Project's activity level like low, high etc.. 
	+ __primary_language__ The primary language in which the projects repos have code in
	+ __i_use_this__ Number of people who mark that they use this
	+ __community_rating__ Average rating of the project as rated by openhub users
	+ __twelve_mo_activity_and_year_on_year_change__ Last 12 months activity compared with previous 12 months activity
		+ __commits__ No of commits in the last 12 months
		+ __change_in_commits__ Diff between no of commits in this 12 months and the previous 12 months before that
		+ __percentage_change_in_commits__ % measure of change in commits
		+ __contributors__ No of contributors in the last 12 months
		+ __change_in_contributors__ Diff between no of committers in this 12 months and the previous 12 months before that
		+ __percentage_change_in_committers__ % measure of change in contributors
+ __detailed_page_url__ This page's relative url


### URL

```shell
https://www.openhub.net/orgs/{org_name}/projects.xml?api_key={api_key}&page={number}
```

#### Example

```ruby
https://www.openhub.net/orgs/mozilla/projects.xml?api_key=some_example_api_key&page=2
```