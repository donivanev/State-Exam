main :: IO()
main = do
    print (mymin 16 11)
    print (16 `mymin` 11)
    print (isInside 6 1 10)
    print (myfunc 10 20)
    --print (myfunc' 10 20)
    print (myFib 5)
    print (myFibIter 500)
    print (mygcd 5 15)

    print (incrementAllBy [1, 2] 3)
    print (multiplyAllBy [1, 2] 3)

-- Да се напише функция mymin, която приема два аргумента и връща по-малкия от тях.

mymin :: Int -> Int -> Int
mymin a b = if a < b then a else b

-- Да се дефинира функцията isInside x a b, която проверява дали числото x се намира в затворения интервал [a, b].

isInside :: Double -> Double -> Double -> Bool
isInside x a b = a <= x && x <= b

-- Да се напише функция myfunc, която пресмята средно аритметично на квадратите на 2 числа.

myfunc :: Double -> Double -> Double
myfunc a b = (a * a + b * b) / 2

myfunc' :: Double -> Double -> Double
myfunc' a b = average (square a) (square b)
    where
        average a b = (a + b) / 2
        square x = x * x

{-
    Да се напише myfib, която получава един аргумент n и връща n-тото число на Фибоначи. Да се напише и итеративно решение.
    (Заб.: редицата е 1, 1, 2, 3, 5, 8, ... и е индексирана от 0.)
-}

myFib :: Int -> Int
myFib n
    | n == 0    = 1
    | n == 1    = 1
    | otherwise = myFib (n - 1) + myFib (n - 2)

myFib' :: Int -> Int
myFib' 0 = 1
myFib' 1 = 1
myFib' n = myFib' (n - 1) + myFib' (n - 2)

myFibIter :: Integer -> Integer
myFibIter n = helper 0 0 1
    where
        helper i next current
            | i > n     = next
            | otherwise = helper (i + 1) (current + next) next

-- Да се напише функция mygcd a b, която връща НОД(a, b).

mygcd :: Int -> Int -> Int
mygcd a b
    | a == b    = a
    | a > b     = mygcd (a - b) b
    | otherwise = mygcd a (b - a)

-- Да се напише функция mymaxdivisor x, която намира най-големия делител d на цялото число x > 1, за който d < x.

mymaxadvisor :: Int -> Int
mymaxadvisor x = helper (x - 1)
    where
        helper d
            | x `mod` d == 0 = d
            | otherwise      = helper (d - 1)

-- Да се дефинира функция, която намира сумата на нечетните числа в затворения интервал [a, b].

sumOdd :: Int -> Int -> Int
sumOdd a b
    | a > b          = 0
    | a `mod` 2 == 1 = a + sumOdd (a + 1) b
    | otherwise      = sumOdd (a + 1) b

-- Да се дефинира предикат, който проверява дали естественото число n е просто.

isPrime :: Integer -> Bool
isPrime 1 = False
isPrime n = helper 2
    where
        helper i
            | i == n       = True
            | mod n i == 0 = False
            | otherwise    = helper (i + 1)

-- Да се дефинира функция, която намира броя на палиндромите в интервала [a, b], където a и b са цели неотрицателни числа и a < b.  

isPalindrome :: Integer -> Bool
isPalindrome n = if (n == reverse n 0) then True else False
    where
        reverse n sum = if n <= 0 then sum else reverse (n `div` 10) (sum * 10 + mod n 10)

countpalindromes :: Int -> Int -> Int
countpalindromes a b
    | a > b            = 0
    | ispalindome a 0  = 1 + countpalindromes (a + 1) b
    | otherwise        = countpalindromes (a + 1) b
    where
        ispalindome y x = if y == 0 then x == a else ispalindome (div y 10) (x * 10 + mod y 10)

-- Да се дефинира функция, която чрез линейно итеративен процес намира броя на естествените делители на едно естествено число.

countDel :: Integer -> Integer
countDel n = helper 2
    where
        helper i
            | i == n         = 0
            | (mod n i) == 0 = 1 + helper (i + 1)
            | otherwise      = helper (i + 1)

countDivisors :: Int -> Int
countDivisors n = helper n 1 0
    where
        helper n d counter
            | d > n        = counter
            | mod n d == 0 = helper n (d + 1) (counter + 1)
            | otherwise    = helper n (d + 1) counter

-- ________________________________________

-- Да се дефинира функцията incrementAllBy :: [Int] -> Int -> [Int], която получава списък и число и го добавя към всеки елемент на списъка

incrementAllBy :: [Int] -> Int -> [Int]
incrementAllBy [] n       = []
incrementAllBy (x : xs) n = (x + n) : incrementAllBy xs n

incrementAllBy' :: [Int] -> Int -> [Int]
incrementAllBy' xs n = if null xs then [] else ( (head xs) + n : ( incrementAllBy (tail xs) n) )

incrementAllBy'' :: [Int] -> Int -> [Int]
incrementAllBy'' xs n = [x + n | x <- xs]

-- Да се дефинира функцията multiplyAllBy :: [Int] -> Int -> [Int], която получава списък и число и умножава всеки елемент на списъка по числото

multiplyAllBy :: [Int] -> Int -> [Int]
multiplyAllBy [] n       = []
multiplyAllBy (x : xs) n = (x * n) : multiplyAllBy xs n

multiplyAllBy' :: [Int] -> Int -> [Int]
multiplyAllBy' xs n = [x * n | x <- xs]

-- Да се дефинира функцията filterSmallerThan , която получава списък и число и премахва елементите на списъка, които са по-малко от числото

filterSmallerThan :: [Int] -> Int -> [Int]
filterSmallerThan xs n = [x | x <- xs, x > n]

-- Да се дефинира функция isAscending :: Integer -> Bool, която проверява дали цифрите на число са във възходящ ред
-- Функцията да получава число, но да работи със списък от цифрите му.

isAscending :: Int -> Bool
isAscending n = helper (toList n)
    where
        toList n            = if n <= 0 then [] else mod n 10 : toList (div n 10)
        helper [x]          = True
        helper (x : y : xs) = if x < y then False else helper (y : xs)
    
isAscending' :: [Int] -> Bool
isAscending' xs
    |null xs || null (tail xs) = True
    |head xs >= head (tail xs) = False
    |otherwise                 = isAscending' (tail xs)

numToList :: Int -> [Int]
numToList n = if n < 10 then [n] else (mod n 10) : numToList (div n 10)
