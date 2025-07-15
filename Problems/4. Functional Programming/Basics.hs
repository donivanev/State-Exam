----- Основни понятия -----

Литерал - True, False, число, знак
Дефинициите на основните вградени функции се съдържат в стандартната прелюдия (Prelude.hs)
Додефиниране на оператор (overloading) - използване на едно и също име за означаване на различни операции

Предефиниране на множество от функции (изключване на вградените в езика функции)
import Prelude hiding (max, min)

-- Дефиниране на модули

module Aut where

module Bee where
import Aut

----- Типове -----

Цяло число - Int, Integer
Реално число - Float, Double, Rational
Булев - True, False
Знак - 'a'

----- Оператори -----

Аритметични (цели числа)
    • +, -, *, div, mod, ^, abs, negate
Аритметични (реални числа)
    • +, -, *, /, ^, **, signum, sqrt
    • ceiling (float to int), floor (float to int), round (float to int), fromIntegral (int to float)
Булеви
    • &&, ||, not
Сравнения
    • ==, /=, >, >=, <, <=

mod и div могат да се използват по два начина:
    • Инфиксно: a `mod` 10
    • Префиксно: mod a 10

----- Дефиниране на променливи -----

var :: type
var = expression

----- Дефиниране на функции -----

-- име на функция (func), типове аргументи (t1...tk), тип на резултата (t)
-- име на функция (func), формални параметри/образци (x1...xk), тяло на функцията (e)
func :: t1 -> t2 -> ... -> tk -> t
func x1 x2 ... xk = e

square :: Int -> Int
square n = n * n

average :: Float -> Float -> Float
average x y = (x + y) / 2

example :: Int
example = double (size - square (2 + 2))

exOr :: Bool -> Bool -> Bool
exOr x y = (x || y) && not (x && y)

-- ord :: Char -> Int
offset :: Int
offset = ord 'A' - ord 'a'

-- chr :: Int -> Char
toUpper :: Char -> Char
toUpper ch = chr (ord ch + offset)

----- Условия -----

-- g1, g2, ... са условия; клаузата otherwise не е задължителна
func x1 x2 ... xk
 | g1        = e1
 | g2        = g2
 ...
 | otherwise = e

max :: Int -> Int -> Int
max x y
 | x >= y = x
 | otherwise = y

fact :: Int -> Int
fact n
 | n == 0 = 1
 | n > 0 = fact (n - 1) * n

----- Условни изрази -----

-- if condition then m else n
max :: Int -> Int -> Int
max x y = if x >= y then x else y

----- Други -----

Символът @ в Haskell се нарича "as-pattern" и се използва в pattern matching, за да може едновременно:
    Да се разглоби стойност (например списък или кортеж)
    Но и да се запази цялата под дадено име

describeList :: [Int] -> String
describeList [] = "Празен списък"
describeList lst@(x:xs) = "Първи елемент: " ++ show x ++ ", останалите: " ++ show xs ++ ", целият списък: " ++ show lst