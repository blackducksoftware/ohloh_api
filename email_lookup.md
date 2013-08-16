## Lookup By Email

The Ohloh API allows you to retrieve an [Account](reference/account.md) using the MD5 hash of the account’s email address.

You can pass the MD5 hash of an email address in any URL that normally expects an Account ID.

This is useful if you know someone’s email address, but do not know the Ohloh account ID. This might be the case if you are hosting a web site with registered users who have supplied their email addresses. With the Ohloh API, you can easily find Ohloh statistics about your registered users.

For example, here’s how to find the account data for `robin@ohloh.net`:
+ Generate the MD5 hash for `robin@ohloh.net`. From a bash command prompt you can do this simply:
```shell
$ md5 -q -s robin@ohloh.net 63f26c4a00677ea1e8b14d2a56efb104
```

+ Pass this hash in place of the account ID in the normal http request:
```shell
$ curl http://www.ohloh.net/accounts/63f26c4a00677ea1e8b14d2a56efb104
```

Ohloh does not publish email addresses. You must already know the email address of the account you are looking for. Because the search is done using the MD5 hash of the email address, the email address comparison is case sensitive and must match exactly.
