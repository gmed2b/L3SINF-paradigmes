map1 :: (e -> r) -> [e] -> [r]
map1 func [] = []
map1 func (x : xs) = func x : map1 func xs
