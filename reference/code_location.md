## Code Location
A Code Location represents an individual source control repository.

Once added to the Open Hub database, a Code Location is permanent and unique.

A Code Location is added to a [Project](project.md) by creating an [Enlistment](enlistment.md), which links the Project to the Code Location. In this way, many Projects can share the same Code Location.

Deleting an Enlistment from a Project does not delete a Code Location, nor will it interrupt Open Hub download activity against that Code Location. The Code Location and all of its source code and metrics remain in the Open Hub database; only the Enlistment link is modified.

### Properties

+ __id__
    The unique ID of the Code Location.
+ __type__
    The source control type. Supported values are:
    - _SvnRepository_
        Subversion
    - _CvsRepository_
        CVS
    - _GitRepository_
        Git
    - _HgRepository_
        Mercurial
    - _BzrRepository_
        Bazaar

+ __url__
    The public URL for the source control server.
+ __module_name__
    For CVS repositories only, this is the module name. For Git repositories only, this is the branch name. For all other repository types, this element is omitted.
+ __username__
    An optional username, if one is required to access the source control server.
+ __password__
    An optional password, if one is required to access the source control server.
+ __logged_at__
    The last time the Open Hub servers successfully queried the source control server for changes.
+ __commits__
    The number of commits which the Open Hub servers have successfully downloaded from the source control server.
+ __ohloh_job_status__
    If the most recent attempt by Open Hub to query the source control server for changes failed or was interrupted, this value will be `failed`. In all other cases it is `success`. 

### URL
Code Locations cannot be directly queried at this time. Access them by using the [Enlistments](enlistment.md) methods.
