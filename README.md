# Ohloh API Documentation

## Welcome

The Ohloh API is a free, REST-based programming interface to the Ohloh open source directory. You can use the Ohloh API to create your own applications and web services based on Ohloh data.

## Getting Help

This page contains important summary information to help you get started. In-depth online documentation is available, linked by the table of contents below.

Some sample code can be found on the [Examples](examples/) page. For questions not covered in the documenation, the [Ohloh API forum](https://www.openhub.net/forums/3492) can provide additional help.

Send bug reports to info@ohloh.net.

## Table of Contents
+ [Lookup By Email](email_lookup.md)
+ [Using OAuth with the Ohloh API](examples/oauth)
+ [Examples](examples/)
+ Ohloh API Reference
    - [Account](reference/account.md)
    - [Account News](reference/news.md)
    - [ActivityFact](reference/activity_fact.md)
    - [Analysis](reference/analysis.md)
    - [ContributorFact](reference/contributor_fact.md)
    - [ContributorLanguageFact](reference/contributor_language_fact.md)
    - [Enlistment](reference/enlistment.md)
    - [Factoid](reference/factoid.md)
    - [Kudo](reference/kudo.md)
    - [KudoScore](reference/kudo_score.md)
    - [Language](reference/language.md)
    - [Message](reference/message.md)
    - [Position](reference/position.md)
    - [Project](reference/project.md)
    - [Repository](reference/repository.md)
    - [SizeFact](reference/size_fact.md)
    - [Stack](reference/stack.md)
    - [StackEntry](reference/stack_entry.md)
+ [API Use Agreement](http://meta.ohloh.net/terms-2/)
+ [Apply for an API Key](https://www.openhub.net/accounts/me/api_keys/new)
+ [API Key Status](https://www.openhub.net/accounts/me/api_keys)

## Terms of Use

The Ohloh API has some restrictions. Please review the complete [Terms of Use](http://meta.ohloh.net/terms-2/) before you begin.

We ask that you cite Ohloh in publications that use our data. Please include a link to https://www.openhub.net on your web pages.

Our terms require you to provide a link back to our site. While you’re free to use any method you’d prefer, we’ve provided this small button for your convenience: ![Ohloh Button](https://www.openhub.net/images/badges/mini.gif)

We recommend linking to our home page. The following html will link the small badge to our home page:

```html
<a href ="https://www.openhub.net"><img src="https://www.openhub.net/images/badges/mini.gif" width="80" height="15" /></a>
```

## API Key

Before you can access the Ohloh API, you must [register your application](https://www.openhub.net/accounts/me/api_keys/new) and obtain an API key. Bandwidth will initially be limited to 1,000 requests per API key per day.

An API Key should be unique to each application that accesses the Ohloh API. You can register up to five applications.

It is important not to share API keys. In order to access or modify account data, your application must be granted permission by an individual Ohloh account holder. This permission is granted on a per-key basis.

You can [register a new application](https://www.openhub.net/accounts/me/api_keys/new) or [view the status](https://www.openhub.net/accounts/me/api_keys) of your existing applications online.

If you have special requirements for additional keys, or if you are interested in building a large-scale application, please contact us at info@ohloh.net.

## OAuth Impersonation

The standard Ohloh API allows read-only access to Ohloh data.

Using OAuth, you can impersonate an Ohloh account while accessing the Ohloh API. This enables you to write to the Ohloh database, and also to access or modify private account information. You must first be granted permission to do this by an Ohloh account holder.

You can read more at [Using OAuth with the Ohloh API](examples/oauth#using-oauth-with-the-ohloh-api).

## Forming a Request

The Ohloh API returns XML-formatted data in response to HTTP GET requests.

The design concept is that for each web page on Ohloh, there may be an equivalent XML-formatted version of the page. Currently, only a small subset of the Ohloh site is available as XML, but more data will become available over time.

You must do three things to receive an XML-formatted response:

1. Append a `.xml` extension to the basic URL. For example, instead of `https://www.openhub.net/projects/1`, which returns an HTML page, you would request `https://www.openhub.net/projects/1.xml`.
2. Provide your API Key as an HTTP parameter. Your request will be forbidden without a valid `api_key`.

For example, to view the project with ID=1 as XML, using an example API key, the complete URL would be:

```
https://www.openhub.net/projects/1.xml?api_key=01234567890123456789
```

For the sake of brevity, the `api_key` parameter will be omitted from the examples in this documentation. Remember to always include it in your actual queries.

Note that the Ohloh API previously required the use of a version parameter `v`. This is no longer required, and will be ignored.

## XML Response Format

A sample response to a project request might be:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<response>
  <status>success</status>
  <result>
    <project>
      <id>1</id>
      <name>Subversion</name>
      <created_at>2006-10-10T15:51:31Z</created_at>
      <updated_at>2007-08-22T17:31:17Z</updated_at>
      <description>Subversion has rapidly become the version control standard....</description>
      <homepage_url>http://subversion.tigris.org/</homepage_url>
      <download_url>http://subversion.tigris.org/project_packages.html</download_url>
      <irc_url></irc_url>
      <stack_count>1096</stack_count>
      <analysis_id>51898</analysis_id>
      <analysis>
        <id>51898</id>
        <project_id>1</project_id>
        <updated_at>2007-07-12T12:21:11Z</updated_at>
        <logged_at>2007-07-12T12:18:54Z</logged_at>
        <min_month>2001-08-01T00:00:00Z</min_month>
        <max_month>2007-07-01T00:00:00Z</max_month>
        <twelve_month_contributor_count>55</twelve_month_contributor_count>
        <total_code_lines>319283</total_code_lines>
        <main_language_id>7</main_language_id>
        <main_language_name>C/C++</main_language_name>
      </analysis>
    </project>
  </result>
</response>
```

All XML returned from the Ohloh API will be contained within a root element called `<response>`, which will always contain a `<status>` element.

The `<status>` element will contain either `success` or `failed`.

When the `<status>` value is `success`, the HTTP response code will be `200`, and the `<result>` element contains the data you requested.

If the `status` is `failed`, then the HTTP response code will be set appropriately (usually Bad Request or Not Found), and an `<error>` element will be present containing human-readable help text. For example:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<response>
  <status>failed</status>
  <error>A valid api_key is required to access this URL.</error>
</response>
```

Details about this project response can be found in the Ohloh API Reference [project page](reference/project.md).

## Collection Requests

### Collection Request Parameters

+ __query__ - Results will be filtered by the provided string. Only items that contain the query string in their names or descriptions will be returned. Filtering is case insenstive. Only alphanumeric characters are accepted. All non-alphanumeric characters will be replaced by spaces. Filtering is not available on all API methods, and the searched text depends on the type of object requested. Check the reference documentation for specifics.
+ __sort__ - Controls the sort order of the returned results. Typical supported values are name, created_at, and updated_at. The specific sort options available depend on the type of object requested, so check to the reference documentation for specifics. _API does not support reverse sorting_.
+ __page__ - In most cases, the Ohloh API returns at most 25 items per request. Pass this parameter to request subsequent items beyond the first page. This parameter is _one-based_, with a default value of 1. If you pass a value outside the range of available pages, you will receive the first page.

For example, to get the second page of projects containing “java” or “Java” in their titles, descriptions, or tags, you would request:

```
GET https://www.openhub.net/projects.xml?query=java&page=2
```

### Collection Response XML Format

Some results will contain a collection of values. When this happens, the `<response>` element will contain some additional elements:

+ __items_returned__ - The number of items returned in this response.
+ __items_available__ - The total number of database items matching the query, including those already returned.
+ __first_item_position__ - The zero-based index of the first item returned

For example, the response to `https://www.openhub.net/projects.xml` might begin:

```xml
<response>
  <status>success</status>
  <items_returned>25</items_returned>
  <items_available>7056</items_available>
  <first_item_position>0</first_item_position>
  <result>
    <project>
      <id>9</id>
      <name>Mozilla Firefox</name>
      ....
```

- - -
Copyright 2013 Black Duck Software, Inc. Unless otherwise marked, this work is licensed under a [Creative Commons Attribution 3.0 Unported License](http://creativecommons.org/licenses/by/3.0/).
