folder :: (a -> b -> b) -> b -> [a] -> b
folder func e [] = e
folder func e [x] = func x e
folder func e (x : xs) = func x (folder func e xs)

conkat :: [[e]] -> [e]
conkat = folder (++) []

-- conkat lst = folder (++) [] lst

conkatLC :: [[a]] -> [a]
conkatLC lst = [y | x <- lst, y <- x]
