main :: IO()
main = do
    print 15
    print [1,3..10]
    print (zip [0,10..] [1,3..10])
    print (member 2 [1..10])
    print (member 20 [1..10])
    print (member 6 [1..])
    --print (member 6 [1,10..])
    print (memberOrderedList 6 [1..])
    print (memberOrderedList 6 [1,7..])
    print (take 10 naturals)
    print (take 10 primes)
    print (take 10 (drop 10 primes))
    print (fib 5) -- 1 1 2 3 5 8
    print (take 10 fibs)
    print (zip [1..10] (tail [1..10]))
    print (zipWith (+) [1..10] (tail [1..10]))
    print (take 50 fibs')
    print (take 10 (drop 50 fibs'))

member :: Eq a => a -> [a] -> Bool
member _ []     = False
member x (a:as) = x == a || member x as

memberOrderedList :: (Ord a, Eq a) => a -> [a] -> Bool
memberOrderedList _ []     = False
memberOrderedList x (a:as)
 | x == a = True
 | x < a  = False
 | otherwise = memberOrderedList x as

naturals :: [Integer]
naturals = [0..]

isPrime :: Integer -> Bool
isPrime n = [1, n] == [d | d <- [1..n], mod n d == 0]

primes :: [Integer]
primes = [p | p <- tail naturals, isPrime p]

fib :: Integer -> Integer
fib 0 = 1
fib 1 = 1
fib n = fib (n - 2) + fib (n - 1)

fibs :: [Integer]
fibs = [fib n | n <- naturals]

-- 1 1 2 3 5 8  13 21 ...
-- 1 2 3 5 8 13 21 34 ...

fibs' = 1 : 1 : zipWith (+) fibs' (tail fibs')
