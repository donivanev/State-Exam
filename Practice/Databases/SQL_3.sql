USE movies
SELECT * FROM movieexec
SELECT * FROM moviestar

-- 1. Напишете заявка, която извежда имената на актрисите, които са също и продуценти с нетна стойност, по-голяма от 10 милиона

SELECT name FROM movieexec WHERE name IN (SELECT name FROM moviestar) AND networth > 10000000

-- 2. Напишете заявка, която извежда имената на тези филмови звезди, които не са продуценти

SELECT name FROM moviestar WHERE name NOT IN (SELECT name FROM movieexec)

USE pc

-- 1. Напишете заявка, която извежда производителите на персонални компютри с честота на процесора поне 500 MHz

SELECT DISTINCT maker FROM product JOIN pc ON product.model = pc.model AND speed >= 500

-- 2. Напишете заявка, която извежда лаптопите, чиято честота на CPU е по-ниска от честотата на който и да е персонален компютър

SELECT model FROM laptop WHERE speed < ALL(SELECT speed FROM pc)

-- 3. Напишете заявка, която извежда модела на продукта (PC, лаптоп или принтер) с най-висока цена

SELECT model FROM pc
UNION ALL
SELECT model FROM laptop
UNION ALL
SELECT model FROM printer

-- 4. Напишете заявка, която извежда производителите на цветните принтери с най-ниска цена

SELECT maker FROM product WHERE model IN (SELECT model FROM printer WHERE color = 'y' 
AND price <= ALL(SELECT price FROM printer WHERE color = 'y'))

-- 5. Напишете заявка, която извежда производителите на тези персонални компютри с най-малко RAM памет, които имат най-бързи процесори

-- SELECT maker FROM product WHERE model IN (SELECT ram FROM pc WHERE )

USE ships

-- 1. Напишете заявка, която извежда страните, чиито класове кораби са с най-голям брой оръдия



-- 2. Напишете заявка, която извежда имената на корабите с 16-инчови оръдия (bore)



-- 3. Напишете заявка, която извежда имената на битките, в които са участвали кораби от клас "Kongo"



-- 4. Напишете заявка, която извежда имената на корабите, чиито брой оръдия е най-голям в сравнение с корабите със същия
-- калибър оръдия (bore)

