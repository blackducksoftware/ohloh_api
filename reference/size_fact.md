## SizeFact
A SizeFact is a pre-computed collection of statistics about [Project](project.md) source code. It provides monthly running totals of lines of code, commits, and developer effort.

SizeFacts contain the running totals of [ActivityFacts](activity_fact.md).

A SizeFact is derived from lower-level statistics contained in an [Analysis](analysis.md). SizeFacts are updated whenever a [Project](project.md) is re-analyzed.

SizeFacts are availabled only after Ohloh has downloaded and analyzed the project source code.

### Properties

+ __month__
    Indicates the month covered by this SizeFact. Only the year and month fields are significant. This SizeFact record includes all development activity that occured during this month.
+ __code__
    The total net lines of code, excluding comments and blanks, as of the end of this month.
+ __comments__
    The total net lines of comments as of the end of this month.
+ __blanks__
    The total net blank lines as of the end of this month.
+ __comment_ratio__
    The fraction of net lines which are comments as of the end of this month.
+ __commits__
    The cumulative total number commits to the project source control, including this month.
+ __man_months__
    The cumulative total months of effort expended by all contributors on this project, including this month. For instance, if 1 contributor has worked for 3 months and 2 developers have each worked for 5 months, man_months will be 13. This is the running total of the [ActivityFact](activity_fact.md) `contributors` property. 

### Collection URL
To get all SizeFacts for a particular [Analysis](analysis.md):
```shell
curl https://www.openhub.net/projects/{project_id}/analyses/{analysis_id}/size_facts.xml
```
If you do not know the ID of the current best Analysis for a Project, you can use the following shortcut:
```shell
curl https://www.openhub.net/projects/{project_id}/analyses/latest/size_facts.xml 
```

The call returns one SizeFact for each month, starting at the first month in which any code exists, and ending at the month in which Ohloh last created a new Analysis for this Project. Typically, the collection ends at the current month, but if the Project has not been re-analyzed in a while, the collection may end sooner.

The results cannot be paginated or filtered. Results are sorted chronologically.
