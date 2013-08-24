def count_words(content)
  stats = {}

  words = content.split(/\W+/)
  words.each do |word|
    if stats.has_key? word
      stats[word] = stats[word] + 1
    else
      stats[word] = 1
    end
  end

  stats.sort_by { |key, value| -value }
end

def p_hash(h)
  h.each { |key, value| puts "#{key}: #{value}" }
end

def content_of(filename)
  IO.read(filename) if File.file?(filename)
end

filename = "README.md"
p_hash(count_words(content_of(filename)))
