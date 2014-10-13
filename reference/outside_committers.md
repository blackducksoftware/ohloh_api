##Outside Committers
People that are not part of an organization but commit to its projects


### Properties

+ __contributor__
	+ __name__ Name of the user account
	+ __kudos__ Kudos obtained by the user account
	+ __level__ Level of the user account
	+ __affiliated_with__ Organization to which the user is affiliated to
	+ __contributions_to_portfolio_projects__
		+ __projects__ Names of the portfolio projects to which the contributor commits to
		+ __twelve_mo_commits__ Commits made by the contributor to portfolio projects in the last 12 months
+ __detailed_page_url__ This page's relative url


### URL

```shell
https://www.openhub.net/orgs/{org_name}/outside_committers.xml?api_key={api_key}&page={number}
```

#### Example

```ruby
https://www.openhub.net/orgs/mozilla/outside_committers.xml?api_key=some_example_api_key&page=2
```
