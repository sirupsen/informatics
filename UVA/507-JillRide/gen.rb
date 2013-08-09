n = 10_000_000

File.open("input.3", "w") do |f|
  f.write "1\n"
  f.write "#{n}\n"

  n.times do
    f.write "#{rand(100) - 50}\n"
  end
end
