array = [2, 2, 2, -4, -4]

0..array.size.times.each do |i| 
  array.combination(i).to_a.each { |a| print a if a.inject(:+) == 0} 
end

print("\n")