multiply a n
  | a == 0 = 0
  | n == 0 = 0
  | otherwise = a + multiply a (n - 1)
