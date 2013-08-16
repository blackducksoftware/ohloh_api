## Using OAuth with the Ohloh API

>__NOTE: At present, Ohloh does not include any writeable API calls. This documentation page is a placeholder for future functionality.__

### What is OAuth?

[OAuth](http://oauth.net/) is an open protocol that allows applications and websites to share sensitive data, without requiring you to release your password. Using OAuth, you can permit third-party applications to read from and write to your Ohloh account without having to share your secret password.

Instead of handing out your Ohloh account password to a third-party application, you visit the Ohloh website directly and grant that application permission to access your Ohloh account. You can revoke this permission any time you change your mind.

### Developer Information

OAuth is an optional, additional feature of the Ohloh API. You can read public data from Ohloh at any time using only your application’s Ohloh API Key.

If you need to read confidential Ohloh account information, or if you would like to write new data to Ohloh, you must obtain an OAuth access token. This requires your application to be specifically granted permission by the Ohloh account holder.

When you provide an OAuth access token to the Ohloh API, Ohloh will behave as if you are logged in as the authorizing account. Any edits you make to Ohloh using that access token will appear as if they were made by the authorizing account.
