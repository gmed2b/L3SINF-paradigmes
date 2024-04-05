estPremier :: Int -> Bool
estPremier e = [x | x <- [1 .. e], mod e x == 0] == [1, e]
