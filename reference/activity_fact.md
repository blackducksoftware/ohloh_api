## ActivityFact
An ActivityFact is a pre-computed collection of statistics about [Project](/reference/project.md) source code. It summarizes changes to lines of code, commits, and contributors in a single month.

[SizeFacts](/reference/size_fact.md) contain the running totals of ActivityFacts.

An ActivityFact is derived from lower-level statistics contained in an [Analysis](/reference/analysis.md). ActivityFacts are updated whenever a [Project](/reference/project.md) is re-analyzed.

ActivityFacts are availabled only after Open Hub has downloaded and analyzed the project source code.

### Properties

+ __month__
    Indicates the month covered by this ActivityFact. Only the year and month fields are significant. This ActivityFact record includes all development activity that occured during this month.
+ __code_added__
    The total new lines of code added, excluding comments and blanks, during this month.
+ __code_removed__
    The total lines of code removed, excluding comments and blanks, during this month.
+ __comments_added__
    The total lines of new comments added during this month.
+ __comments_removed__
    The total lines of comments removed during this month.
+ __blanks_added__
    The total blank lines added during this month.
+ __blanks_removed__
    The total blank lines removed during this month.
+ __commits__
    The number of commits made during this month.
+ __contributors__
    The number of contributors who made at least one commit during this month. 

### Collection URL
To get all ActivityFacts for a particular [Analysis](/reference/analysis.md):
```shell
curl https://www.openhub.net/projects/{project_id}/analyses/{analysis_id}/activity_facts.xml
```
If you do not know the ID of the current best Analysis for a Project, you can use the `latest` as a shortcut for latest published analysis.
```shell
curl https://www.openhub.net/projects/{project_id}/analyses/latest/activity_facts.xml
```

The call returns one Activity for each month, starting at the first month in which any code exists, and ending at the current month. If Open Hub has not created a new Analysis for this Project in a long time, the ActivityFacts for the months following the time of the last Analysis will contain zeros.

The results cannot be paginated or filtered. Results are sorted chronologically.
