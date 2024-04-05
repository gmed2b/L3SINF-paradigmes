filter1 :: (e -> Bool) -> [e] -> [e]
filter1 func [] = []
filter1 func (x : xs)
  | not (func x) = filter1 func xs
  | otherwise = x : filter1 func xs
