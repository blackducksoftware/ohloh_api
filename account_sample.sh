#!/bin/sh

# This is an example of using the Ohloh API from Bash.
# Detailed information can be found at the Ohloh website:
#
#     http://meta.ohloh.net/getting_started
#

# This example retrieves basic Ohloh account information
# and outputs it as simple name: value pairs.
#
# Pass your Ohloh API key as the first parameter to this script.
# Ohloh API keys are free. If you do not have one, you can obtain one
# at the Ohloh website:
#
#     http://www.ohloh.net/accounts/<your_login>/api_keys/new
#
# Pass the email address of the account as the second parameter to this script.

usage() {
	echo >&2 "Usage: $0 [api_key] [email]"
	exit 1
}

echo $1 | grep -q -E -e'.+' || usage
API_KEY=$1

echo $2 | grep -q -E -e'.+@.+\..+' || usage
EMAIL_MD5=`echo -n $2 | openssl md5 | cut -f2 -d" "`

# Pass the MD5 hash of the email address to Ohloh.
# A quick-and-dirty sed filter converts the XML response to name:value pairs
#
# We use the --fail option so that curl will return a non-zero exit status if Ohloh returns an error.
# This also means that the error message text returned from Ohloh will be suppressed from the output.
curl --fail -s "www.ohloh.net/accounts/$EMAIL_MD5.xml?v=1&api_key=$API_KEY" | sed -n 's/ *<\(.*\)>\(.*\)<\/\1>$/\1: \2/ p'

# Forward along the exit status from curl
exit $PIPESTATUS
