## Analysis

An Analysis is a pre-computed collection of statistics about [Project](/reference/project.md) source code and contributors.

An individual Analysis never changes. When a Project’s source code is modified, a completely new Analysis is generated for that Project. Eventually, old analyses are deleted from the database. Therefore, you should always obtain the ID of the best current analysis from the project record before requesting an analysis.

The Analysis object described here contains only a few top-level metrics. Detailed, historical metrics are contained within child objects of an Analysis, which will be exposed through the API at a later date.

### Properties

+ __id__
    The unique ID for the Analysis.
+ __url__
    A URL, returning details about this Analysis in XML format.    
+ __project_id__
    The unique ID of the Project measured by this Analysis.
+ __updated_at__
    The time at which this Analysis record was last modified.
+ __logged_at__
    The time at which Ohloh queried the source control system for the source code measured by this Analysis. All commits which occured at or before this time are included. Note that the Analysis might also include some activity after this time if the project includes many [Repositories](/reference/repository.md), because not all Repositories are updated at the same time. The logged_at time is the most pessimistic time among all the Repositories included in the Project.
+ __min_month__
    Ohloh groups most historical statistics ([ActivityFacts](/reference/activity_fact.md) and [SizeFacts](/reference/size_fact.md)) into monthly totals. min_month indicates the first month for which Ohloh has monthly historical statistics available for this project. This is typically the date of the first project commit, truncated to the beginning of its calendar month. Only the year and month fields are significant.
+ __max_month__
    The last month for which monthly historical statistics are available for this project. Depending on when this analysis was prepared, max_month usually refers to the current month, but it may be slightly older. Only the year and month fields are significant. Ohloh’s monthly statistics for max_month are usually smaller than other months because the complete month has not yet elapsed, and it reflects ongoing development work.
+ __twelve_month_contributor_count__
    The number of contributors who made at least one commit to the project source code in the twelve months leading up to and including `max_month`.
+ __total_contributor_count__
    The total number of contributors who made at least one commit to the project source code leading up to and including `max_month`.
+ __twelve_month_commit_count__
    The number of commits to the project source code in the twelve months leading up to and including `max_month`.
+ __total_commit_count__
    The total number of commits to the project source code leading up to and including `max_month`.
+ __total_code_lines__
    The most recent total count of all source code lines. Blank lines and comment lines are excluded.
+ __main_language_id__
    The unique ID of the most common programming language used in this project. XML and HTML are ignored when making this determination.
+ __main_language_name__
    The name of the most common programming language used in this project. XML and HTML are ignored when making this determination.
+ __factoids__
    The factoids for the current Analysis will be included under this node.

```xml
<factoids>
    <factoid type="FactoidTeamSizeVeryLarge">Very large, active development team</factoid>
    <factoid type="FactoidAgeVeryOld">Mature, well-established codebase</factoid>
    <factoid type="FactoidActivityIncreasing">Increasing year-over-year development activity</factoid>
    <factoid type="FactoidCommentsLow">Few source code comments</factoid>
</factoids>
```

+ __language__
    The language breakdown chart for the current Analysis will be included under this node. The node will have the following children:
    - _@graph_url_
    This is the url to the PNG image that depicts the language breakdown for the current Analysis. The colors referenced in each languages @color attribute will be used in this image.
    - _language_
    Not every language will have a entry. Ohloh will will combine languages that do not make up a significant percentage into a aggregate entry “N Other”. This entry can be identified by either its @color, always “000000″ or @id, always “”.
    Each language will contain the following data
        - @color The color code that Ohloh uses to represent this language on the website. This color is also used in the language breakdown graph image.
        - @percentage The percentage of lines of code that the current language represents in the current Analysis
        - @id The Ohloh language id.

```xml
<languages graph_url="https://openhub.net/p/firefox/analyses/9239902/languages.png">
  <language color="F35F1F" percentage="40" id="44">C++</language>
  <language color="FF8F00" percentage="19" id="42">C</language>
  <language color="A4007E" percentage="14" id="6">JavaScript</language>
  <language color="000000" percentage="27" id="">28 Other</language>
</languages>
```
    

### URL
To get a particular Analysis for a single Project:
```shell
curl https://www.openhub.net/projects/{project_id}/analyses/{analysis_id}.xml
```

A shortcut to the current best Analysis for a single Project can be made by substituting `latest` for the analysis ID:
```shell
curl https://www.openhub.net/projects/{project_id}/analyses/latest.xml 
```
