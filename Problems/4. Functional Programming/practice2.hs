main :: IO()
main = do
    print (Rectangle 10 15)
    print (perimeter (Triangle 10 15 20))
    print (area (Rectangle 10 15))
    print (isRound (Circle 5))
    print (sumArea [(Triangle 1 2 3), (Circle 5)])
    print (biggestShape [(Triangle 10 15 20), (Circle 5), (Rectangle 10 15)])

    print (Point2D 2 3)
    -- print (areEqual (Point2D 2 3) (Point2D 1 4))
    -- print (areEqual (Point3D 2 3 5) (Point3D 1 4 7))

    print (size t1)
    print (height t1)
    print (sumTree t1)

-- Да се дефинира тип Shape с 3 конструктора: 
-- Circle,        който има 1 аргумент  - радиус
-- Rectangle, който има 2 аргумента - ширина и височина
-- Triangle,    който има 3 аргумента - 3 страни
-- Нека Shape да е екземпляр на класа Show и за него да се дефинира метода show.

-- За Shape да се дефинират:
-- a) функция perimeter :: Shape -> Double, която намира периметъра на фигурата
-- b) функция area :: Shape -> Double, която намира лицето на фигурата
-- c) предикат isRound :: Shape -> Bool, който проверява дали дадена фигура е кръгла

-- Да се дефинира функция sumArea, която приема списък от фигури и връща сумата от лицата на фигурите в списъка. 
-- Да се дефинира още една функция biggestShape, която намира фигурата с най-голямо лице.

data Shape = Circle Double | Rectangle Double Double | Triangle Double Double Double deriving Show

perimeter :: Shape -> Double
perimeter (Circle r) = 2 * 3.14 * r
perimeter (Rectangle a b) = 2 * a + 2 * b
perimeter (Triangle a b c) = a + b + c

area :: Shape -> Double
area (Circle r) = 3.14 * r * r
area (Rectangle a b) = a * b
area (Triangle a b c) = sqrt (p * (p - a) * (p - b) * (p - c)) where p = (a + b + c) / 2

isRound :: Shape -> Bool
isRound (Circle _) = True
isRound _ = False

sumArea :: [Shape] -> Double 
sumArea shapes = sum (map area shapes)

biggestShape :: [Shape] -> Shape
biggestShape shapes = foldl1 (\shape1 shape2 -> if area shape1 > area shape2 then shape1 else shape2) shapes

-- Да се дефинира тип Point, който задава точка в равнината и точка в пространството. 
-- Нека да е екземпляр на класа Eq и за него да се дефинира равенство на точки от една и съща размерност.

-- Да се дефинира функция distance за работа с типа, която намира разстоянието между две (съвместими) точки. 
-- Ако точките са с различна размерност (т.е имат различен брой координати) функцията да връща съобщение за грешка.

-- Да се дефинира функция getClosestPoint, която приема списък от точки и още една точка p. 
-- Като резултат функцията да връща тази точка от списъка, която е най-близо до точката p.

data Point = Point2D Double Double | Point3D Double Double Double deriving (Eq, Show)

-- areEqual :: Point -> Point -> Bool
-- areEqual p1 p2 = p1 == p2

-- distance :: Point -> Point -> Double
-- distance

-- getClosestPoint :: [Point] -> Point -> Point

-- Да се дефинират рекурсивен алгебричен тип двоично дърво (BTree) и следните функции:
-- a) функция size, която намира броя на елементите на двоично дърво
-- b) функция height, която намира височината на двоично дърво
-- c) функция sumTree, която намира сумата от елементите на двоично дърво
-- d) функция sumLeaves, която намира сумата елементите по листата на двоично дърво
-- e) функция inorder, която обхожда двоично дърво в ред Ляво-Корен-Дясно

data BTree = Empty | Node Int BTree BTree deriving Show

-- Примери:
t1 :: BTree                                        --    5
t1 = Node 5 (Node 2 Empty                          --   / \
                        (Node 3 Empty Empty))      --  2   6
            (Node 6 Empty Empty)                   --   \
                                                   --    3 
                                          
t2 :: BTree                                         --    5
t2 = Node 5 (Node 3 Empty Empty)                    --   / \
                (Node 4 (Node 5 Empty Empty)        --  3   4
                            (Node 7 Empty Empty))   --     /  \
                                                    --    5    7

size :: BTree -> Int
size Empty = 0
size (Node _ leftChild rightChild) = 1 + size leftChild + size rightChild

height :: BTree -> Int
height Empty = 0
height (Node _ leftChild rightChild) = 1 + max (height leftChild) (height rightChild)

sumTree :: BTree -> Int
sumTree Empty = 0
sumTree (Node value leftChild rightChild) = value + sumTree leftChild + sumTree rightChild

sumLeaves :: BTree -> Int
sumLeaves Empty = 0
sumLeaves (Node value leftChild rightChild) = value
sumLeaves (Node _ leftChild rightChild) = sumLeaves leftChild + sumLeaves rightChild

-- inroder :: BTree -> [Int]
-- inroder

-- Да се дефинира функция getLevel :: Int -> BTree -> [Int], която намира елементите на k-то ниво на двоично дърво.
-- getLevel :: Int -> BTree -> [Int]

-- Да се дефинира функция average :: BTree -> Double, която пресмята средно-аритметичното от записаното във върховете на двоично дърво.
-- average :: BTree -> Double
-- average Empty = 0
-- average (Node data leftChild rightChild) = data + average leftChild + average rightChild

-- Да се дефинира функция mirrorTree :: BTree -> BTree, която преобразува дърво в "огледалното" му.
-- mirrorTree :: BTree -> BTree

-- Пример:
--      1                 1
--     /  \              /  \
--    2    3      =>    3    2
--   /    /  \         /  \    \
--  5    7    6       6    7    5