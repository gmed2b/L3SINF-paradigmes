unzip1 :: [(a, b)] -> ([a], [b])
unzip1 [] = ([], [])
unzip1 ((a, b) : xs) =
  let (l1, l2) = unzip1 xs
   in (a : l1, b : l2)
