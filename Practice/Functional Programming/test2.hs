main :: IO()
main = do
    print (findNb 1071225)         -- -> 45
    print (findNb 40539911473216)  -- -> 3568
    print (findNb 135440716410000) -- -> 4824
    print (findNb 4183059834009)   -- -> 2022
    print (findNb 91716553919377)  -- -> -1
    print (findNb 24723578342962)  -- -> -1

    print (dominates (+4) (*2) [1..4]) -- -> True
    print (dominates (+4) (*2) [1..5]) -- -> False

    print (splitPoints (1,1) 5 [(1,2),(2,3),(10,15),(-1,1),(12,14)]) -- -> ([(1.0,2.0),(2.0,3.0),(-1.0,1.0)],[(10.0,15.0),(12.0,14.0)]))

    print (isBinarySearchTree t1) -- -> True
    print (isBinarySearchTree t2) -- -> False (в дясното поддърво има стойности, помалки от тази в корена)
    print (isBinarySearchTree t3) -- -> False (лявото поддърво не е двоично дърво за търсене)

-- 1. Чрез използването на n кубове е построена сграда. Кубът, намиращ се най-отдолу, т.е. основата, е с обем n^3.
-- Кубът, който е върху него, е с обем (n-1)^3. Кубът, поставен най-отгоре, има обем 1^3. Обемът на цялата сграда е:
-- n^3 + (n-1)^3 + ... + 1^3 = m. Да се дефинира функция findNb :: Integer -> Integer, която по дадено m да връща броя кубове n,
-- необходими за построяване на сградата. Ако n не съществува, да се връща -1.

find :: Integer -> Integer -> Integer -> Integer
find n m sum 
    |sum > m   = -1
    |sum == m  = n - 1
    |otherwise = find (n + 1) m (sum + (n ^ 3)) 

findNb :: Integer -> Integer
findNb m = find 1 m 0

-- 2. Нека са дадени две едноместни целочислени функции f и g и списък от цели числа xs. Ще казваме, че функцията f доминира g
-- върху множеството xs, ако за всяко x ∈ xs е вярно, че |f(x)| ≥ |g(x)|. Да се дефинира функция
-- dominates :: (Int -> Int) -> (Int -> Int) -> [Int] -> Bool, която връща резултата от проверката дали функцията f доминира g
-- върху множеството xs.

--5 6 7 8 <-> 2 4 6 8
--5 6 7 8 9 <-> 2 4 6 8 10

compareLists :: [Int] -> [Int] -> Bool
compareLists xs ys
    |null xs           = True
    |head xs < head ys = False
    |otherwise         = compareLists (tail xs) (tail ys)

dominates :: (Int -> Int) -> (Int -> Int) -> [Int] -> Bool
dominates f g xs = compareLists (map f xs) (map g xs)

-- 3. Нека е дефиниран типът type Point = (Double,Double), представящ точка с реални координати. Да се дефинира функция
-- splitPoints :: Point -> Double -> [Point] -> ([Point],[Point]), която приема точка p, радиус r и списък от точки ps и
-- връща като резултат двойка от списъци – такава, че първият съдържа тези точки от ps, които са в кръга с център p и радиус r,
-- а вторият – всички останали точки от ps.

type Point = (Double, Double)

distance :: (Double, Double) -> Point -> Double
distance x y = sqrt ((fst x - fst y) ^ 2 + (snd x - snd y) ^ 2)

inCircle :: Point -> Double -> [Point] -> [Point]
inCircle p r ps = [point | point <- ps, (distance point p) < r]

outOfCircle :: Point -> Double -> [Point] -> [Point]
outOfCircle p r ps = [point | point <- ps, (distance point p) > r]

splitPoints :: Point -> Double -> [Point] -> ([Point], [Point])
splitPoints p r ps = (inCircle p r ps, outOfCircle p r ps)  

-- 4. Нека е дефинирано следното представяне на двоично дърво: data BTree = Empty | Node Int BTree BTree.
-- Да се дефинира функция isBinarySearchTree :: BTree -> Bool, която проверява дали подадено двоично дърво от цели числа
-- е двоично дърво за търсене. Казваме, че едно двоично дърво е двоично дърво за търсене, ако лявото му поддърво съдържа само
-- възли със стойности, по-малки от тази в корена, а дясното му поддърво - само стойности, по-големи или равни на тази в корена.
-- Освен това, трябва и самите поддървета също да са двоични дървета за търсене.

data BTree = Empty | Node Int BTree BTree

t1 :: BTree 
t1 = Node 8 (Node 3 (Node 1 Empty Empty) 
                    (Node 4 Empty Empty)) 
            (Node 10 (Node 9 Empty Empty) 
                    (Node 14 Empty Empty)) 

t2 :: BTree 
t2 = Node 8 (Node 3 (Node 1 Empty Empty) 
                    (Node 4 Empty Empty))
            (Node 8 (Node 5 Empty Empty) 
                    (Node 14 Empty Empty)) 

t3 :: BTree 
t3 = Node 8 (Node 3 (Node 5 Empty Empty) 
                    (Node 6 Empty Empty)) 
            (Node 10 (Node 9 Empty Empty) 
                    (Node 14 Empty Empty))

binarySearchTree :: BTree -> [Int]
binarySearchTree Empty                = []
binarySearchTree (Node n Empty Empty) = [n]
binarySearchTree (Node n left right)  = binarySearchTree left ++ [n] ++ binarySearchTree right

isSorted :: [Int] -> Bool
isSorted xs
    |null xs || length xs == 1 = True
    |head xs > head (tail xs)  = False
    |otherwise                 = isSorted (tail xs)

isBinarySearchTree :: BTree -> Bool
isBinarySearchTree bt = isSorted (binarySearchTree bt)