facacc :: Integer -> Integer -> Integer
facacc acc 0 = acc
facacc acc n
  | n > 0 = facacc (acc * n) (n - 1)
  | otherwise = error "N doit être >0"

facto :: Integer -> Integer
facto = facacc 1
