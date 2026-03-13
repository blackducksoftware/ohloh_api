# Project Managers API Reference

## Endpoint

```
GET /p/{project_name}/managers.xml?api_key={api_key}
```

- **Description:** Returns a list of managers for the specified project.
- **Required Parameters:**
  - `project_name`: The name of the project.
  - `api_key`: Your API key.

## Sample Request

```
GET /p/sample_project/managers.xml?api_key=xyz
```

## Sample Response

```xml
<response>
  <status>success</status>
  <items_returned>2</items_returned>
  <result>
    <manager>
      <account_id>1</account_id>
      <account_name>Test User1</account_name>
      <url>http://localhost:3000/accounts/test_user1.xml</url>
      <html_url>http://localhost:3000/accounts/test_user1</html_url>
      <commits>0</commits>
      <message/>
      <created_at>2026-03-05T00:00:00Z</created_at>
      <updated_at>2026-03-05T00:00:00Z</updated_at>
    </manager>
    <manager>
      <account_id>2</account_id>
      <account_name>Test User2</account_name>
      <url>http://localhost:3000/accounts/test_user2.xml</url>
      <html_url>http://localhost:3000/accounts/test_user2</html_url>
      <commits>0</commits>
      <message>hi</message>
      <created_at>2026-03-05T00:00:00Z</created_at>
      <updated_at>2026-03-05T00:00:00Z</updated_at>
      <pending>true</pending>
    </manager>
  </result>
</response>
```

## Response Fields

- `<status>`: Status of the API call (e.g., `success`).
- `<items_returned>`: Number of manager records returned.
- `<result>`: Container for the list of `<manager>` elements.
- `<manager>`: Contains the following fields:
  - `<account_id>`: Unique identifier for the manager's account.
  - `<account_name>`: Name of the manager's account.
  - `<url>`: API URL for the manager's account.
  - `<html_url>`: Web URL for the manager's account.
  - `<commits>`: Number of commits by the manager.
  - `<message>`: Optional message from the manager.
  - `<created_at>`: Timestamp when the manager was added.
  - `<updated_at>`: Timestamp when the manager was last updated.
  - `<pending>`: (Optional) Indicates if the manager's status is pending (`true` or omitted).

## Notes
- The `<pending>` field is only present for managers whose status is pending.
- All timestamps are in ISO 8601 format.
