USE ships;

-- Да се напише заявка, която извежда без повторение имената на всички класове, от които няма нито един повреден в битка кораб.
-- Ако даден клас няма никакви кораби или има, но те не са участвали в никакви битки, този клас също трябва да бъде изведен.

SELECT DISTINCT classes.class FROM classes LEFT JOIN ships ON classes.class = ships.class LEFT JOIN outcomes ON name = ship
AND result = 'sunk' GROUP BY classes.class HAVING COUNT(ship) = 0

SELECT DISTINCT classes.class FROM classes LEFT JOIN ships ON classes.class = ships.class LEFT JOIN outcomes ON name = ship
WHERE ship NOT IN (SELECT ship FROM outcomes WHERE result = 'damaged')

-- Да се посочи коя от следните заявки извежда имената на класовете и броя на потъналите кораби от съответния клас. Ако даден
-- клас има кораби, но нито един от тях не е потънал или нито един от тях не е участвал в битка, срещу неговото име заявката да
-- извежда числото 0. Ако даден клас няма никакви кораби, неговото име да НЕ се извежда.

SELECT class, COUNT(ship) FROM Ships LEFT JOIN Outcomes ON Ships.name = Outcomes.ship AND result = 'sunk' GROUP BY class;

SELECT DISTINCT class, (SELECT COUNT(*) FROM Outcomes WHERE result = 'sunk') FROM Ships;

SELECT class, COUNT(result = 'sunk') FROM Ships JOIN Outcomes ON Ships.name = Outcomes.ship GROUP BY class HAVING COUNT(*) = 0;

SELECT c.class, COUNT(DISTINCT result) FROM Outcomes o RIGHT JOIN Ships s ON o.ship = s.name RIGHT JOIN Classes c
ON s.class = c.class WHERE result = 'sunk' GROUP BY c.class;

-- ______________________________________________

USE movies;

-- Да се напише заявка, която извежда без повторение имената на всички актриси, които са играли във филми както през 20-и век
-- (до 2000 г. включително), така и през 21-и век (от 2001 г. насам).

SELECT MS.NAME FROM MOVIESTAR MS JOIN STARSIN SI ON MS.NAME = SI.STARNAME JOIN MOVIE M ON SI.MOVIETITLE = M.TITLE AND SI.MOVIEYEAR = M.YEAR
WHERE MS.GENDER = 'F' GROUP BY MS.NAME HAVING SUM(CASE WHEN M.YEAR <= 2000 THEN 1 ELSE 0 END) > 0 AND SUM(CASE WHEN M.YEAR >= 2001 THEN 1 ELSE 0 END) > 0;

-- Да се посочи коя от следните заявки извежда без повторение имената на всички студиа, на които сумарната дължина на всички
-- техни черно-бели филми е по-голяма от дължината на най-дългия филм на това студио (без значение дали е цветен):

SELECT name FROM Studio LEFT JOIN Movie ON name = studioname AND incolor = 'N' GROUP BY name HAVING SUM(length) > MAX(length);

SELECT DISTINCT name FROM Studio RIGHT JOIN Movie ON name = studioname AND incolor = 'N' WHERE SUM(length) > MAX(length);

SELECT name FROM Studio WHERE (SELECT SUM(length) FROM Movie WHERE incolor = 'N' AND studioname = Studio.name) >
(SELECT MAX(length) FROM Movie WHERE studioname = Studio.name);

SELECT DISTINCT studioname FROM Movie m WHERE (SELECT SUM(length) FROM Movie WHERE incolor = 'N' AND studioname = m.studioname) >
(SELECT MAX(length) FROM Movie);