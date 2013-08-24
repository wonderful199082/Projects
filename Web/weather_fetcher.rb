require 'rubygems'
require 'yahoo-weather'

@client = YahooWeather::Client.new
response = @client.lookup_by_woeid(2151330)

#straight text output
print <<edoc
#{response.title}
#{response.condition.temp} degrees
#{response.condition.text}
edoc

# sample html output
print <<edoc
<div>
  <img src="#{response.image.url}"><br/>
  #{response.condition.temp} degrees
  #{response.units.temperature}<br/>
  #{response.condition.text}<br>
  Forecast:<br/>
  #{response.forecasts[0].day} -
  #{response.forecasts[0].text}.  High:
  #{response.forecasts[0].high} Low:
  #{response.forecasts[0].low}<br/>
  #{response.forecasts[1].day} -
  #{response.forecasts[1].text}.  High:
  #{response.forecasts[1].high} Low:
  #{response.forecasts[1].low}<br/>
  More information <a
  href="#{response.page_url}">here</a>.
</div>
edoc
