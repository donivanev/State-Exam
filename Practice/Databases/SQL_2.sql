USE movies

-- 1. Напишете заявка, която извежда имената на актрисите, участвали в Terms of Endearment

SELECT name FROM moviestar JOIN starsin ON name = starname WHERE gender = 'F' AND movietitle = 'Terms of Endearment'

-- 2. Напишете заявка, която извежда имената на филмовите звезди, участвали във филми на студио MGM през 1995 г.

SELECT starname FROM starsin JOIN movie ON movietitle = title WHERE studioname = 'MGM' AND movieyear = '1995'

USE pc

-- 1. Напишете заявка, която извежда производителя и честотата на процесора на лаптопите с размер на харддиска поне 9 GB

SELECT maker, speed FROM laptop JOIN product ON laptop.model = product.model WHERE hd >= 9

-- 2. Напишете заявка, която извежда номер на модел и цена на всички продукти, произведени от производител с име "B".
-- Сортирайте резултата така, че първо да се изведат най-скъпите продукти

SELECT product.model, price FROM product JOIN pc ON product.model = pc.model WHERE maker = 'B'
UNION
SELECT product.model, price FROM product JOIN laptop ON product.model = laptop.model WHERE maker = 'B'
UNION
SELECT product.model, price FROM product JOIN printer ON product.model = printer.model WHERE maker = 'B'
ORDER BY price DESC

-- 3. Напишете заявка, която извежда размерите на тези харддискове, които се предлагат в поне два компютъра

SELECT p1.hd FROM pc p1 JOIN pc p2 ON p1.hd = p2.hd AND p1.code <> p2.code

-- 4. Напишете заявка, която извежда всички двойки модели на компютри, които имат еднаква честота на процесора и памет.
-- Двойките трябва да се показват само по веднъж, например ако вече е изведена двойката (i, j), не трябва да се извежда (j, i)

SELECT DISTINCT p1.model, p2.model FROM pc p1 JOIN pc p2 ON p1.speed = p2.speed AND p1.ram = p2.ram 
WHERE p1.model < p2.model

-- 5. Напишете заявка, която извежда производителите на поне два различни компютъра с честота на процесора поне 1000 MHz

SELECT maker FROM product JOIN pc ON product.model = pc.model JOIN pc p2 ON pc.code = p2.code 
WHERE pc.code <> p2.code AND pc.speed > 1000

USE ships

-- 1. Напишете заявка, която извежда името на корабите, по-тежки (displacement) от 35000

SELECT name FROM ships JOIN classes ON ships.class = classes.class WHERE displacement > 35000

-- 2. Напишете заявка, която извежда имената, водоизместимостта и броя оръдия на всички кораби, участвали в битката при Guadalcanal

SELECT name, displacement, numguns FROM outcomes JOIN ships ON ship = ships.name JOIN classes ON ships.class = classes.class
WHERE battle = 'Guadalcanal'

-- 3. Напишете заявка, която извежда имената на тези държави, които имат класове кораби от тип "bb" и "bc" едновременно

SELECT DISTINCT classes.country FROM classes JOIN classes c2 ON classes.class = c2.class WHERE classes.type = 'bb'
INTERSECT 
SELECT DISTINCT classes.country FROM classes JOIN classes c2 ON classes.class = c2.class WHERE classes.type = 'bc'

-- 4. Напишете заявка, която извежда имената на тези кораби, които са били повредени в една битка, но по-късно са участвали в друга

--SELECT ship FROM outcomes JOIN battles ON battle = name WHERE result = 'damaged'

SELECT DISTINCT o1.ship FROM outcomes o1 JOIN battles b1 ON o1.battle = b1.name JOIN outcomes o2 ON o1.ship = o2.ship
JOIN battles b2 ON o2.battle = b2.name WHERE o1.result = 'damaged' AND b1.date < b2.date