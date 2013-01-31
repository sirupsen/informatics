# order = [1,3,4,2,3,1,2,4,3,2]
# target_order = [1,1,2,2,2,3,3,3,4,4]
order = [2,3,3,4,4,2,1,1,3,1]
target_order = [1,1,1,2,2,3,3,3,4,4]

workers = 4
all_swaps = []

# We're /always/ better!
(10/(4-1)).times do
  swaps = []

  order.each_with_index do |type, index|
    break if workers == 0
    current_type_at_index = order[index]

    # The car is not in the right spot
    if current_type_at_index != target_order[index]
      # Lets check if we can swap smartly

      # In which parking lots does the current car want to be?
      target_start = target_order.index(type)
      target_end = (target_order.index(type + 1) || (target_order.length)) - 1

      target_range = (target_start..target_end)

      # Check the target range for a type that wants to be in place of the current
      # wrong positioned one
      target_range.each do |range_index|
        if order[range_index] == target_order[index] # match!
          swaps << [index + 1, range_index + 1]
          swaps << [range_index + 1, index + 1]

          order[index] = order[range_index]
          order[range_index] = current_type_at_index

          workers -= 2
        end
      end
    end
  end

  # If there are still enough workers left to do some moving, let's go ahead and
  # perform some "dumb" switching as part of the round
  if workers > 1
    order.each_with_index do |type, index|
      break if workers == 0
      current_type_at_index = order[index]

      # The car is not in the right spot
      if current_type_at_index != target_order[index]
        target_range = target_order.index(type)..((target_order.index(type + 1) || (target_order.length)) - 1)

        target_range.each do |range_index|
          if target_order[range_index] != target_order[index]
            swaps << [range_index + 1, index + 1]

            new_type = order[range_index]
          end
          break
        end
      end
    end
  end

  p swaps

  if order == target_order
    puts "Done"
    exit
  end

  all_swaps << swaps
  workers = 4
end

puts "oh shi-"
