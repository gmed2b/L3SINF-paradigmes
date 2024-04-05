folder :: (a -> b -> b) -> b -> [a] -> b
folder func e [] = e
folder func e [x] = func x e
folder func e (x : xs) = func x (folder func e xs)

mLength :: [e] -> Int
mLength = folder (\x y -> 1 + y) 0

-- mLength lst = folder (\x y -> 1 + y) 0 lst
