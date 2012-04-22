dices = [
  [  2,
   3,1,6,5,
     4
  ],
  [  3,
   1,2,4,6,
     5
  ],
  [  5,
   6,4,1,3,
     2
  ],
  [  1,
   3,6,2,4,
     5
  ],
  [  4,
   1,6,5,2,
     3
  ]
]

def opposite_index(index)
  case index
  when 0
    5
  when 1
    3
  when 2
    4
  when 3
    1
  when 4
    2
  when 5
    0
  end
end

max_sum = 0

0.upto(5) do |i|
  # Up of fake dice before first to keep DRY
  prev_up = dices.first[opposite_index(i)]
  sum = 0

  dices.each do |dice|
    down_index = dice.index(prev_up)
    up_index = opposite_index(down_index)

    sum += dice.reject { |e| e == dice[up_index] || e == dice[down_index] }.max
    prev_up = dice[up_index]
  end

  sum > max_sum and max_sum = sum
end

p max_sum
