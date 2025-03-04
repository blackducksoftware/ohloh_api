require 'oauth2'
require 'sinatra'

enable :sessions
CALLBACK_URL = 'http://localhost:9292/callback'

# Assumes that you have set OpenHub_KEY and OpenHub_SECRET environment
# variables to values from your API keys page.
before do
  @client = OAuth2::Client.new(ENV['OpenHub_KEY'], ENV['OpenHub_SECRET'],
                               site: 'https://www.openhub.net',
                               token_method: :post)
end

def access_token
  OAuth2::AccessToken.new(@client, session[:access_token], refresh_token: session[:refresh_token])
end

get '/login' do
  redirect @client.auth_code.authorize_url(redirect_uri: CALLBACK_URL)
end

get '/callback' do
  new_token = @client.auth_code.get_token(params[:code], redirect_uri: CALLBACK_URL)
  session[:access_token] = new_token.token
  session[:refresh_token] = new_token.refresh_token

  access_token.get('accounts/me.xml').body
end
