require 'time'

days = [0,0,0,0,0,0,0]

1.upto(12) do |month|
  thirteenth = Time.parse("1900/#{month}/13")

  days[thirteenth.wday] += 1
  p thirteenth.wday
  p thirteenth.strftime("%A")
end

print days[6]
print " "
print days[0]
print " "
print days[1]
print " "
print days[2]
print " "
print days[3]
print " "
print days[4]
print " "
print days[5]
print "\n"
