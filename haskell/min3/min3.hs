module Main (main) where

import System.IO

min3 x y z = min x (min y z)

main = do
  hSetBuffering stdout NoBuffering
  putStrLn "Enter three numbers"
  x <- readLn :: IO Int
  y <- readLn :: IO Int
  z <- readLn :: IO Int
  putStrLn ("The minimum is " ++ show (min3 x y z))
