USE movies

-- 07.09.2022
-- 1) Да се напише заявка, която извежда заглавията и дължините в минути на всички цветни филми без най-дългия цветен и
-- без тези с неизвестна дължина. Ако има няколко филма с максимална дължина,нито един от тях не трябва да бъде изведен.

-- I
SELECT title, length FROM movie WHERE incolor = 'Y' AND length IS NOT NULL AND length <>
(SELECT MAX(length) FROM movie WHERE incolor = 'Y')

-- IS NULL, IS NOT NULL
-- >, <, <>, =, != ..... NULL (UNKNOWN)
-- TRUE 2 > 1
-- FALSE 2 < 1
-- UNKNOWN 2 < NULL

-- II
SELECT title, length FROM movie WHERE incolor = 'Y' AND length < (SELECT MAX(length) FROM movie WHERE incolor = 'Y')

-- III
SELECT title, length FROM movie WHERE incolor = 'Y' AND length IS NOT NULL
EXCEPT -- EXCEPT ALL
SELECT title, length FROM movie WHERE incolor = 'Y' AND length = (SELECT MAX(length) FROM movie WHERE incolor = 'Y')

-- UNION , UNION ALL
-- INTERSECT, INTERSECT ALL
-- EXCEPT, EXCEPT ALL
--- GROUP BY COL1, SELECT COL1, + AVG, MIN, MAX, COUNT...

-- 2) Да се посочи коя от следните заявки извежда имената на тези студиа, които нямат филми или са снимали филми само в една
-- единствена година:

-- FROM T1 INNER JOIN T2 ON T1.COL1=T2.COL1;
-- FROM T1 JOIN T2 ON T1.COL1=T2.COL1;
-- FROM T1, T2 WHERE T1.COL1=T2.COL1;

-- FROM T1 LEFT OUTER JOIN T2 ON T1.COL1 = T2.COL1;
-- FROM T1 LEFT JOIN T2 ON T1.COL1 = T2.COL1;
-- FROM T1 RIGHT OUTER JOIN T2 ON T1.COL1 = T2.COL1;
-- FROM T1 FULL OUTER JOIN T2 ON T1.COL1 = T2.COL1;

SELECT name, title, year FROM studio LEFT JOIN movie ON name = studioName WHERE title IS NULL

-- В)
SELECT name, COUNT(DISTINCT year) FROM studio LEFT JOIN movie ON name = studioName GROUP BY name HAVING COUNT(DISTINCT year) <= 1

-- 12.07.2022
-- 1) Да се попълнят празните места в следната заявка така, че тя да извежда името на студиото на филма The Usual Suspects и
-- заглавията на всички филми на същото студио:

SELECT s.name, m.title FROM movie m JOIN studio s ON m.studioname = s.name WHERE s.name IN
(SELECT studioname FROM movie WHERE title = 'The Usual Suspects' AND year = 1995)

-- 2) Да се посочи коя от следните заявки извежда имената на филмовите звезди, за които няма информация в кои филми са играли

-- Б)
SELECT ms.name, si.movietitle FROM moviestar ms LEFT JOIN starsin si ON ms.name = si.starname WHERE si.movietitle IS NULL

-- II
SELECT name FROM moviestar
EXCEPT --ALL
SELECT starname FROM starsin

-- 08.09.2021

-- 1) - В)
SELECT studioname FROM movie WHERE incolor = 'Y'
INTERSECT
SELECT studioname FROM movie WHERE length IS NULL

-- 2) - Б)
SELECT name, COUNT(title) FROM moviestar LEFT JOIN starsin ON name = starname LEFT JOIN movie ON movietitle = title
AND movieyear = year AND incolor = 'N' WHERE gender = 'F' GROUP BY name

-- 13.07.2021

USE pc

-- 1) - A)
SELECT code, price FROM laptop WHERE screen BETWEEN 13 AND 15 AND ram IN (SELECT ram FROM PC)

-- 2) - В)
SELECT maker, COUNT(code) FROM laptop RIGHT JOIN product ON laptop.model = product.model AND screen = 15 GROUP BY maker

-- 16.09.2020

USE movies;
-- 1) Да се напише заявка, която извежда имената и адресите на всички студиа, които имат поне един цветен и поне един черно-бял
-- филм. Резултатът да се сортира възходящо по адрес.
-- I
SELECT s.name, s.address FROM studio s, movie m WHERE s.name = m.studioname AND m.incolor = 'Y'
INTERSECT
SELECT s.name, s.address FROM studio s, movie m WHERE s.name = m.studioname AND m.incolor = 'N'
ORDER BY 2

-- II
SELECT DISTINCT s.name, s.address FROM studio s, movie m WHERE s.name = m.studioname AND m.incolor = 'Y' AND NAME IN
(SELECT studioname FROM movie WHERE incolor = 'N')

-- 2) Да се напише заявка, която за всяко студио с най-много три филма извежда:
--      • името му;
--      • адреса;
--      • средната дължина на филмите на това студио.
-- Студиа без филми също да се изведат (за средна дължина да се извежда null или 0).
SELECT s.name, s.address, AVG(length) AS avg_len, COUNT(title) AS cnt FROM studio s LEFT JOIN movie M ON s.name = m.studioname
GROUP BY s.name, s.address HAVING COUNT(title) <= 3

-- 05.08.2020
-- 1) Да се напише заявка, която извежда имената и рождените дати на всички филмови звезди, чието име не съдържа "Jr." и са играли в
-- поне един цветен филм. Първо да се изведат най-младите звезди, а звезди, родени на една и съща дата, да се изведат по азбучен ред.
SELECT ms.name, ms.birthdate FROM moviestar ms, starsin si, movie m WHERE ms.name = si.starname AND si.movietitle = m.title
AND si.movieyear = m.year AND ms.name NOT LIKE '%Jr.%' AND m.incolor = 'Y' ORDER BY ms.birthdate DESC, ms.name

-- 2) Да се напише заявка, която извежда следната информация за всяка актриса, играла в най-много 6 филма:
--      • име;
--      • рождена година (напр. ако актрисата е родена на 1.1.1995 г., в колоната да пише 1995);
--      • брой различни студиа, с които е работила.
-- Ако за дадена актриса няма информация в какви филми е играла, за нея също да се изведе ред с горната информация, като за брой
-- студиа се изведе 0.
SELECT ms.name, YEAR(ms.birthdate) AS birthYear, COUNT(DISTINCT m.studioname) AS studioCount FROM moviestar ms
LEFT JOIN starsin si ON ms.name = si.starname LEFT JOIN movie m ON m.title = si.movietitle AND m.year = si.movieyear
WHERE ms.gender = 'F' GROUP BY ms.name, ms.birthdate HAVING COUNT(*) <= 6;