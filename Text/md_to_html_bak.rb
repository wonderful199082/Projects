#require 'maruku'

#md = 'hello world'

#doc = Maruku.new(md)
#p doc.to_html
#p doc.to_html_document

class MdParser
  def extract_links(md)
    links = {}

    contents = IO.read(md) if File.file? md
    ls = contents.scan(/\[.*\]\(.*\)/)
    ls.each do |l|
      key = l.match(/\[.*\]/)[0].gsub(/\[|\]/, '')
      value = l.match(/\(.*\)/)[0].gsub(/\(|\)/,'')
      links[key] = value unless links.has_key? key
    end

    links
  end
end

parser = MdParser.new
# extract links
links = parser.extract_links("README.md");
links.each { |key, value| puts "#{key}: #{value}" }
