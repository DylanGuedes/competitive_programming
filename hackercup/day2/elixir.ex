{:ok, file} = File.open "inp", [:write]

seq = 1..300
for n <- seq do
  [1..300 | seq]
end
result = [300, 300, seq]
IO.binwrite file, Enum.join(result)
