## Kudo
A Kudo is a simple gesture of thanks, praise, or endorsement from an Ohloh [account](/reference/account.md) to another person. An account may send Kudos to as many people as desired.

Kudos can be sent directly to another Ohloh account, or they may be sent to a contributor on a Project who does not have an Ohloh account. This flexibility makes Kudo records slightly complex.

When a Kudo is sent directly to an Ohloh Account, the recipient is identified by `receiver_account_id`.

When a Kudo is sent to a contributor on a Project who does not have an Account, the Kudo record contains both `contributor_id` and `project_id`, which together uniquely identify the recipient.

Ocassionally, an Ohloh Account holder may claim to be a Project contributor who has some existing Kudos. When this happens, the existing Kudos become linked to the Account, and the Kudos will now have all three properties: `receiver_account_id`, `contributor_id`, and `project_id`.

### Properties
+ __created_at__
    The time at which this Kudo was sent.
+ __sender_account_id__
    The unique ID of the [Account](account.md) sending this Kudo.
+ __sender_account_name__
    The name of the [Account](account.md) sending this Kudo. 
+ __receiver_account_id__
    If this Kudo can be linked to an Account, this is the unique ID of the Account receiving this Kudo. Otherwise, this element is omitted.
+ __receiver_account_name__
    If this kudo can be linked to an Account, this is the name of the Account receiving this Kudo. Otherwise, this element is omitted.
+ __project_id__
    If this Kudo was sent to a Project contributor instead of an Account, this is the unique ID of the [Project](project.md). Otherwise, this element is omitted.
+ __project_name__
    If this Kudo was sent to a Project contributor instead of an Account, this is the Project name. Otherwise, this element is omitted.
+ __contributor_id__
    If this Kudo was sent to a Project contributor instead of an Account, this is the unique ID of the contributor. Otherwise, this element is omitted.
+ __contributor_name__
    If this Kudo was sent to a Project contributor instead of an account, this is the name which appears in the source control logs. Otherwise, this element is omitted. 

### Collection URL
To get a list of all Kudos received by an Account:
```shell
curl http://www.ohloh.net/accounts/{account_id}/kudos.xml
```
To get a list of all Kudos sent by an Account:
```shell
curl http://www.ohloh.net/accounts/{account_id}/kudos/sent.xml 
```
These methods do not support any sorting, filtering, or paging options. You will always receive the complete list of all Kudos, sorted from new to old.

If you do not know the Account ID, you can also query for Kudos using the MD5 hash of the email address. Read more about email-based queries [here](/email_lookup.md).

