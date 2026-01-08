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

concatList = [1, 2] ++ [3, 4] -- concatenate lists
_ = 1:[2, 3] -- add something to the start using the "cons" operator

---- ranges: cool shorthand for constructing lists
rangeList = [1..5] -- both limits are included!
rangeStepList = [1,4..20] -- complete with the difference of the first two
_ = ['a'..'z'] -- works for chars

---- list comprehensions
comprehendList = [x * 2 | x <- [1..10]] -- double all elements of a list
-- but only for x's under a certain conditions
comprehendCondList = [x * 2 | x <- [1..10], x > 5, x < 10]
-- works with multiple variables (gives all combinations / cross product)
combinationsList = [x * y | x <- [1..3], y <- [1..3]]

-- strings are lists (of chars)! this all works for them!
myString = "hello" ++ " " ++ "world"
