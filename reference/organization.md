### Organization
An organization is an entity which contains a collection of projects and accounts.


### Properties
+ __name__ Organization Name
+ __url__  XML API URL for the organization.
+ __html_url__ The URL for the organization page on OpenHub.
+ __created_at__ The time at which the organization was initially added to OpenHub.
+ __updated_at__ The time of most recent modification to the organization record.
+ __description__ The optional description of the organization, currently limited to 800 characters.
+ __homepage_url__ An optional URL for the home page of the organization, e.g Apache Software Foundation (www.apache.org)
+ __url_name__ A short, unique, handle for the organization. e.g for url_name as 'apache' the equivalent web link is www.openhub.net/orgs/apache
+ __small_logo_url__ An url to the organization’s 32×32 pixels logo image.
+ __medium_logo_url__ An url to the organization’s 64×64 pixels logo image.
+ __type__ The type of the organization(Non-profit/Commercial/Government/Educational).
+ __inforgraphic_details__ Details presented in the organization page inforgraphic image
	+ __outside_committers__
	+ __outside_committers_commits__
	+ __projects_having_outside_commits__
	+ __portfolio_projects__
	+ __affiliators__
	+ __affiliators_committing_to_portfolio_projects__
	+ __affiliator_commits_to_portfolio_projects__
	+ __affiliators_commiting_projects__
	+ __outside_projects__
	+ __outside_projects_commits__
	+ __affiliators_committing_to_outside_projects__
+ __portfolio_projects__ First 10 Portfolio Projects for the requested organization
	+ __project__ Each project in the list with the following details
		+ __name__
		+ __activity__
		+ __primary_language__
		+ __i_use_this__
		+ __community_rating__
		+ __twelve_mo_activity_and_year_on_year_change__
			+ __commits__
			+ __change_in_commits__
			+ __percentage_change_in_commits__
			+ __contributors__
			+ __change_in_contributors__
			+ __percentage_change_in_committers__
	+ __detailed_page_url__ Url for paginated listing of all portfolio projects
+ __outside_projects__ First 10 Outside Projects for the requested organization.
	+ __project__ Each project in the list with the following details
		+ __name__
		+ __activity__
		+ __claimed_by__
		+ __i_use_this__
		+ __community_rating__
		+ __affiliates_contributing__
		+ __commits_by_current_affiliates__
	+ __detailed_page_url__ Url for paginated listing of all outside projects
+ __outside_committers__ First 10 Outside Committers for the requested organization
	+ __contributor__ Each account in the list with the following details
		+ __name__
		+ __kudos__
		+ __level__
		+ __affiliated_with__
		+ __contributions_to_portfolio_projects__
			+ __projects__
			+ __twelve_mo_commits__
	+ __detailed_page_url__ Url for paginated listing of all outside committers
+ __affiliated_committers__ First 10 Affiliated Committers for the requested organization
	+ __affiliator__ Each account in the list with the following details
		+ __name__
		+ __kudos__
		+ __level__
		+ __most_commits__
			+ __project__
			+ __commits__
		+ __most_recent_commit__
			+ __project__
			+ __date__
	+ __detailed_page_url__ Url for paginated listing of all affiliated committers


### URL
```shell
https://www.openhub.net/orgs/{org_url_name}.xml?api_key={api_key}&view={view_option}
```

view_option will return the requested organization related data-table(maximum of 10 records)

  - The view option can be one of the following four ````portfolio_projects````, ````outside_projects````, ````affiliated_committers```` or ````outside_committers````

#### Examples

```ruby
https://www.openhub.net/orgs/mozilla.xml?api_key=some_example_api_key&view=portfolio_projects
```

```ruby
https://www.openhub.net/orgs/mozilla.xml?api_key=some_example_api_key&view=outside_projects
```

```ruby
https://www.openhub.net/orgs/mozilla.xml?api_key=some_example_api_key&view=affiliated_committers
```

```ruby
https://www.openhub.net/orgs/mozilla.xml?api_key=some_example_api_key&view=outside_committers
```
