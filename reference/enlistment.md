## Enlistment
An Enlistment joins a [Project](/reference/project.md) to a source control [Repository](/reference/repository.md).

Once added to the Ohloh database, a Repository is permanent. However, Enlistments to that Repository may be added or removed at any time. Many Projects may share a single Repository.

### Properties

+ __id__
    The unique ID of the Enlistment.
+ __project_id__
    The unique ID of the [Project](/reference/project.md).
+ __repository_id__
    The unique ID of the [Repository](/reference/repository.md).
+ __repository__
    The [Repository](/reference/repository.md) record will be included in full here. 

### URL
To get a single Enlistment
```shell
curl GET http://www.ohloh.net/projects/{project_id}/enlistments/{enlistment_id}.xml
```

### Collection URL
To get a list of all enlistments for a particular project:
``` shell
curl http://www.ohloh.net/projects/{project_id}/enlistments.xml
```

The Enlistment collection method supports the standard [collection request parameters](/README.md#collection-requests) with the following details:

+ __query__
    If supplied, enlistments with a repository URL matching the query string will be returned.
+ __sort__
    Enlistment collections support the following sort options:
    - __module_name__
    - __project__
    - __type__
    - __url (default)__


