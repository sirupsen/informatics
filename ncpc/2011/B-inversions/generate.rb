n = ARGV[0]

File.open("input.gen", "w") do |f|
  f.write "#{n} "

  n.to_i.times do
    f.write "#{(rand(n.to_i - 1) + 1)} "
  end
end
