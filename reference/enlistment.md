## Enlistment
An Enlistment joins a [Project](/reference/project.md) to a source control [Code Location](/reference/code_location.md).

Once added to the Open Hub database, a Code Location is permanent. However, Enlistments to that Code Location may be added or removed at any time. Many Projects may share a single CodeLocation.

### Properties

+ __id__
    The unique ID of the Enlistment.
+ __project_id__
    The unique ID of the [Project](/reference/project.md).
+ __code_location__
    The [Code Location](/reference/code_location.md) record will be included in full here. 

### URL
To get a single Enlistment
```shell
curl GET https://www.openhub.net/p/{project_id}/enlistments/{enlistment_id}.xml
```

### Collection URL
To get a list of all enlistments for a particular project:
``` shell
curl https://www.openhub.net/p/{project_id}/enlistments.xml
```

The Enlistment collection method supports the standard [collection request parameters](/README.md#collection-requests) with the following details:

+ __query__
    If supplied, enlistments with a code_location URL matching the query string will be returned.
+ __sort__
    Enlistment collections support the following sort options:
    - __module_name__
    - __project__
    - __type__
    - __url (default)__


