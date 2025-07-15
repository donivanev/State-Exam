main :: IO()
main = do
    print (mymin 10 8)
    print (isInside 4 1 8)
    print (myfunc 4 9)
    print (myfib 6)
    print (mygcd 5 15)
    -- print (mymaxadvisor 1)
    print (sumOdd 5 15)
    print (isPrime 20)
    -- print (countPalindromes 10 23)
    print (incrementAllBy [2, 3, 4, 5, 6] 5)
    print (multiplyAllBy [2, 3, 4, 5, 6] 2)
    print (filterSmallerThan [2, 3, 4, 5, 6] 4)
    print (toList 378)
    print (isAscending 378)

    print (isImage [1, 5, 8] [7, 2, 4])
    print (chunksOf 3 [1, 5, 8, 11, 16, 20, 23, 27, 32])
    print (divisors 3)
    print (prodSumDiv [6, 12, 18] 3)
    print (isSorted [9, 4, 8])
    print (insert 3 [1, 5, 8])

-- Да се напише функция mymin, която приема два аргумента и връща по-малкия от тях.
mymin :: Int -> Int -> Int
mymin a b = if a < b then a else b

-- Да се дефинира функцията isInside x a b, която проверява дали числото x се намира в затворения интервал [a, b].
isInside :: Int -> Int -> Int -> Bool
isInside x a b
  | x < a = False
  | x > b = False
  | otherwise = True

-- Да се напише функция myfunc, която пресмята средно аритметично на квадратите на 2 числа.
myfunc :: Double -> Double -> Double
myfunc a b = avg (sq a) (sq b)
  where 
        avg a b = (a + b) / 2
        sq x = x * x 

-- Да се напише myfib, която получава един аргумент n и връща n-тото число на Фибоначи. Да се напише и итеративно решение
myfib :: Int -> Int
myfib n
  | n == 0 = 0
  | n == 1 = 1
  | otherwise = myfib (n - 1) + myfib (n - 2)

-- Да се напише функция mygcd a b, която връща НОД(a, b).
mygcd :: Int -> Int -> Int
mygcd a b
  | a == 0 = a
  | otherwise = mygcd (b `mod` a) b

-- Да се напише функция mymaxdivisor x, която намира най-големия делител d на цялото число x > 1, за който d < x.
-- mymaxadvisor :: Int -> Int
-- mymaxadvisor x

-- Да се дефинира функция, която намира сумата на нечетните числа в затворения интервал [a, b].
sumOdd :: Int -> Int -> Int
sumOdd a b
  | a > b = 0
  | a `mod` 2 == 0 = sumOdd (a + 1) b
  | otherwise = sumOdd (a + 1) b + a

-- Да се дефинира предикат, който проверява дали естественото число n е просто.
isPrime :: Integer -> Bool
isPrime n
  | n == 1 = False
  | otherwise = divisor 2
    where 
      divisor i
        | i == n = True
        | n `mod` i == 0 = False
        | otherwise = divisor (i + 1)

-- Да се дефинира функция, която намира броя на палиндромите в интервала [a, b], където a и b са цели неотрицателни числа и a < b.
-- countPalindromes :: Int -> Int -> Int
-- countPalindromes a b
--   | a > b = 0
--   | otherwise = countInRange (a + 1) b
--     where helper a b
--     | a `mod` 10 /= b `mod` 10 = helper c
--     | (a `div` 10) (b `div` 10)

-- Да се дефинира функция, която чрез линейно итеративен процес намира броя на естествените делители на едно естествено число.


-- Да се дефинират следните функции:
-- incrementAllBy :: [Int] -> Int -> [Int], която получава списък и число и го добавя към всеки елемент на списъка
-- multiplyAllBy :: [Int] -> Int -> [Int], която получава списък и число и умножава всеки елемент на списъка по числото
-- filterSmallerThan , която получава списък и число и премахва елементите на списъка, които са по-малки от числото

incrementAllBy :: [Int] -> Int -> [Int]
incrementAllBy [] n = []
incrementAllBy (x:xs) n = (x + n) : incrementAllBy xs n -- or just incrementAllBy xs n = [x + n | x <- xs]

multiplyAllBy :: [Int] -> Int -> [Int]
multiplyAllBy [] n = []
multiplyAllBy (x:xs) n = (x * n) : multiplyAllBy xs n -- or just multiplyAllBy xs n = [x * n | x <- xs]

filterSmallerThan :: [Int] -> Int -> [Int]
filterSmallerThan [] n = []
filterSmallerThan (x:xs) n = if x < n then filterSmallerThan xs n else x : filterSmallerThan xs n -- or just filterSmallerThan xs n = [x | x <- xs, x > n]

-- Да се дефинира функция isAscending :: Integer -> Bool, която проверява дали цифрите на число са във възходящ ред.
-- Функцията да получава число, но да работи със списък от цифрите му.

-- toList :: Integer -> [Integer]
-- toList 0 = [0]
-- toList a = reverse (if a == 0 then [] else (a `mod` 10) : toList (a `div` 10))

toList :: Integer -> [Integer]
toList 0 = [0]
toList a = reverse (toListHelper a)
  where
    toListHelper 0 = []
    toListHelper a = (a `mod` 10) : toListHelper (a `div` 10)

isAscending :: Int -> Bool
isAscending n = isSorted (toList n)
    where
        toList n            = if n <= 0 then [] else n `mod` 10 : toList (n `div` 10)
        isSorted [x]          = True
        isSorted (x : y : xs) = if x < y then False else isSorted (y : xs)

-- Нека as = [a1, a2 ... , ak] и bs = [b1, b2 ... , bk] са непразни списъци с еднакъв брой числа.

-- Да се дефинира предикат isImage :: [Int] -> [Int] -> Bool, който да връща "истина" точно когато съществува такова число x, че ai = x + bi, ∀i = 1, ..., k.
isImage :: [Int] -> [Int] -> Bool
isImage [_] [_] = True
isImage (x1 : x2 : xs) (y1 : y2 : ys) = x1 - y1 == x2 - y2 && isImage (x2:xs) (y2:ys)

-- Да се дефинира функция chunksOf :: Int -> [a] -> [[a]], която разделя входния списък на подсписъци с дължина равна на подаденото число.
chunksOf :: Int -> [a] -> [[a]]
chunksOf n [] = []
chunksOf n xs = take n xs : chunksOf n (drop n xs)

-- Да се дефинира предикат isTriangular :: [[Int]] -> Bool, който получава квадратна числова матрица, представена като списък от списъци, и проверява
-- дали тя е горно триъгълна, т.е. дали всичките елементи под главния ѝ диагонал са нули.
isTriangular :: [[Int]] -> Bool
isTriangular []    = False
isTriangular [[_]] = True
isTriangular mat   = all (== 0) (tail (map head mat)) && isTriangular (tail (map tail mat))

-- Да се дефинира функция divisors :: Integer -> [Integer], която генерира списък от всички (собствени) делители на дадено число.
divisors :: Integer -> [Integer]
divisors n = findDivisors 1
  where
    findDivisors d
        | d >= n = []
        | n `mod` d == 0 = d : findDivisors (d + 1)
        | otherwise = findDivisors (d + 1)

-- List comprehension
-- divisors :: Integer -> [Integer]
-- divisors n = [d | d <- [1..(n - 1)], n `mod` d == 0]

-- Да се дефинира функция primesInRange :: Integer -> Integer -> [Integer], която конструира списък от простите числа в интервала [a,b]

primesInRange :: Integer -> Integer -> [Integer]
primesInRange a b
  | a > b     = []
  | isPrime a = a : primesInRange (a + 1) b
  | otherwise = primesInRange (a + 1) b

-- List comprehension
-- primesInRange :: Integer -> Integer -> [Integer]
-- primesInRange a b = [x | x <- [a..b], isPrime x]

-- Да се дефинира функция prodSumDiv :: [Integer] -> Integer -> Integer, която намира произведението на естествените числа в даден списък,
-- сумата от делителите на които е кратна на k.
prodSumDiv :: [Integer] -> Integer -> Integer
prodSumDiv xs k = product [x | x <- xs, sum (divisors x) `mod` k == 0]

-- Да се дефинира функция isSorted :: [Int] -> Bool, която проверява дали списък е сортиран във възходящ ред
isSorted :: [Int] -> Bool
isSorted [] = False
isSorted [_] = True
isSorted (x : y : xs) = if x > y then False else isSorted xs

-- isSorted xs = and [x <= y | (x, y) <- zip xs (tail xs)]

-- Да се дефинира функция merge :: [Int] -> [Int] -> [Int], която получава два сортирани списъка и ги обединява така, че резултатът също да е сортиран
-- merge :: [Int] -> [Int] -> [Int]

-- Да се дефинира функция insert :: Int -> [Int] -> [Int], която добавя елемент в сортиран списък, като резултатният списък също е сортиран
insert :: Int -> [Int] -> [Int]
insert a [] = [a]
insert a (x:xs)
  | a <= x = a : x : xs
  | otherwise = x : insert a xs

-- insert :: Int -> [Int] -> [Int] 
-- insert num [] = [num] 
-- insert num xs@(c:cs) = if c > num then num : xs else c : insert num cs

-- Да се реализира функция insertionSort :: [Int] -> [Int], която реализира сортиране чрез вмъкване върху списък
-- insertionSort :: [Int] -> [Int]
