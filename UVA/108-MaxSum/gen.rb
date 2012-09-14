ns = [1, 2, 4, 5, 8, 10, 15, 18, 20, 28, 35, 40, 50, 67, 80, 90, 92, 100]

i = 2;

def rand_positive_or_negative(n)
  rand(2) == 1 ? -n : n
end

ns.each do |n|
  File.open("input.#{i}", "w") do |f|
    f.write "#{n}\n"

    n.times do
      n.times do
        f.write "#{rand_positive_or_negative(rand(101))} "
      end

      f.write "\n"
    end
  end

  i += 1
end


system("clang++ 108-maxsum.cpp -o maxsum")

ns.count.times do |i|
  system("time cat input.#{i+1} | ./maxsum > output.#{i+1}")
end
