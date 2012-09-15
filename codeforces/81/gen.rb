N = 100000

o =  [('A'..'Z')].map{|i| i.to_a}.flatten;  
string  =  (0..N).map{ o[rand(o.length)]  }.join;

puts string
