lstDiviseur :: Int -> [Int]
lstDiviseur e = [x | x <- [1 .. e], e `mod` x == 0]
