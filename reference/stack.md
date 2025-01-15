## Stack

A Stack represents a collection of Projects used by a single person. A Stack belongs to an [Account](account.md)./,

A Stack contains zero or more [StackEntries](stack_entry.md), each of which links the Stack to a single [Project](project.md).

### Properties

+ __id__
    The unique ID for the Stack.
+ __title__
    The name of the Stack.
+ __description__
    A short description about this Stack.
+ __updated_at__
    The most recent time at which any Projects were added to or removed from this Stack.
+ __project_count__
    The total number of Projects currently contained in this Stack.
+ __stack_entries__
    A collection of zero or more [StackEntries](stack_entry.md). If the Stack object was returned in response to a collection request (/projects/x/stacks.xml), you will receive only a single StackEntry corresponding to the Project in question.
+ __account_id__
    The unique ID of the [Account](account.md) which owns this Stack.
+ __account__
    For convenience, a full [Account](account.md) object may be included here. 

### Collection URL
To get a list of all Stacks for a particular Project:
```shell
GET https://www.openhub.net/p/{project_id}/stacks.xml 
```
The Stacks returned in this collection will each contain only a single [StackEntry](stack_entry.md), corresponding to the Project in question.

Each Stack in the result will also include an Account object.

The Stack collection is paginated, and supports the standard [collection request parameters](/README.md#collection-requests) with the following details:

+ __query__
    If supplied, only Stacks owned by Accounts with names matching the query string will be returned.
+ __sort__
    Stack collections support the following sort options:
    - __id__
    - __name__ (default)
    - __created_at__ Time at which the Project was added to the stack
    - __project_count__


