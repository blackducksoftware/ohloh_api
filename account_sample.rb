#!/usr/bin/env ruby
require 'net/http'
require 'rexml/document'
require 'digest/md5'

# This is an example of using the Ohloh API from Ruby.
# Detailed information can be found at the Ohloh website:
#
#     http://meta.ohloh.net/getting_started
#
# This example uses the REXML library for XML parsing:
#
#     http://www.germane-software.com/software/rexml/
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

unless ARGV[0] =~ /[\w]+/ and ARGV[1] =~ /.+@.+\..+/
	STDERR.puts "Usage: #{__FILE__} [api_key] [email]"
	exit 1
end

api_key = ARGV[0]
email = ARGV[1]

#
# Connect to the Ohloh website and retrieve the account data.
#

# We pass the MD5 hash of the email address
email_md5 = Digest::MD5.hexdigest(email).to_s
response = Net::HTTP.get_response("www.ohloh.net", "/accounts/#{email_md5}.xml?v=1&api_key=#{api_key}", 80)

# HTTP OK?
if response.code != '200'
  STDERR.puts "#{response.code} - #{response.message}"
  exit 1
end

# Parse the response into a structured XML object
xml = REXML::Document.new(response.body)

# Did Ohloh return an error?
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
