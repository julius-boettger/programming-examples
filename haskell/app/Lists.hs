-- this module is not used when running the main function.
-- load it with ghci to play around!
module Lists () where

myList = [1, 2, 3] -- a simple list
_ = myList !! 1 -- index it
_ = length myList -- check length
_ = null myList -- check if empty

_ = head myList -- first element
_ = last myList -- last element
_ = tail myList -- all elements except first
_ = init myList -- all elements except last

_ = [1, 2] ++ [3, 4] -- concatenate lists
_ = 1:[2, 3] -- add something to the start using the "cons" operator

-- strings are lists!
myString = "hello" ++ " " ++ "world"
