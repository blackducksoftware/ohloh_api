## ContributorFact

A ContributorFact contains a selection of high-level statistics about a person who commited source code to a [Project](/reference/project.md). One ContributorFact record exists for each contributor.

A ContributorFact is part of an [Analysis](/reference/analysis.md), and is derived from lower-level statistics contained within the Analysis.

A new ContributorFact is created for each Project contributor whenever a new Analysis is created for the Project.

ContributorFacts only exist after Ohloh has downloaded and analyzed the project source code.

### Properties


+ __analysis_id__
    The unique ID for the [Analysis](/reference/analysis.md) which provided the source data for this ContributorFact.
+ __contributor_id__
    The ID for the person who contributed the code measured in this ContributorFact. The `contributor_id` is not globally unique. It is derived from the author name found in the source control server log, and is unique within the scope of an individual project only.
+ __contributor_name__
    The name used by the author of this code when committing to the source control server.
+ __account_id__
    If this contribution has been claimed by an Ohloh member, the element contains the unique ID of the Ohloh [Account](/reference/account.md). Otherwise, this element is omitted.
+ __account_name__
    If this contribution has been claimed by an Ohloh member, this element contains the Account name. Otherwise, this element is omitted.
+ __primary_language_id__
    The unique ID of the [Language](/reference/language.md) most often used by this contributor, measured by the number of code lines added. If this contributor has not committed any code in a language which Ohloh can recognize, this value will be null.
+ __primary_language_nice_name__
    The `nice_name` of the Language specified by `primary_language_id`.
+ __comment_ratio__
    The fraction of new lines added by this contributor which are comments. Note that Ohloh does not track the net lines of current code attributable to an specific individual. This statistic merely sums over all new lines added, and does not consider whether the added lines were later removed by this contributor or any other.
+ __first_commit_time__
    The time of the first commit by this contributor.
+ __last_commit_time__
    The time of the last commit by this contributor.
+ __man_months__
    The total number of calendar months in which this contributor made at least one commit. Note that this is not simply the number of months between `first_commit_time` and `last_commit_time`: months in which there was no activity for this contributor are not counted.
+ __commits__
    The total number of commits made by this contributor.
+ __contributor_language_facts__
    A collection of [ContributorLanguageFacts](/reference/contributor_language_fact.md) may be included here, covering statistics in individual [Languages](/reference/language.md). This collection is only present when ContributorFacts are queried individually.

### URL
To get a single ContributorFact based on the latest Analysis for a Project:
```shell
curl http://www.ohloh.net/projects/{project_id}/contributors/{contributor_id}.xml 
```
This ContributorFact will include within it a collection of [ContributorLanguageFacts](/reference/contributor_language_fact.md) covering statistics for individual languages.

### Collection URL
To get a list of all ContributorFacts based on the lastest Analysis for a Project:
```shell
curl http://www.ohloh.net/projects/{project_id}/contributors.xml 
```
ContributorFacts returned from this call will not include ContributorLanguageFacts. Those can be obtained by retrieving ContributorFacts individually only.

The project collection request supports the standard [collection request parameters](/README.md#collection-requests), with the following details:

+ __query__
    If supplied, only ContributorFacts with a matching `contributor_name` will be returned. Ohloh account names are not matched.
+ __sort__
    ContributorFact collections support the following sort options:
    - __name__
    kudo_position
    - __commits__
        Highest commits, first
    - __commits_12_mo (default)__
        Highest commits in past twelve months, first
    - __language__
    - __latest_commit__
    - __newest__
    - __oldest__



