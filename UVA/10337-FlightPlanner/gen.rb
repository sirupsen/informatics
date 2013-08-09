p ARGV
X = ARGV[0].to_i

def random_positive_negative(n)
  rand(2) == 1 ? -n : n
end

File.open("input.#{ARGV[1]}", "w") do |f|
  f.write "#{X}\n"

  for y in 1..10 do
    for x in (1..(X/100)) do
      f.write "#{random_positive_negative(rand(11))} "
    end

    f.write "\n"
  end
end
