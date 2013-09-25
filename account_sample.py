#!/usr/bin/python

"""
The MIT License (MIT)

Copyright (c) 2013 Thijs Triemstra 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
"""

"""
This is an example of using the Ohloh API from Python.

Detailed information can be found on GitHub:

     https://github.com/blackducksw/ohloh_api

This example uses the ElementTree library for XML parsing
(included in Python 2.5 and newer):

     http://effbot.org/zone/element-index.htm

This example retrieves basic Ohloh account information
and outputs it as simple name: value pairs.

Pass your Ohloh API key as the first parameter to this script.
Ohloh API keys are free. If you do not have one, you can obtain one
at the Ohloh website:

     http://www.ohloh.net/accounts/<your_login>/api_keys/new

Pass the email address of the account as the second parameter to this script.
"""

import sys, urllib, hashlib
# import ElementTree based on the python version
try:
  import elementtree.ElementTree as ET
except ImportError:
  import xml.etree.ElementTree as ET

# We pass the MD5 hash of the email address
email = hashlib.md5()
email.update(sys.argv[2])

# Connect to the Ohloh website and retrieve the account data.
params = urllib.urlencode({'api_key': sys.argv[1], 'v': 1})
url = "http://www.ohloh.net/accounts/%s.xml?%s" % (email.hexdigest(), params)
f = urllib.urlopen(url)

# Parse the response into a structured XML object
tree = ET.parse(f)

# Did Ohloh return an error?
elem = tree.getroot()
error = elem.find("error")
if error != None:
    print 'Ohloh returned:', ET.tostring(error),
    sys.exit()

# Output all the immediate child properties of an Account
for node in elem.find("result/account"):
    if node.tag == "kudo_score":
        print "%s:" % node.tag
        for score in elem.find("result/account/kudo_score"):
            print "\t%s:\t%s" % (score.tag, score.text)
    else:
        print "%s:\t%s" % (node.tag, node.text)
