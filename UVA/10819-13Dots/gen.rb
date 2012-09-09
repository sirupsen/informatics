money = rand(10000)
products = 100

File.open("input.gen", "w") do |f|
  f.write "#{money} #{products}\n"
  products.times do
    f.write "#{rand(4000)} #{rand(5) + 1}\n"
  end
end
