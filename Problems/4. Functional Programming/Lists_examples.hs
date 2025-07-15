main :: IO()
main = do
    print (naturals 3)

naturals :: [Integer]
naturals = [0..]

isPrime :: Integer -> Bool
isPrime n = [1, n] == [d | d <- [1..n], mod n d == 0]

primes :: [Integer]
primes = [p | p <- tail naturals, isPrime p]

fibs :: [Integer]
fibs = [fib n | n <- naturals]

fibs' = 1 : 1 : zipWith (+) fibs' (tail fibs')