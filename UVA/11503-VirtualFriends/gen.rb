n = 100000

names = []

(n/2).times do 
  names << (0...8).map{65.+(rand(25)).chr}.join
end

File.open("input.3", "w") do |f|
  f.write "1\n"
  f.write "#{n}\n"

  n.times do
    f.write "#{names.sample} #{names.sample}\n"
  end
end
