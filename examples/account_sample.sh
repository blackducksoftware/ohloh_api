#!/bin/sh

# The MIT License (MIT)
# 
# Copyright (c) 2013 Black Duck Software, Inc.
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

# This is an example of using the Ohloh API from Bash.
# Detailed information can be found on GitHub:
#
#     https://github.com/blackducksw/ohloh_api
#

# This example retrieves basic Ohloh account information
# and outputs it as simple name: value pairs.
#
# Pass your Ohloh API key as the first parameter to this script.
# Ohloh API keys are free. If you do not have one, you can obtain one
# at the Ohloh website:
#
#     https://www.openhub.net/accounts/<your_login>/api_keys/new
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
curl --fail -s "https://www.openhub.net/accounts/$EMAIL_MD5.xml?v=1&api_key=$API_KEY" | sed -n 's/ *<\(.*\)>\(.*\)<\/\1>$/\1: \2/ p'

# Forward along the exit status from curl
exit $PIPESTATUS
