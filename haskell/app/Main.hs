-- run with `cabal run`
-- or execute parts interactively with `ghci` and `:l app/Main`/`:r`

-- as haskell is lazily evaluated, only values which are actually needed
-- are computed. this doesn't happen for most of the examples here.

-- disable warning for not knowing the HLINT pragma
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

-- uhh
module Main (main) where

-- the main function of type IO to allow IO
main :: IO ()
main = putStrLn "Hello World"

---- some example expressions with wildcard pattern (`_`) bindings
_ = 3 + (-3) -- always put unary minus in parentheses!
{-# HLINT ignore #-}
_ = not False && True || True -- boolean operations
_ = 0 /= 0 -- unusual syntax for inequality

-- a function that takes one argument and doubles it
-- we can supply the explicit type signature optionally:
-- constraining type a to be Number, receiving one
-- as as an argument, and returning one.
double :: Num a => a -> a
double x = x * 2
-- call a function like this
_ = double 3

-- note how in the type signature, the last type is the returned type
myMin :: Ord a => a -> a -> a
myMin a b = if a < b then a else b

-- arithmetic operators like `+` are also functions, but in infix notation.
-- self-defined functions can also be used called infix notation like this: 
_ = 1 `myMin` 2

-- a function without parameters is a "definition"
value = 3
