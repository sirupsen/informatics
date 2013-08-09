def substring_indices(string, substring, offset, indices)
  new_index = string.index(substring, offset)
  return substring_indices(string, substring, new_index + 1, indices << new_index + 1) if(new_index)
  indices
end

p substring_indices("ACGTACGTACGTACGT", "GTA", 0, [])
