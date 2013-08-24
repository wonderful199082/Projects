class FileExplorer
  def dir_of(dir)
    arr = []
    Dir.foreach(dir) { |f| arr << f } if File.directory? dir

    arr
  end

  def file_of(dir)
    Dir["#{dir}/**/*"]
  end

  def list(dir)
    arr = dir_of(dir)
    arr.each { |f| puts f }
  end

  def list_r(dir)
    puts file_of(dir)
  end
end

fe = FileExplorer.new
fe.list_r("/")
