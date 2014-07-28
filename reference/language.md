## Language

A Language record contains the name and various statistics related to a programming language.

Language statistics are updated daily.

### Properties

+ __id__
    The unique ID of the language.
+ __name__
    A short, unique name for the language. Primarily for internal Open Hub use.
+ __nice_name__
    A human-friendly name for the language.
+ __category__
    Either code, markup, or build, which indicates that the language is either a “standard” programming language, a document markup language such as XML, or a build script such as a makefile.
+ __code__
    The total net lines of code, excluding comments and blank lines, written in this language across all projects on Open Hub.
+ __comments__
    The total net comment lines written in this language across all projects on Open Hub.
+ __blanks__
    The total net blank lines in this language across all projects on Open Hub.
+ __comment_ratio__
    A precomputed floating-point value for the percent of lines in this language that are comments, across all projects on Open Hub.
+ __projects__
    The total number of Projects on Open Hub which currently include at least one line in this language.
+ __contributors__
    The total number of contributors on Open Hub who have written at least one line of code in this language that still exists today.
+ __commits__
    The total number of commits on Open Hub which include at least one line in this language. 

### URL
To get a single Language:
```shell
curl https://www.openhub.net/languages/{language_id}.xml 
```

### Collection URL
To get a paginated list of all Languages:
```shell
curl https://www.openhub.net/languages.xml 
```
The Language collection request supports the standard [collection request parameters](/README.md#collection-requests), with the following sort options:

+ __total__
    Results are sort by the total source lines, including comments and blanks, from highest to lowest.
+ __code__
    Results are sorted by code lines only from highest to lowest.
+ __projects__
    Results are sorted by the number of projects, from highest to lowest.
+ __comment_ratio__
    Results are sorted by comment_ratio from highest to lowest.
    Results are sorted by the number of Projects, from highest to lowest.
+ __contributors__
    Results are sorted by the number of contributors, from highest to lowest
+ __commits__
    Results are sorted by the number of commits, from highest to lowest.
+ __name (default)__
    Results are sorted alphabetically by nice_name. 
