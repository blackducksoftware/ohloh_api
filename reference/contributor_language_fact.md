## ContributorLanguageFact

A ContributorLanguageFact contains a selection of [Language](/reference/language.md)-specific statistics about a single person who commited source code to a [Project](/reference/project.md).

One ContributorFact record exists for each Language used by a contributor.

The ContributorLanguageFact is very similar to a [ContributorFact](/reference/contributor_fact.md). The difference is that a ContributorLanguageFact contains statistics for a particular Language only, while a ContributorFact contains summary statistics across all languages used by the contributor.

A ContributorLanguageFact is part of an Analysis, and is derived from lower-level statistics contained within the [Analysis](/reference/analysis.md). New ContributorLanguageFacts are created for each Project contributor whenever a new Analysis is created for the Project.

ContributorLanguageFacts only exist after Open Hub has downloaded and analyzed the project source code.

### Properties

+ __analysis_id__
    The unique ID for the [Analysis](/reference/analysis.md) which provided the source data for this ContributorFact.
+ __contributor_id__
    The ID for the person who contributed the code measured in this ContributorLanguageFact. The `contributor_id` is not globally unique. It is derived from the author name found in the source control server log, and is unique within the scope of an individual project only.
+ __contributor_name__
    The name used by the author of this code when committing to the source control server.
+ __language_id__
    The unique ID of the [Language](/reference/language.md) measured.
+ __language_nice_name__
    The `nice_name` of the Language measured.
+ __comment_ratio__
    The fraction of new lines added by this contributor in this language which are comments. Note that Open Hub does not track the net lines of current code attributable to an specific individual. This statistic merely sums over all new lines added, and does not consider whether the added lines were later removed by this contributor or any other.
+ __man_months__
    The total number of calendar months in which this contributor made at least one commit using this Language. Months in which there was no activity in this Language for this contributor are not counted.
+ __commits__
    The total number of commits made in this Language by this contributor.

### Collection URL
To get a list of all ContributorLanguageFacts for a particular contributor, based on the lastest Analysis for a Project:
```shell
curl https://www.openhub.net/p/{project_id}/contributors/{contributor_id}.xml
```
This is the same URL used to obtain a [ContributorFact](/reference/contributor_fact.md). The ContributorFact returned by this call will include within it a collection of ContributorLanguageFacts.
