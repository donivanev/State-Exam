USE pc

-- 1. Напишете заявка, която извежда средната честота на процесорите на компютрите

SELECT AVG(speed) FROM pc

-- 2. Напишете заявка, която за всеки производител извежда средния размер на екраните на неговите лаптопи

SELECT maker, AVG(screen) FROM product JOIN laptop ON product.model = laptop.model GROUP BY maker

-- 3. Напишете заявка, която извежда средната честота на лаптопите с цена над 1000

SELECT AVG(speed) FROM laptop WHERE price > 1000

-- 4. Напишете заявка, която извежда средната цена на компютрите, произведени от производител "A"

SELECT AVG(price) FROM pc JOIN product ON pc.model = product.model WHERE maker = 'A'

-- 5. Напишете заявка, която извежда средната цена на компютрите и лаптопите на производител "B" (едно число)

SELECT AVG(price) FROM (SELECT price FROM product p JOIN pc ON p.model = pc.model WHERE maker = 'B'
UNION ALL SELECT price FROM product p JOIN laptop l ON p.model = l.model WHERE maker = 'B') AllPrices

-- 6. Напишете заявка, която извежда средната цена на компютрите според различните им честоти на процесорите

SELECT speed, AVG(price) FROM pc GROUP BY speed

-- 7. Напишете заявка, която извежда производителите, които са произвели поне по 3 различни модела компютъра

SELECT maker FROM product JOIN pc ON product.model = pc.model GROUP BY maker HAVING 
COUNT(pc.model) > 3

-- 8. Напишете заявка, която извежда производителите на компютрите с най-висока цена

SELECT DISTINCT maker FROM product JOIN pc ON product.model = pc.model WHERE price = (SELECT MAX(price) FROM pc)

-- 9. Напишете заявка, която извежда средната цена на компютрите за всяка честота, по-голяма от 800 MHz

SELECT speed, AVG(price) FROM pc WHERE speed > 800 GROUP BY speed

-- 10. Напишете заявка, която извежда средния размер на диска на тези компютри, произведени от производители,
-- които произвеждат и принтери

SELECT AVG(hd) FROM pc JOIN product ON pc.model = product.model WHERE product.maker IN
(SELECT maker FROM product WHERE type = 'printer')

-- 11. Напишете заявка, която за всеки размер на лаптоп намира разликата в цената на най-скъпия и
-- най-евтиния лаптоп със същия размер

SELECT screen, MAX(price) - MIN(price) FROM laptop GROUP BY screen

USE ships;

-- 1. Напишете заявка, която извежда броя на класовете кораби

SELECT COUNT(class) FROM classes

-- 2. Напишете заявка, която извежда средния брой на оръдията (numguns) за всички кораби, пуснати на вода
-- (т.е. изброени са в таблицата Ships)

SELECT AVG(numguns) FROM classes WHERE class in (SELECT class FROM ships)

-- 3. Напишете заявка, която извежда за всеки клас първата и последната година, в която кораб от съответния клас е пуснат на вода

SELECT MIN(launched) as FirstYear, MAX(launched) as LastYear FROM ships 
JOIN classes ON ships.class = classes.class GROUP BY classes.class

-- 4. Напишете заявка, която за всеки клас извежда броя на корабите, потънали в битка

SELECT classes.class, COUNT(ship) FROM classes JOIN ships ON classes.class = ships.class 
JOIN outcomes ON name = ship WHERE result = 'sunk' GROUP BY classes.class

-- 5. Напишете заявка, която за всеки клас с над 4 пуснати на вода кораба извежда броя на корабите, потънали в битка

SELECT classes.class, COUNT(ship) FROM classes JOIN ships ON classes.class = ships.class 
JOIN outcomes ON name = ship WHERE result = 'sunk' GROUP BY classes.class HAVING COUNT(launched) > 4

-- 6. Напишете заявка, която извежда средното тегло на корабите (displacement) за всяка страна

SELECT country, AVG(displacement) FROM classes GROUP BY country

USE movies

-- 1. За всеки актьор/актриса изведете броя на различните студиа, с които са записвали филми. Включете и тези, за които
-- няма информация в кои филми са играли

SELECT starname, COUNT(studioname) FROM starsin JOIN movie ON movietitle = title AND movieyear = year GROUP BY starname

-- 2. Изведете имената на актьорите, участвали в поне 3 филма след 1990 г.

SELECT starname FROM starsin WHERE movieyear > 1990 GROUP BY starname HAVING COUNT(movietitle) > 3

-- 3. Да се изведат различните модели компютри, подредени по цена на най-скъпия конкретен компютър от даден модел

USE pc

SELECT model FROM pc GROUP BY model ORDER BY MAX(price)

USE ships

-- 1. Намерете броя на потъналите американски кораби за всяка проведена битка с поне един потънал американски кораб



-- 2. Битките, в които са участвали поне 3 кораба на една и съща страна



-- 3. Имената на класовете, за които няма кораб, пуснат на вода след 1921 г., но имат пуснат поне един кораб



-- 4. (*) За всеки кораб броя на битките, в които е бил увреден (result = "damaged"). Ако корабът не е участвал в битки или
-- пък никога не е бил увреждан, в резултата да се вписва 0



-- 5. (*) Намерете за всеки клас с поне 3 кораба броя на корабите от този клас, които са победили в битка (result = 'ok')



-- 6. За всяка битка да се изведе името на битката, годината на битката и броят на потъналите кораби, броят на повредените
-- кораби и броят на корабите без промяна



-- 7. (*) Намерете имената на битките, в които са участвали поне 3 кораба с под 9 оръдия и от тях поне два са с резултат 'ok'