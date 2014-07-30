#!/usr/bin/env ruby
require 'sinatra'
require 'oauth'

enable :sessions
set :session_secret, 'enter your secret here'

CALLBACK_URL = 'http://localhost:4567/info'

# Assumes that you have set OHLOH_KEY and OHLOH_SECRET environment
# variables to values from your API keys page.
before do
  @consumer = OAuth::Consumer.new(ENV['OHLOH_KEY'], ENV['OHLOH_SECRET'],
                                  {:site => 'https://www.openhub.net',
                                  :token_url => "/oauth/access_token"})
end

get '/login' do
  request_token = @consumer.get_request_token(:oauth_callback => CALLBACK_URL)
  session[:r_token] = request_token.token
  session[:r_token_secret] = request_token.secret
  redirect request_token.authorize_url(:oauth_callback => CALLBACK_URL)
end

get '/info' do
  r_token = session[:r_token]
  r_token_secret =  session[:r_token_secret]
  if r_token.nil? || r_token_secret.nil?
    return 'You are not authenticated. Go to /login'
  end
  request_token = OAuth::RequestToken.new(@consumer, r_token, r_token_secret)
  access_token = request_token.get_access_token
  content_type 'text/xml'
  access_token.get('/accounts/me.xml').body
end
