som :: Integer -> Integer
som 0 = 0
som n = n + som (n - 1)

-- somacc :: Integer -> Integer
somacc n = somaux 0 n
  where
    somaux acc n
      | n == 0 = acc
      | n > 0 = somaux (n + acc) (n - 1)
      | otherwise = error "N doit etre >0"
