main :: IO()
main = do
    print (map (+1) [1, 2, 3]) -- apply a function to every element of a list
    print (concatMap (\x -> [x, x + 1]) [1, 2, 3]) -- maps and concatenates the result in one list
                                                   -- [1, 2, 2, 3, 3, 4]
    print (filter even [1, 2, 3, 4]) -- filters elements in a list by a given predicate
    print (zip [1, 2, 3] [4, 5, 6]) -- combines pairs of elements from two lists in one list of pairs
    print (zipWith (+) [1, 2, 3] [4, 5, 6]) -- merges two lists with a function
    print (foldl (+) 0 [1, 2, 3]) -- folds (reduces) a list from left to right (((0 + 1) + 2) + 3)
    print (foldr (+) 0 [1, 2, 3]) -- folds (reduces) a list from right to left (1 + (2 + (3 + 0)))
    print (foldl1 (+) 0 [1, 2, 3]) -- like foldl but doesn't require initial value, uses the last element of the list
    print (foldr1 (+) 0 [1, 2, 3]) -- like foldr but doesn't require initial value, uses the first element of the list
    print (takeWhile (< 5) [1, 2, 3, 6, 7]) -- takes elements until the condition is false
    print (dropWhile (< 5) [1, 2, 3, 6, 7]) -- drops elements until the condition is false
    print (any even [1, 3, 5, 6]) -- returns true if at least on element matches the condition
    print (all even [1, 3, 5, 6]) -- return true if all elements match the condition
    print ((f . g) 3) -- f(g(3)) = 7
    print (f $ g 3) -- f(g(3)) = 7
    
    print (foldl (:) [] [1, 2, 3, 4]) -- [4, 3, 2, 1]

    print (zip [0,10..] [1,3..10]) -- [(0,1), (10,3), (20,5), (30,7), (40,9)]
    print (take 10 naturals) -- [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    print (take 5 primes) -- [2, 3, 5, 7, 11]
    print (take 10 (drop 10 primes)) -- [31, 37, 41, 43, 47, 53, 59, 61, 67, 71]
    print (fib 5) -- 1 1 2 3 5 8
    print (take 10 fibs) -- [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
    print (zip [1..10] (tail [1..10])) -- [(1,2), (2,3), (3,4), (4,5), (5,6), (6,7), (7,8), (8,9), (9,10)]
    print (zipWith (+) [1..10] (tail [1..10])) -- [3, 5, 7, 9, 11, 13, 15, 17, 19]
    print (take 50 fibs') -- първите 50 числа на Фибоначи
    print (take 10 (drop 50 fibs')) -- следващите 10 числа на Фибоначи след 50-то

f :: Int -> Int
f x = x + 1

g :: Int -> Int
g x = x * 2

naturals :: [Integer]
naturals = [0..]

isPrime :: Integer -> Bool
isPrime n = n > 1 && length [x | x <- [1..n], n `mod` x == 0] == 2

primes :: [Integer]
primes = [p | p <- tail naturals, isPrime p]

flatten :: [[Integer]] -> [Integer]
flatten list = foldr (++) [] list -- flatten = foldr (++) []

map (\(x:y:z) -> x:z) [(1, 2, 3), (2, 3, 1), (3, 1, 2)] -- [[1, 3], [2, 1], [3, 2]]
map (\(x,y,z) -> x^y) [(1, 2, 3), (2, 3, 1), (3, 1, 2)] -- [1, 8, 3]

filter (<= x) lst == [y | y <- lst, y <= x]
filter (`elem` ['a'..'z']) "u LaUgH aT mE BeCaUsE I aM diFfeRent"

