tripletPythagore :: Int -> [(Int, Int, Int)]
tripletPythagore n = [(a, b, c) | a <- [1 .. n], b <- [a .. n], c <- [b .. n], ((a ^ 2) + (b ^ 2)) == (c ^ 2)]
