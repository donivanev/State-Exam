USE movies

-- 1. Всички филми, чието заглавие съдържа едновременно думите 'Star' и 'Trek' (не непременно в този ред). Резултатите да се
-- подредят по година (първо най-новите филми), а филмите от една и съща година - по азбучен ред

SELECT title FROM movie WHERE title LIKE '%Star%' AND title LIKE '%Trek%' ORDER BY year DESC, title

-- 2. Заглавията и годините на филмите, в които са играли звезди, родени между 1.1.1970 и 1.7.1980

SELECT movietitle, movieyear FROM starsin JOIN moviestar ON starname = name WHERE birthdate BETWEEN '1.1.1970' AND '1.7.1980'

USE pc

-- 1. Компютрите, които са по-евтини от всеки лаптоп на същия производител

SELECT DISTINCT(pc.model) FROM pc JOIN product ON pc.model = product.model 
WHERE price < ALL(SELECT price FROM laptop WHERE maker = product.maker)

-- 2. Компютрите, които са по-евтини от всеки лаптоп и принтер на същия производител

SELECT DISTINCT(pc.model) FROM pc JOIN product ON pc.model = product.model 
WHERE price < ALL(SELECT price FROM laptop WHERE maker = product.maker) AND
price < ALL(SELECT price FROM printer WHERE maker = product.maker)

USE ships

-- 1. Имената и годините на пускане на всички кораби, които имат същото име като своя клас

SELECT name, launched FROM ships WHERE name = class

-- 2. Имената на всички кораби, за които едновременно са изпълнени следните условия: (1) участвали са в поне една битка и
-- (2) имената им (на корабите) започват с C или K

SELECT DISTINCT ship FROM outcomes WHERE (ship LIKE 'C%' OR ship LIKE 'K%') AND battle IN (SELECT battle from outcomes)

-- 3. Всички държави, които имат потънали в битка кораби

SELECT DISTINCT country FROM classes JOIN ships ON classes.class = ships.class JOIN outcomes ON name = ship
WHERE result = 'sunk'

-- 4. Всички държави, които нямат нито един потънал кораб

SELECT DISTINCT country FROM classes JOIN ships ON classes.class = ships.class JOIN outcomes ON name = ship
WHERE result <> 'sunk'

-- 5. (От държавен изпит) Имената на класовете, за които няма кораб, пуснат на вода (launched) след 1921 г.
-- Ако за класа няма пуснат никакъв кораб, той също трябва да излезе в резултата

SELECT DISTINCT classes.class FROM classes LEFT JOIN ships ON classes.class = ships.class AND launched > 1921
WHERE name IS NULL

-- 6. Името, държавата и калибъра (bore) на всички класове кораби с 6, 8 или 10 оръдия. Калибърът да се изведе в сантиметри (1 инч ~ 2.54 см)

SELECT name, country, bore * 2.54 FROM ships JOIN classes ON ships.class = classes.class
WHERE bore = 6 OR bore = 8 OR bore = 10

-- 7. Държавите, които имат класове с различен калибър (напр. САЩ имат клас с 14 калибър и класове с 16 калибър, докато
-- Великобритания има само класове с 15)

SELECT country FROM classes c WHERE bore NOT IN (SELECT bore FROM classes WHERE country = c.country)

-- 8. Страните, които произвеждат кораби с най-голям брой оръдия (numguns)

SELECT country FROM classes WHERE numguns > ALL(SELECT numguns FROM classes)