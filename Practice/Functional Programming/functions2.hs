main :: IO()
main = do
    print (chunksOf 2 [1, 3, 4, 6, 7, 8])
    print (divisors 21)
    print (isSorted [4, 8, 14])
    print (merge [1, 3, 7] [6, 9, 45])
    print (insert 5 [1, 4, 9])
    print (insertionSort' [7, 8, 3, 2, 0])

-- Нека as = [a1, a2 … , ak] и bs = [b1, b2 … , bk] са непразни списъци с еднакъв брой числа. Да се дефинира предикат
-- isImage :: [Int] -> [Int] -> Bool, който да връща „истина“ точно когато съществува такова число x, че ai = x + bi за всяко
-- i = 1,..., k.

isImage :: [Int] -> [Int] -> Bool
isImage [_] [_]               = True
isImage (a1:a2:as) (b1:b2:bs) = a1 - b1 == a2 - b2 && isImage (a2:as) (b2:bs)

isImage' (a1 : as) (b1 : bs) = and (map (\ (a, b) -> a - b == a1 - b1) (zip as bs))

-- Да се дефинира функция chunksOf :: Int -> [a] -> [[a]], която разделя входния списък на подсписъци с дължина равна на подаденото число.

chunksOf :: Int -> [a] -> [[a]]
chunksOf n [] = []
chunksOf n xs = take n xs : chunksOf n (drop n xs)

-- Да се дефинира предикат isTriangular :: [[Int]] -> Bool, който получава квадратна числова матрица, представена като списък от
-- списъци, и проверява дали тя е горно триъгълна, т.е. дали всичките елементи под главния ѝ диагонал са нули.

isTriangular :: [[Int]] -> Bool
isTriangular []    = False 
isTriangular [[_]] = True
isTriangular mat   = all (== 0) (tail (map head mat)) && isTriangular (tail (map tail mat))

-- Да се дефинира функция divisors :: Integer -> [Integer], която генерира списък от всички (собствени) делители на дадено число.

divisors :: Int -> [Int]
divisors n = [d | d <- [1..(n-1)], mod n d == 0]

-- Да се дефинира функция primesInRange :: Integer -> Integer -> [Integer],. която конструира списък от простите числа в интервала [a,b]

isPrime :: Integer -> Bool 
isPrime n = [1, n] == [d | d <- [1..(n-1)], mod n d == 0]

isPrime' :: Integer -> Bool 
isPrime' x = helper 1 0
    where
        helper n i
            |n < 2         = False   
            |mod n i == 0  = True
            |otherwise     = helper n (i + 1)

primesInRange :: Integer -> Integer -> [Integer]
primesInRange a b = [x | x <- [a..b], isPrime x]

primesInRange' :: Integer -> Integer -> [Integer]
primesInRange' a b = [x | x <- [a..b], prime x 2]
    where 
        prime x i
            |i >= x       = True
            |mod x i == 0 = False
            |otherwise    = prime x (i + 1)

divideBy3And7 :: Integer -> [Integer]
divideBy3And7 n = [n | n <- [1..n], mod n 3 == 0 && mod n 7 == 0]

-- Да се дефинира функция prodSumDiv :: [Integer] -> Integer -> Integer, която намира произведението на естествените числа в
-- даден списък, сумата от делителите на които е кратна на k.

prodSumDiv :: [Int] -> Int -> Int
prodSumDiv xs k = product [x | x <- xs , mod (sum (divisors x)) k == 0]

-- Да се дефинира функция isSorted :: [Int] -> Bool, която проверява дали списък е сортиран във възходящ ред

isSorted :: [Int] -> Bool 
isSorted [] = True 
isSorted [x] = True 
isSorted [x1, x2] = x1 <= x2 
isSorted (x1 : x2 : xs) = x1 <= x2 && isSorted (x2 : xs)

isSorted' xs = all (\ (a, b) -> a <= b) (zip xs (tail xs))

-- Да се дефинира функция merge :: [Int] -> [Int] -> [Int], която получава два сортирани списъка и ги обединява така, че резултатът също да е сортиран

merge :: [Int] -> [Int] -> [Int] 
merge as [] = as 
merge [] bs = bs
merge (a : as) (b : bs) = if a <= b then a : merge as (b : bs) else b : merge (a : as) bs

-- Да се дефинира функция insert :: Int -> [Int] -> [Int], която добавя елемент в сортиран списък, като резултатният списък също е сортиран

insert :: Int -> [Int] -> [Int] 
insert num [] = [num] 
insert num xs@(c:cs) = if c > num then num : xs else c : insert num cs

-- Да се реализира функция insertionSort :: [Int] -> [Int], която реализира сортиране чрез вмъкване върху списък

insertionSort :: [Int] -> [Int] 
insertionSort cs = helper [] cs 
    where 
        helper result [] = result 
        helper result (c:cs) = helper (insert c result) cs

insertionSort' :: [Int] -> [Int]
insertionSort' xs = foldr insert [] xs

insertionSort'' :: [Int] -> [Int]
insertionSort'' = foldr insert []

-- ____________________________________________

main :: IO()
main = do
    print ""
    print (Rectangle 10 15)

-- Да се дефинира тип Shape с 3 конструктора: Circle с 1 аргумент - радиус
--                                            Rectangle с 2 аргумента - ширина и височина
--                                            Triangle с 3 аргумента - 3 страни
-- Нека Shape да е екземпляр на класа Show и за него да се дефинира метода show.

data Shape = Circle Double |
             Rectangle Double Double |
             Triangle Double Double Double 
              deriving Show

--instance Show Shape where 
--  show (Triangle a b c) = show (a, b, c)
 --   show (Rectangle a b) = "Rectangle with sides" ++ show a ++ " i " ++ show b

-- За Shape да се дефинират:
-- функция perimeter :: Shape -> Double, която намира периметъра на фигурата

a :: [Shape]
a = Circle 10 : [Rectangle 10 21]

perimeter :: Shape -> Double
perimeter (Circle r) = 3.14 * r * 2
perimeter (Rectangle a b) = 2 * (a + b)
perimeter (Triangle a b c) = a + b + c

-- функция area :: Shape -> Double, която намира лицето на фигурата

area :: Shape -> Double 
area (Circle r)       = pi * r * r 
area (Rectangle a b)  = a * b 
area (Triangle a b c) = sqrt (p * (p - a) * (p - b) * (p - c)) 
    where p = (a + b + c) / 2

-- предикат isRound :: Shape -> Bool, който проверява дали дадена фигура е кръгла

isRound :: Shape -> Bool 
isRound (Circle _) = True 
isRound _          = False

-- Да се дефинира функция sumArea, която приема списък от фигури и връща сумата от лицата на фигурите в списъка. 

sumArea :: [Shape] -> Double 
sumArea shapes = sum (map area shapes)

-- Да се дефинира функция biggestShape, която намира фигурата с най-голямо лице.

biggestShape :: [Shape] -> Shape
biggestShape []     = error "Empty list"
biggestShape shapes = foldl1 (\ u v -> if area u > area v then u else v) shapes

-- Да се дефинира тип Point, който задава точка в равнината и точка в пространството.
-- Нека да е екземпляр на класа Eq и за него да се дефинира равенство на точки от една и съща размерност.

data Point = Point2D Double Double | Point3D Double Double Double
    deriving (Eq, Show)

-- Да се дефинира функция distance за работа с типа, която намира разстоянието между две (съвместими) точки.
-- Ако точките са с различна размерност (т.е имат различен брой координати) функцията да връща съобщение за грешка.

distance :: Point -> Point -> Double 
distance (Point2D x1 y1) (Point2D x2 y2)       = sqrt ((x1-x2) * (x1-x2) + (y1 - y2) * (y1 - y2)) 
distance (Point3D x1 y1 z1) (Point3D x2 y2 z2) = sqrt ((x1-x2) * (x1-x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
distance _ _ = error "Not compatible"