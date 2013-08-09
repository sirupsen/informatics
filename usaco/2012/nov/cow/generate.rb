100_000_000.times do |i|
  puts i if i % 100000 == 0

  File.open "./input.9", "a" do |f|
    if rand(2) == 1
      f.write "("
    else
      f.write ")"
    end
  end
end
