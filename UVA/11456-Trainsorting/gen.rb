ns = [0, 1, 3, 5, 8, 10, 15, 20, 50, 200, 400, 500, 800, 900, 1000, 1200, 1500, 1700, 2000]

i = 2;

def rand_2(check, n)
  boom = rand(n * 2) + 1

  return boom unless check[boom]
  return rand_2(check, n)
end

ns.each do |n|

  File.open("input.#{i}", 'w') do |f|
    f.write "#{n}\n"

    check = {}

    n.times do
      random = rand_2(check, n)
      check[random] = true
      f.write "#{random}\n"
    end
  end

  i += 1
end

i = 2;
ns.count.times do
  system("clang++ ddd-trainsorting.cpp -o train && time cat input.#{i} | ./train > output.#{i}")
  i += 1
end
