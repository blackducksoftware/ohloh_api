## Project
A Project represents a collection of source code, documentation, and web sites treated together as a unit. It’s what most people might call an ‘application’ or ‘library’.

### Properties
+ __id__
    The unique ID for the Project.
+ __name__
    The project name. Currently limited to 40 characters, and must be unique on Ohloh.
+ __created_at__
    The time at which this Project was initially added to the Ohloh database.
+ __updated_at__
    The time of the most recent modification of this Project record.
+ __description__
    An optional description. Currently limited to 800 characters.
+ __homepage_url__
    An optional URL to the project home page.
+ __download_url__
    An optional URL to a website hosting project downloads.
+ __url_name__
    A short, unique name for this project. This name is used in Ohloh URLs.
+ __medium_logo_url__
    An url to the project’s 64×64 pixels logo image.
+ __small_logo_url__
    An url to the project’s 32×32 pixels logo image.
+ __user_count__
    The number of users currently using this project.
+ __average_rating__
    A floating point value from 1.0 to 5.0, representing the average value of all user ratings. 1.0 is the worst possible rating and 5.0 is the highest possible rating. Will be null if no users have rated this project.
+ __rating_count__
    The number of users who have rated this project.
+ __review_count__
    The number of users who have reviewed this project.
+ __analysis_id__
    The unique ID of the current best [Analysis](analysis.md) for this project. If the project has never been analyzed, this element will be empty.
+ __analysis__
    For convenience, the current best Analysis for the project is included in this element. This object is present only when you have requested a single project — if the project was returned as part of a collection, the analysis object will not be present.
+ __url__
    The xml api url for the current Project.
+ __html_url__
    The url to the current Projects details page on Ohloh.
+ __factoids__
    The factoids for the current analysis of the project will be included under this node.

```xml
<factoids>
  <factoid type="FactoidTeamSizeVeryLarge">Very large, active development team</factoid>
  <factoid type="FactoidAgeVeryOld">Mature, well-established codebase</factoid>
  <factoid type="FactoidActivityIncreasing">Increasing year-over-year development activity</factoid>
  <factoid type="FactoidCommentsLow">Few source code comments</factoid>
</factoids>
```

+ __tags__
    The tags for the current project will be included under this node.

```xml
<tags>
  <tag>ruby</tag>
  <tag>gem</tag>
  <tag>web</tag>
</tags>
```

+ __language__
    The language breakdown chart for the current Analysis will be included under this node. The node will have the following children:
    - __@graph_url__
    This is the url to the PNG image that depicts the language breakdown for the current Analysis. The colors referenced in each languages @color attribute will be used in this image.
    - __language__
    Not every language will have a entry. Ohloh will will combine languages that do not make up a significant percentage into a aggregate entry “N Other”. This entry can be identified by either its @color, always “000000″ or @id, always “”.
    Each language will contain the following data
        - @color The color code that Ohloh uses to represent this language on the website. This color is also used in the language breakdown graph image.
        - @percentage The percentage of lines of code that the current language represents in the current Analysis
        - @id The Ohloh language id.

```xml
<languages graph_url="http://ohloh.net/p/firefox/analyses/9239902/languages.png">
  <language color="F35F1F" percentage="40" id="44">C++</language>
  <language color="FF8F00" percentage="19" id="42">C</language>
  <language color="A4007E" percentage="14" id="6">JavaScript</language>
  <language color="000000" percentage="27" id="">28 Other</language>
</languages>
```

+ __licenses__
    The Licenses for the current project will be included under this node.
    - __name__
    Full Name of the License
    - __nice_name__
    A human-friendly name of the License


```xml
  <licenses>
    <license>
      <name>mit</name>
      <nice_name>MIT License</nice_name>
    </license>
  </licenses>
```

+ __links__
    The links associated with the current project. Homepage and Download links are not included here.
    - __category__
    Link category on Ohloh
    - __title__
    - __url__


```xml
  <links>
    <link>
      <category>Documentation</category>
      <url>http://www.luckytips.co.nr/firefox</url>
      <title>Tips n Tricks</title>
    </link>
  </links>
```

### URL
To get a single Project, including its current best Analysis:
```shell
curl http://www.ohloh.net/projects/{project_id}.xml 
```

### Collection URL
To get a list of all Projects, not including their Analyses:
```shell
curl http://www.ohloh.net/projects.xml 
```
The Project collection request supports the standard [collection request parameters](/README.md#collection-requests), with the following details:

+ __query__
    If supplied, only Projects matching the query string will be returned. A Project matches if its name, description, or any of its tags contain the query string.
+ __sort__
    Project collections support the following sort options:

    - __new__
    - __rating__
    - __active_committers__
        Highest active committers in past 12 months, first
    - __activity_level__
    - __commit_count__
        Highest commits, first
    - __committer_count__
        Highest contributors, first
    - __stack_count__
    - __stack_count_reverse (default)__
    - __id__
    - __name__
    - __name_length__
        Length of project name. Shorter name, first
    - __updated_at__



