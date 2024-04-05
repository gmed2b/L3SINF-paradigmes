-- Equation gardé
length1 :: [a] -> Int
length1 liste = lenghtacc 0 liste
  where
    lenghtacc acc liste
      | null liste = acc
      | otherwise = lenghtacc (acc + 1) (tail liste)

-- Pattern matching
length2 :: [a] -> Int
length2 liste = lenghtacc 0 liste
  where
    lenghtacc acc [] = acc
    lenghtacc acc (x : liste) = lenghtacc (acc + 1) liste
