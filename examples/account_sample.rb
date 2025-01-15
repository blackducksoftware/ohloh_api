#!/usr/bin/env ruby
require 'net/https'
require 'rexml/document'
require 'digest/md5'

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

# This is an example of using the Open Hub API from Ruby.
# Detailed information can be found at the Open Hub website:
#
#     https://github.com/blackducksw/ohloh_api
#
# This example uses the REXML library for XML parsing:
#
#     http://www.germane-software.com/software/rexml/
#

# This example retrieves basic Open Hub account information
# and outputs it as simple name: value pairs.
#
# Pass your Open Hub API key as the first parameter to this script.
# Open Hub API keys are free. If you do not have one, you can obtain one
# at the Open Hub website:
#
#     https://www.openhub.net/accounts/<your_login>/api_keys/new
#
# Pass the email address of the account as the second parameter to this script.

unless ARGV[0] =~ /[\w]+/ and ARGV[1] =~ /.+@.+\..+/
	STDERR.puts "Usage: #{__FILE__} [api_key] [email]"
	exit 1
end

api_key = ARGV[0]
email = ARGV[1]

#
# Connect to the Open Hub website and retrieve the account data.
#

# We pass the MD5 hash of the email address
email_md5 = Digest::MD5.hexdigest(email).to_s

uri = URI("https://www.openhub.net/accounts/#{email_md5}.xml?v=1&api_key=#{api_key}")
http = Net::HTTP.new(uri.host, uri.port)
http.use_ssl = true
response = http.get(uri.request_uri)

# HTTP OK?
if response.code != '200'
  STDERR.puts "#{response.code} - #{response.message}"
  exit 1
end

# Parse the response into a structured XML object
xml = REXML::Document.new(response.body)

# Did Open Hub return an error?
error = xml.root.get_elements('/response/error').first
if error
  STDERR.puts "#{error.text}"
  exit 1
end

# Output all the immediate child properties of an Account
xml.root.get_elements('/response/result/account').first.each_element do |element|
  puts "#{element.name}:\t#{element.text}" unless element.has_elements?
end

# The kudo_rank element may not be present.
# Check for it, and default to 1 if it is missing.
xml_kudo_rank = xml.root.get_elements('/response/result/account/kudo_score/kudo_rank').first
kudo_rank = xml_kudo_rank ? xml_kudo_rank.text.to_i : 1
puts "kudo_rank:\t#{kudo_rank}"
