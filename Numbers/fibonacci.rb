# explanation:
# times: run a command n times
# each_with_object(obj): iterate the given block with an object given, and return the object
def fibonacci(n)
  n.times.each_with_object([0,1]) { |num, obj| obj << obj[-2] + obj[-1] }
end

puts fibonacci(10)
