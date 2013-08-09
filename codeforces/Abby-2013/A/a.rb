s=gets

used = {}
als = 0
sum = 1

class String
  def is_number?
    true if Float(self) rescue false
  end
end

s.each_char.each_with_index do |c, i|
  mult = 1

  if c == '?'
    if i > 0
      mult = 10
    else
      mult = 9
    end
  elsif c.ord >= 'A'.ord && c.ord <= 'Z'.ord
    if used[c]
      mult = 1
    elsif i > 0
      mult = 10 - als
    else
      mult = 9
    end
  end

  sum *= mult

  if c.ord >= 'A'.ord && c.ord <= 'Z'.ord && !used[c]
    als += 1
    used[c] = true;
  end
end

puts sum
