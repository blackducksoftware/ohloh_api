## Lookup By Email

The Open Hub API allows you to retrieve an [Account](reference/account.md) using the MD5 hash of the account’s email address.

You can pass the MD5 hash of an email address in any URL that normally expects an Account ID.

This is useful if you know someone’s email address, but do not know the Open Hub account ID. This might be the case if you are hosting a web site with registered users who have supplied their email addresses. With the Open Hub API, you can easily find Open Hub statistics about your registered users.

For example, here’s how to find the account data for `info@openhub.net`:
+ Generate the MD5 hash for `info@openhub.net`. From a irb shell you can do this simply:
```shell
require 'digest'
Digest::MD5.hexdigest('info@openhub.net').to_s
f1c4c8746d8e42872f6db32977ad5d61
```

+ Pass this hash in place of the account ID in the normal http request:
```shell
$ curl https://www.openhub.net/accounts/f1c4c8746d8e42872f6db32977ad5d61.xml?api_key=<YOUR API KEY>
```

Open Hub does not publish email addresses. You must already know the email address of the account you are looking for. Because the search is done using the MD5 hash of the email address, the email address comparison is case sensitive and must match exactly.
