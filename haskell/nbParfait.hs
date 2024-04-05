lstDiviseur :: Int -> [Int]
lstDiviseur e = [x | x <- [1 .. e], e `mod` x == 0]

nbParfait :: Int -> [Int]
nbParfait n = [x | x <- [6 .. n], sum (lstDiviseur x) - x == x]
