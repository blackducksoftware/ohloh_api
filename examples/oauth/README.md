## Using OAuth with the Open Hub API

### What is OAuth?

[OAuth](http://oauth.net/) is an open protocol that allows applications and websites to share sensitive data, without requiring you to release your password. Using OAuth, you can permit third-party applications to read from your Open Hub account without having to share your password.

Instead of handing out your Open Hub account password to a third-party application, you visit the Open Hub website directly and grant that application permission to access your Open Hub account. You can revoke this permission any time you change your mind.

### Using OAuth 
In order to become Open Hub OAuth consumer, you'd need to get your key and secret from your [API Keys](https://www.openhub.net/accounts/me/api_keys) page. Open Hub supports OAuth 1.0a.
[ohloh_oauth_sinatra.rb](/examples/oauth/ohloh_oauth_sinatra.rb) is a simple [Sinatra](http://www.sinatrarb.com/) based example using [oauth gem](https://github.com/oauth-xx/oauth-ruby) that fetches authenticated user's [account](/reference/account.md) xml.

Although not affiliated with Open Hub, [OmniAuth](https://github.com/intridea/omniauth) appears to have Ohloh strategy available [here](https://github.com/RodrigoAyala/omniauth-ohloh). This code is not supported, tested or verified by Open Hub.

### Developer Information
OAuth is an optional, additional feature of the Open Hub API that can be used to integrate Open Hub users on your website using their authenticated identity. You can read public data from Open Hub at any time using only your application’s Open Hub API Key.
