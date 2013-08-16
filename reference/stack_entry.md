## StackEntry

A StackEntry joins a [Stack](stack.md) to a [Project](project.md).

### Properties

+ __id__
    The unique ID for the StackEntry.
+ __created_at__
    The time at which this Project was added to this Stack.
+ __stack_id__
    The unique ID of the Stack which contains this StackEntry.
+ __project_id__
    The unique ID of the Project.
+ __project__
    For convenience, a full Project object may be included here. If the Stack object was returned in response to an Account Stack request (/accounts/x/stacks/default.xml), the Project objects will be present. 

### URL
StackEntry object cannot be queried directly. They are included in a response to queries or [stacks](stack.md).
