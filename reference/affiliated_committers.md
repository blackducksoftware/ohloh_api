##Affiliated Committers
People that are part of an organization and commit to its projects


### Properties

+ __affiliator__
	+ __name__ Name of the user account
	+ __kudos__ Kudos obtained by the user account
	+ __level__ Level of the user account
	+ __most_commits__
		+ __project__ Name of the project to which the committer has made most commits to
		+ __commits__ No of commits made to the most committed project
	+ __most_recent_commit__
		+ __project__ Name of the project last to committed by the affiliator 
		+ __date__ Date of the last commit
+ __detailed_page_url__ This page's relative url


### URL

```shell
https://www.openhub.net/orgs/{org_name}/affiliated_committers.xml?api_key={api_key}&page={number}
```

#### Example

```ruby
https://www.openhub.net/orgs/mozilla/affiliated_committers.xml?api_key=some_example_api_key&page=2
```
