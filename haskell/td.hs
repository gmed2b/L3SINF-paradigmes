module TD where

monLast :: [e] -> e
monLast [] = error "List can't be null"
monLast (x : xs)
  | not (null xs) = monLast xs
  | otherwise = x

appartient :: (Eq e) => e -> [e] -> Bool
appartient e (x : xs)
  | null xs = error "pas trouvé"
  | e == x = True
  | otherwise = appartient e xs
