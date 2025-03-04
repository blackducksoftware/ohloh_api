## Using OAuth 2.0 with the Open Hub API

### What is OAuth 2.0?

[OAuth 2.0](http://oauth.net/2) is the next evolution of the OAuth protocol. It is an open protocol that allows applications and websites to share sensitive data, without requiring you to release your password. Using OAuth, you can permit third-party applications to read from your Open Hub account without having to share your password.

Instead of handing out your Open Hub account password to a third-party application, you visit the Open Hub website directly and grant that application permission to access your Open Hub account. You can revoke this permission any time you change your mind.

### Using OAuth 2.0

In order to become Open Hub OAuth consumer, you'd need to get your key and secret from your [API Keys](https://www.openhub.net/accounts/me/api_keys) page.

The application [ohloh_oauth2_sinatra.rb](/examples/oauth2/ohloh_oauth2_sinatra.rb) is a simple [Sinatra](http://www.sinatrarb.com/) based example using the [oauth2 gem](https://github.com/intridea/oauth2) that fetches authenticated user's [account](/reference/account.md) xml.

### Developer Information

OAuth 2.0 is an optional, additional feature of the Open Hub API that can be used to integrate Open Hub users on your website using their authenticated identity. You can read public data from Open Hub at any time using only your application’s Open Hub API Key.
