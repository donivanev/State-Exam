-- Алгебрични типове

data Day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday | Sunday

-- Изброени типове (разновидност на алгебричен тип)

data Season = Spring | Summer | Autumn | Winter

-- Производни типове

data People = Person Name Age
type Name = String
type Age = Int

-- Алтернативи

data Shape = Circle Float | Rectangle Float Float

area :: Shape -> Float
area (Circle r) = pi * r * r
area (Rectangle h w) = h * w

-- Производни екземпляри на класове

data Season = Spring | Summer | Autumn | Winter deriving (Eq,Ord,Enum,Show,Read)
data Shape = Circle Float | Rectangle Float Float deriving (Eq,Ord,Show,Read)

-- Рекурсивни алгебрични типове

data NTree = NilT | Node Int NTree NTree -- дърво с елементи цели числа, NilT е празното дърво
data Tree a = Nil | Node a (Tree a) (Tree a) deriving (Eq,Ord,Show,Read) -- дърво с елементи от произволен тип

depth :: Tree a -> Int
depth Nil = 0
depth (Node n t1 t2) = 1 + max (depth t1) (depth t2)

numberOfElements :: Tree a -> Int
numberOfElements Nil = 0
numberOfElements (Node _ leftTree rightTree) = 1 + numberOfElements leftTree + numberOfElements rightTree

sumOfElements :: Tree Int -> Int
sumOfElements Nil = 0
sumOfElements (Node n leftTree rightTree) = n + sumOfElements leftTree + sumOfElements rightTree

countLeaves :: Tree a -> Int
countLeaves Nil = 0
countLeaves (Node _ Nil Nil) = 1
countLeaves (Node _ leftTree rightTree) = countLeaves leftTree + countLeaves rightTree

-- Прилагане на дадена функция към всеки от върховете на дървото
mapTree :: (a -> b) -> Tree a -> Tree b
mapTree f Nil = Nil
mapTree f (Node x tl t2) = Node (f x) (mapTree f tl) (mapTree f t2)

-- Взаимно рекурсивни типове

data Person = Adult Name Address Biog | Child Name
data Biog = Parent String [Person] | NonParent String

showPerson (Adult nm ad bio) = show nm ++ show ad ++ showBiog bio
showBiog (Parent st parList) = st ++ concat (map showPerson parList)

-- Полиморфни алгебрични типове

equalPair :: Eq a => Pairs a -> Bool
equalPair (Pr x y) = (x == y)