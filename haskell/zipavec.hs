zipAvec :: (a -> b -> c) -> [a] -> [b] -> [c]
zipAvec func [] l2 = []
zipAvec func l1 [] = []
zipAvec func (x : xs) (y : ys) =
  let lst = zipAvec func xs ys
   in func x y : lst
