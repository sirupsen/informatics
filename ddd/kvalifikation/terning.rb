cubes = [
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

class Node
  attr_accessor :children, :parent, :sides, :index_up

  def initialize(sides = nil, index_up = nil, parent = nil)
    @sides = sides
    @fuck = sides
    @index_up = index_up
    @children = []
    @parent = parent
  end

  def add_child(sides, up)
    new = Node.new(sides, up, self)
    @children << new
    new
  end

  def sum
    return highest_side + @parent.sum if @sides
    0
  end

  def highest_side
    @sides.reject { |item| item == @sides[@index_up] || item == @sides[opposite_of_index(@index_up)]  }.max
  end

  def opposite_of_index(index)
    case index
    when 0
      @sides[5]
    when 1
      @sides[3]
    when 2
      @sides[4]
    when 3
      @sides[1]
    when 4
      @sides[2]
    when 5
      @sides[0]
    end
  end
end

main_node = Node.new
current_nodes = []
next_nodes = [main_node]
sum = []

cubes.each do |cube|
  current_nodes = next_nodes
  next_nodes = []

  0.upto(5) do |i|
    current_nodes.each do |node|
      child = node.add_child(cube, i)
      next_nodes << child
      sum << child.sum
    end
  end
end

p sum.max
