## Account

An Account represents an Open Hub member. Some Account data is private, and cannot be accessed through the Open Hub API.

### Properties
+ __id__
The unique ID for the Account.

+ __name__
    The public name for this Account.

+ __about__
    A short description about this account.

+ __login__
    The Login handle for this account.

+ __created_at__
    The time at which this Account was originally created on Open Hub.

+ __updated_at__
    The time at which this Account record was last modified.

+ __homepage_url__
    An optional URL to a member’s home page, such as a blog.

+ __twitter_account__
    An optional Twitter handle for this account.

+ __url__
    A URL, returning details about this account in XML format.

+ __html_url__
    A URL to the profile's Home page for this account.

+ __avatar_url__
    A URL to the profile image displayed on Open Hub pages. Currently, this is an URL to the Gravatar free image hosting service, which will resolves to a default image if the account holder is not a Gravatar member. Images are 80×80 by default.

+ __email_sha1__
    The SHA1 hex digest of the account email address.

+ __posts_count__
    The number of posts made to the Open Hub forums by this account.

+ __location__
    An optional text description of this account holder’s claimed location. This text has been validated by either the Google or Yahoo geocoder web service, but the precision is variable.

+ __country_code__
    A string representing the account holder’s country. This field is derived from location using either the Google or Yahoo geocoder web service. If you use this data, read the important note below.

+ __latitude__ and __longitude__
    Floating-point values representing the account’s latitude and longitude, suitable for use with the Google Maps API. They are available only when the account has specified a valid location.

+ __kudo_score__
If this account has a KudoScore, it will appear here. New accounts may not have a KudoScore. The Open Hub web site displays these accounts with a default KudoRank of 1.

+ __languages__
    Only available when requesting an accounts details, this node will not be returned as part of a search result list. This node contains the total language experience for this account grouped by language.Eachnode contains the following children:
    - __@color__
    This is the Open Hub color code for this language. If you will be displaying this data in your application it is highly recommended you use the colors returned here as these are the same colors Open Hub uses to display specific languages.
    - __name__
    The Open Hub code name for this language, e.g. C# will be csharp and C++ will be cpp.
    - __experience_months__
    The total number of months that Open Hub has computed as experience in this language for the current Account.
    - __total_commits__
    The total number of commits made by the current Account that contained code in the current Language.
    - __total_lines_changed__
    The total number of lines changed by the current Account that contained code in the current Language.
    - __comment_ratio__
    The ratio of comment lines to code lines in commits made by the current Account for the current Language.

```xml
<languages>
    <language color="A4007E">
        <name>javascript</name>
        <experience_months>24</experience_months>
        <total_commits>116</total_commits>
        <total_lines_changed>563,931</total_lines_changed>
        <comment_ratio>23.4%</comment_ratio>
    </language>
    <language color="FF1A00">
        <name>css</name>
        <experience_months>20</experience_months>
        <total_commits>83</total_commits>
        <total_lines_changed>74,705</total_lines_changed>
        <comment_ratio>4.3%</comment_ratio>
    </language>
    <language color="47A400">
        <name>html</name>
        <experience_months>19</experience_months>
        <total_commits>62</total_commits>
        <total_lines_changed>27,875</total_lines_changed>
        <comment_ratio>20.5%</comment_ratio>
    </language>
</languages>
```

+ __badges__
Lists the badges awarded to the account holder.  All accounts have a Kudo Score of at least 1, so the Kudo Rank badge will always appear here.  Badges are listed with these attributes:
    - __name__
    The name of the badge
    - __level__
    The numeric value of the level for the badge.  Some badges are "binary", such as the Project Manager or the Organization Manager badges.  These are awarded when the account holder manages a project or organization, respectively.  For these types of badges, the level is '0'
    - __description__
    This is the description of the badge that is used for tool tips on Open Hub
    - __image_url__
    This is the URL of a 64x64 pixel icon of the badge image
    - __pips_url__
    This is the URL of a 15x64 pixel icon of the pips based on the level.  This will be empty when the level is 0.

### Making API Calls

#### Individual account
To get a single Account:
```shell
curl https://www.openhub.net/accounts/{account_id}.xml
```

You can also retrieve an Account using the MD5 hash of the email address, if you know it:
```shell
curl https://www.openhub.net/accounts/{email_md5_hash}.xml
```

Read more about email-based queries [here](/email_lookup.md).

#### Collection of accounts
To get a list of all Accounts:
```shell
curl https://www.openhub.net/accounts.xml
```

The account collection method supports the standard [collection request parameters](/README.md#collection-requests) with the following details:

+ __query__
    If supplied, only accounts matching the query string will be returned. Only the name field is searched.
+ __sort__
    Account collections support the following sort options:
    - __created_at (default)__
        Recently created, first
    - __name__
    - __updated_at__
        Recently updated, first

### A Note about Country Codes
Open Hub preferentially uses the [Google Maps API](http://www.google.com/apis/maps/documentation/index.html) geocoder to resolve location names entered by users. `country_code` values obtained from the Google Maps API use two-letter abbreviations.

However, Google’s coverage is not complete, and not all countries can be resolved. For countries that cannot be resolved by the Google geocoder, Open Hub falls back to the Yahoo geocoder. These countries include the United Kingdom and China. `country_code` values obtained from Yahoo are full country names, not two-letter abbreviations.

For this reason, there are two data formats intermingled in country_code. Open Hub does not use this data internally, so the data has not been cleaned and unified.
