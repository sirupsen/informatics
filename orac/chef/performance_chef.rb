require 'test/unit'

class Test::Unit::TestCase
  def send_input(input)
    format_output(`echo #{input} | ./a.out`)
  end

  def format_output(output)
    output.strip.to_i
  end

  def test_first_one
    assert_equal 2, send_input("4 6 3 -1 5")
  end

  def test_second
    assert_equal 8, send_input("8 -3 10 19 9 7 10 0 5")
  end

  def test_third
    assert_equal -4, send_input("3 -10 -4 1")
  end
end

# n = rand(20000) + 1
# puts "N: #{n}"
# 
# tastes = []
# n.times do
#   tastes << (rand(50) + 1)
# end
# 
# command = "echo #{n} #{tastes.join(' ')} | ./a.out"
# 
# before = Time.now
# puts `#{command}`
# after = Time.now
# 
# puts after - before
