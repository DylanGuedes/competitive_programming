grid = [1, 300, 300]
300.times do |k|
  300.times do |idx|
    grid.push(100000)
  end
  grid.push(" ")
end

yourfile = "myinp"
grid = grid.join(" ")
File.open(yourfile, 'w') { |file| file.write(grid) }
