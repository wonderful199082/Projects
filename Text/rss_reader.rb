require 'rss'
require 'open-uri'

url = 'http://www.ruby-lang.org/en/feeds/news.rss'

open(url) do |rss|
  feed = RSS::Parser.parse(rss)
  p "---------------------------------------------"

  p "Title: #{feed.channel.title}"
  feed.items.each do |item|
    p "Title: #{item.title}"
    p "Author: #{item.author}"
    p "Date: #{item.pubDate}"
    p "Link: #{item.link}"
    p "Description: #{item.description}"
    p "---------------------------------------------"
  end
end
