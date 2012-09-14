N = 10
Rand = 10
Offset = 5

def rnd
  rand(Rand) - Offset
end

File.open("input.gen", "w") do |f|
  f.write N.to_s + " "
  f.write 1.to_s + "\n"

  N.times do
    f.write(rnd.to_s + "\n")
  end

  f.write("#{rnd + Offset + 1} #{rand(5) + 1}")
end
