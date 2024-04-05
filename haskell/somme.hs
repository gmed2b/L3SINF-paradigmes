folder :: (a -> b -> b) -> b -> [a] -> b
folder func e [] = e
folder func e [x] = func x e
folder func e (x : xs) = func x (folder func e xs)

mSomme :: [Int] -> Int
mSomme = folder (+) 0
