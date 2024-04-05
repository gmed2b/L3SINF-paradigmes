import System.IO

square x = x * x

quad x = square (square x)

greater x y
  | x > y = x
  | otherwise = y

area r = pi * r ^ 2
