times = []

100.times do
  dices = []

  (rand(10000) + 1).times do
    dices << [1,2,3,4,5,6].shuffle
  end

  dice_strings = dices.map { |dice| dice.join(" ") }.join("\n")

  before = Time.now
  output = `echo "#{dices.count} #{dice_strings}" | ./a.out`
  after = Time.now

  c_tiem = after - before
  times << c_tiem

  puts "#{dices.count} dices, highest possible sum: #{output} in #{c_tiem}s"
end

puts times.reduce(:+) / times.count
