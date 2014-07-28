#!/usr/bin/perl

=pod

=head1 NAME

account_sample.pl - Simple example of using the Open Hub API from Perl

=head1 SYNOPSIS

account_sample.pl api_key email

=head1 DESCRIPTION

This is a small example of how to use the Open Hub API from Perl,
mimicking the Ruby example - account_sample.rb

Detailed information about the Open Hub API can be found at
https://github.com/blackducksw/ohloh_api

The script takes an API key and the email address of a developer
registered on Open Hub as parameters, and prints out all the
information of that account.

=head1 EXAMPLE

    ./account_sample.pl YOUR_API_KEY_HERE robin@ohloh.net

=head1 DEPENDENCIES

This script uses
L<LWP::Simple> (to query the Open Hub website),
L<Digest::MD5> (to MD5s the email address as requested by the API)
and
L<XML::Simple> (to parse the server's answer).

=head1 VERSION

This documentation refers to account_sample version 0.1

=head1 AUTHOR

Yanick Champoux (yanick@cpan.org)

=head1 LICENCE AND COPYRIGHT

Copyright (c) 2007 Yanick Champoux (yanick@cpan.org). All rights reserved.

This module is free software; you can redistribute it and/or
modify it under the same terms as Perl itself. See perldoc perlartistic.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

=cut

use strict;
use warnings;

use LWP::Simple;
use Digest::MD5 qw/ md5_hex /;
use XML::Simple;

my $VERSION     = '0.01';
my $API_VERSION = 1;

die_usage() unless @ARGV == 2;

my ( $api_key, $email ) = @ARGV;

my $email_md5 = md5_hex($email);

### let's build the request url
# first the base url
my $url = 'https://www.openhub.net/';
# then the email "page" we want
$url .= "accounts/$email_md5.xml";
# and finally the API version and the api key
$url .= '?' . join '&' => "v=$API_VERSION", "api_key=$api_key";

# request the url from the server
my $response = get $url or die "Open Hub server didn't return anything\n";

# parse the XML response
my $xml = eval { XMLin($response) } or die "Server didn't return valid XML\n";

# was the request a success?
die "request didn't succeed: $xml->{error}\n"
  unless $xml->{status} eq 'success';

# make an alias to the info we want
my %account = %{ $xml->{result}{account} };

# now we print the info for the account

for my $attr (
    qw/ id name created_at updated_at homepage_url
    avatar_url posts_count location country_code
    latitude longitude /
  ) {

    # only print the attribute if it exist
    printf "%-20s: %s\n", $attr, $account{$attr}
      if defined $account{$attr} and not ref $account{$attr};
}

# print the kudo information
printf "%-20s: %s\n", 'kudo rank', $account{kudo_score}{kudo_rank}
  if $account{kudo_score};

exit;

### utility functions ######################################

sub die_usage {
    die "usage: $0 api_key email\n";
}

__END__
