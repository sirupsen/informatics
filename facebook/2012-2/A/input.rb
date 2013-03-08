File.open("input.3", "w") do |f|
  10_000.times do
    f.write "#{rand(1_000_000)} "
  end
end
