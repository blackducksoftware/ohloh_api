## Factoid

A Factoid is a short, high-level bullet point delivering a simple observation about a [Project](/reference/project.md). Factoids are derived from an Analysis, and new Factoids are created for a Project every time a new [Analysis](/reference/analysis.md) is created.

On the Ohloh web site, Factoids are rendered in the Nutshell section of the project summary page. Factoids also are available in several of the sharing widgets available for embedding on websites.

A Project has factoids only if Ohloh has downloaded and analyzed its source code.

### Properties
+ __id__
The unique ID for the Factoid. Factoid IDs change every time the Project is reanalyzed, so it’s unwise to store these IDs for long periods.

+ __analysis_id__
The unique ID of the [analysis](/reference/analysis.md) used to calculate this factoid.

+ __type__
The Factoid type. The possible types are defined below.

+ __description__
A short, human-readable description. This is the bullet point text which appears on the Ohloh project page.

+ __severity__
An integer from -3 to +3 which rates the relative severity of the factoid. Negative numbers generally indicate bad news, positive numbers generally indicate good news. Ohloh uses these numbers to select icons to display beside the factoids. All factoids of the same type have the save severity.

### URL
To get a single Factoid:
```shell
curl http://www.ohloh.net/projects/{project_id}/factoids/{factoid_id}.xml
```

### Collection URL
To get a list of all current Factoids for a particular Project:
```shell
curl http://www.ohloh.net/projects/{project_id}/factoids.xml 
```
The collection request does not support any filtering, sorting or paging. You will always receive the entire collection of factoids, ordered by descending priority.

### Factoid Types

+ __FactoidActivityDecreasing__
During the last twelve calendar months, there were at least 25% fewer commits to this project than in the prior twelve calendar months.

+ __FactoidActivityStable__
During the last twelve calendar months, the commit count was within +/- 25% of the count for the prior twelve calendar months.

+ __FactoidActivityIncreasing__
During the last twelve calendar months, there were at least 25% more commits to this project than in the prior twelve calendar months.

+ __FactoidAgeYoung__
The source control repository is less than 1 year old.

+ __FactoidAgeEstablished__
The source control repository is 1 to 3 years old.

+ __FactoidAgeOld__
The source control repository is 3 to 5 years old.

+ __FactoidAgeVeryOld__
The source control repository is 5 years old or older.

+ __FactoidCommentsVeryLow__
Compared to all other projects written in the same language, the comment ratio for this project is in the bottom 10%.

+ __FactoidCommentsLow__
Compared to all other projects written in the same language, the comment ratio for this project is in the bottom 33% but not in the bottom 10%.

+ __FactoidCommentsAverage__
Compared to all other projects written in the same language, the comment ratio for this project is in the middle 33%.

+ __FactoidCommentsHigh__
Compared to all other projects written in the same language, the comment ratio for this project is in the top 33% but not in the top 10%.

+ __FactoidCommentsVeryHigh__
Compared to all other projects written in the same language, the comment ratio for this project is in the top 10%.

+ __FactoidTeamSizeZero__
No commits were made to this project in the last 12 months.

+ __FactoidTeamSizeOne__
Only a single contributor made commits to this project in the last 12 months.

+ __FactoidTeamSizeSmall__
Two or three contributors made commits to this project in the last 12 months.

+ __FactoidTeamSizeAverage__
4 to 6 contributors made commits to this project in the last 12 months.

+ __FactoidTeamSizeLarge__
7 to 27 contributors made commits to this project in the last 12 months.

+ __FactoidTeamSizeVeryLarge__
28 or more contributors made commits to this project in the last 12 months.

__Note about "mostly written in"__  - "... is mostly written in" bullet point listed in the Nutshell section of project summaries and in widgets displaying factoid information is not technically a factoid. This element is actually the `main_language_name` property on an [analysis](/reference/analysis.md).
