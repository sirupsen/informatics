@total_workers = 4
workers = 4

# p order  = [1,3,4,2,3,1,2,4,3,2]
# p target = [1,1,2,2,2,3,3,3,4,4]
order = [2,3,3,4,4,2,1,1,3,1]
target = [1,1,1,2,2,3,3,3,4,4]

def switch()
  start_target_range = target.index(type) # Start of target range
  end_target_range = (target.index(type + 1) || (target.length)) - 1 # End of target range is the start of next type

  # Find out whether any of the elements in the target range fit in this
  # spot.
  (start_target_range..end_target_range).each do |i|
    if target[tmp_index] != target[i] # if its not wished there, we wanna switch with it
      output << [(tmp_index + 1), (i + 1)]
      order[i] = order[tmp_index]

      workers -= 1
      p workers
      sleep(4)
    end
  end
end

def round(order, target, workers)
  index = 0
  output = []
  p order

  while workers != 0
    type = order[index]

    # Still workers, no N effective swap
    if index > (target.length - 1)
      tmp_index = index - target.length
      moves = @total_workers - 1
      type = order[tmp_index]

      unless type == target[tmp_index]
        switch(type, target, order)
      end
    else
      # Find first wrongly positioned car
      unless type == target[index]
        start_target_range = target.index(type) # Start of target range
        end_target_range = (target.index(type + 1) || (target.length)) - 1 # End of target range is the start of next type

        # Find out whether any of the elements in the target range fit in this
        # spot.
        (start_target_range..end_target_range).each do |i|
          # If the element in the target range has optimum where the current
          # number is
          if order[i] == target[index]
            output << [(index + 1), (i + 1)]
            output << [(i + 1), (index + 1)]

            order[index] = order[i]
            order[i] = type

            workers -= 2
            break # break this
          end
        end
      end

      index += 1
    end
  end

  p output
  order
end

loop do
  new_order = round(order, target, workers)

  if new_order == target
    puts "done"
    break
  end

  order = new_order
end
