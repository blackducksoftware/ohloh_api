## Open Hub API Examples #
Some basic [Open Hub](https://www.openhub.net) API samples to help you get started. For information on the Open Hub API, please see the [documentation](/README.md). The Open Hub API has some restrictions, so please review the complete [Terms of Use](http://meta.ohloh.net/terms-2) before you begin.

### Examples are available in: ###
* BASH

  Uses `curl` to pull an [Account](/reference/account.md) from Open Hub and `openssl` to create MD5 hex of the email address. A simple sed hack parses the XML response into name:value pairs. The example demonstrates data retrieval using email address lookup. Pass your API key and the email address of the Account you are requsting as parameters to the script:

  `./account_sample.sh YOUR_API_KEY_HERE rluckey@blackducksoftware.com`

  The script isn’t very robust — `sed` is not the world’s best XML parser — but it does return a non-zero exit code if the record is not found or some other problem occurs.

* Ruby

  Performs the same email-based account lookup, but uses more rigorous error handling and parsing to create a structured XML document object. Using the `REXML` library, you can build a more robust interface to the Open Hub API.

  Execute the script by passing your API key and an email address as parameters:

  `ruby account_sample.rb YOUR_API_KEY_HERE rluckey@blackducksoftware.com`

* Python

  Performs a similar account lookup on Open Hub. It requires `urllib`, `hashlib` and `elementtree`.

  Execute the script by passing your API key and an email address as parameters:

  `./account_sample.py YOUR_API_KEY_HERE rluckey@blackducksoftware.com`

  Many thanks to [Thijs Triemstra](https://www.openhub.net/accounts/3953) for contributing this sample.

* Perl

  Performs a similar account lookup on Open Hub. It requires the `LWP::Simple`, `Digest::MD5`, and `XML::Simple` libraries.

  Execute the script by passing your API key and an email address as parameters:

  `./account_sample.pl YOUR_API_KEY_HERE rluckey@blackducksoftware.com`

  Many thanks to [Yanick Champoux](https://www.openhub.net/accounts/12933) for contributing this sample.

* Java

  Uses Java’s networking capabilities to pull an [Account](/reference/account.md) from Open Hub. It demonstrates how to generate an MD5 hash of an email address to use as a lookup key, then uses DOM to parse the XML response.

  Pass your API key and the email address of the Account you are requesting as parameters:

  `javac ApiExample.java`

  `java ApiExample YOUR_API_KEY_HERE rluckey@blackducksoftware.com`

* C++

  The C++ example is a bit more involved, because it must include code for networking, MD5 hashing, and XML parsing. The example includes source for some small libraries to create a self-contained program.

  The code was written for Visual Studio 2005, but it also compiles and runs on Mac OS X, and should work on Linux. Let us know if you encounter trouble on your platform.

  To build with Visual Studio 2005:
  * Open solution file `ApiExample.cpp/build/vs2005/OhlohApiExample.sln`
  * Right-click the solution and choose *Build*.

  To build on Linux or Mac OS X, *cd to ApiExample.cpp* and run the build script:

  `./compile.sh`

  You can then run the executable called `ApiExample` and pass it your API key and an email address:

  `./bin/ApiExample YOUR_API_KEY_HERE rluckey@blackducksoftware.com`

  Many thanks to [Lars ‘Levia’ Wesselius](https://www.openhub.net/accounts/739) for providing the sample code in both C++ and Java!

* PHP

  Paul Scott has created a full-featured PHP class for accessing the Open Hub API, complete with documentation. You can find it at the [PHP Classes](http://www.phpclasses.org/browse/package/4261.html) website.


Your feedback on these examples will benefit everyone, and we’re eager for input on improvements.   
We’d also appreciate help translating the samples into more languages.

Please don’t hesitate to contact us at info@ohloh.net.
