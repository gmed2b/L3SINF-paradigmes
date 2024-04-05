partage :: [e] -> ([e], [e])
partage [] = ([], [])
partage [x] = ([x], [])
partage (x : y : xs) =
  let (l1, l2) = partage xs
   in (x : l1, y : l2)

-- partage (x : y : xs) =
--   (x:l1, y:l2)
--     where
--       (l1, l2) = partage xs
