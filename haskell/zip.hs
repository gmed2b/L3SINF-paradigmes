zip1 :: [a] -> [b] -> [(a, b)]
zip1 [] [] = []
zip1 (x : xs) [] = error "Les deux liste doivent avoir la meme longueur"
zip1 [] (y : ys) = error "Les deux liste doivent avoir la meme longueur"
zip1 (x : xs) (y : ys) =
  let lst_retour = zip1 xs ys
   in ((x, y) : lst_retour)

-- comment verifier que les deux listes font la meme longueur
