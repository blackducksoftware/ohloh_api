##Organization
An organization is an Entity which contains a collection of projects called portfolio projects under it.


### Properties
+ __name__ Organization Name
+ __url__  XML Api URL for the current organization.
+ __html_url__ The URL for the current organization page on OpenHub.
+ __created_at__ The time at which the organization was initially added to OpenHub.
+ __updated_at__ The time of most recent modification to the organization record.
+ __description__ The optional description of the current organization, currently limited to 800 characters.
+ __homepage_url__ An optional URL for the home page of the organization, e.g Apache Software Foundation (www.apache.org)
+ __url_name__ A short, unique, handle for the current organization. e.g for url_name as 'apache' the equivalent web link is www.openhub.net/orgs/apache 
+ __small_logo_url__ An url to the organization’s 32×32 pixels logo image.
+ __medium_logo_url__ An url to the organization’s 64×64 pixels logo image.
+ __projects_count__ The number of portfolio projects under the organization.
+ __affiliated_committers__ The count of number of committers affiliated to the organization.


### Collection URL
```shell
https://www.openhub.net/orgs.xml?api_key={api_key}&page={number}&sort={projects}&query={keyword}
```

The organization collection request supports the standard [collection request parameters](/README.md#collection-requests), with the following details:

+ __query__ If supplied, only organizations matching the query string will be returned.

  - An organization match occurs if its name, description, or any of its tags contain the query string.

+ __sort__ Organization collection supports the following sort options :

  - __name__ Sort by organization name.
  - __projects_count__ Sort by number of portfolio projects in the organization.
  - __created_at__ Sort by the organization created date/time.
  - __updated_at__ Sort by organization record's last updated date/time.

+ __page__ Results page for the organization collection xml api.

  - The first page of results are displayed when the API is queried without passing a 'page' parameter in the url.
  - Successive pages of results can be queried using ```page=1``` upto ```page=n```

#### Example

```ruby
https://www.openhub.net/orgs.xml?api_key=some_example_api_key&page=2&sort=projects_count&query=java
```
