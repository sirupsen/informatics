all_actual_rounds = []
theory_max_rounds = []
time_in_c = []

100.times do 
  order  = []

  n = rand(1000) + 200
  m = rand(48) + 4
  w = rand(m) + 2

  n.times do
    order << rand(m) + 1
  end
  target = order.sort

  p n 
  p m
  p w

  before = Time.now
  output = `echo #{n} #{m} #{w} #{order.join(" ")} | ./a.out`
  after = Time.now
  c_time = after - before
  time_in_c << c_time

  fixed_output = output.split("\n")
  actual_rounds = fixed_output[1]
  all_actual_rounds << actual_rounds
  reorderings = fixed_output[2..-1].map { |e| e.split }

  reorderings.each do |reordering|
    reordering.shift # fuck the count

    reordering.each_slice(4) do |switch|
      first = order[switch[0].to_i - 1]
      last = order[switch[1].to_i - 1]

      order[switch[0].to_i - 1] = last
      order[switch[1].to_i - 1] = first
    end
  end

  theory_max = n/(w-1)
  theory_max_rounds << theory_max

  if order == target
    puts "YES in #{actual_rounds} upper bound: #{theory_max}, time in C: #{c_time}"
  else
    # p reorderings
    # p output
    # p fixed_output
    # p order
    # p target
    # p n 
    # p m
    # p w
    raise "OMG FUCK NO"
  end
end

puts "Average actual: #{all_actual_rounds.map(&:to_i).reduce(:+) / all_actual_rounds.count}"
puts "Average theory: #{theory_max_rounds.map(&:to_i).reduce(:+) / theory_max_rounds.count}"
puts "Average time in C: #{time_in_c.reduce(:+) / time_in_c.count}"
