## Position
A position represents a contribution or series of contributions that an account holder has made to a project within Open Hub. It corresponds to a committer ID for a source code repository for a particular project.

### Properties

+ __title__
    An optional field that contains the title for this position. Example: “Lead Developer”. This field is filled in by the account holder.
+ __organization__
    An optional field that contains the organization name for this position. This field will be filled in if the account holder has designated that this position’s contributions were made on behalf of an organization. Example: “IBM Corporation”.
+ __html_url__
    The url to the contributor page on Open Hub.
+ __created_at__
    The time at which this Position was originally created on Open Hub.
+ __updated_at__
    The time at which this Position record was last modified.
+ __started_at__
    Optional field that contains the time at which this position was started. This field may be filled in by the account holder if this position is not backed by commits (e.g. the user contributed documentation to the projects wiki or authored and submitted a patch committed by a project maintainer).
+ __ended_at__
    Option field that contains the time at which this position was ended. This field may be filled in by the account holder if the position is not backed by commits.
+ __sparkline_url__
    The url to the sparkline that represents the account holder’s commit activity for the current position.
+ __commits__
    The total number of commits made by the account holder at this position.
+ __project__
    The Project that this position is attached to. This node will contain all of the properties for the specific [project](project.md).

### URL
To get positions for an account:
```shell
curl https://www.openhub.net/accounts/{account_id}/positions.xml
```
