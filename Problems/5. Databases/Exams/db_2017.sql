USE movies;

-- Попълнете липсващите части, обозначени с ______ така, че заявката да изведе за всяко студио името на студиото, заглавието
-- и годината на филма, излязъл последно на екран за това студио.

SELECT studioname, title, year FROM movie m WHERE year = (SELECT _______________ FROM movie WHERE _______________);

-- Попълнете липсващите части, обозначени с ______ така, че заявката да изведе име на продуцент и обща дължина на продуцираните
-- от него филми, за тези продуценти, които имат поне един филм преди 1980 г.

SELECT name, _______________ FROM movieexec JOIN movie ON producerc# = cert# _______________ _______________;

-- Попълнете липсващите части, обозначени с ______ така, че заявката да изведе име на актьорите, участвали във филми на
-- продуценти с най-големи нетни активи, както и заглавие на филмите, в които са участвали, име на продуцент и нетни активи.

SELECT starname, title, name, networth FROM starsin JOIN movie ON movietitle=title AND movieyear=year JOIN
(SELECT cert#, networth, name FROM movieexec WHERE _______________) t _______________;

-- Заградете буквата на заявката, която извежда името на продуцента, заглавието и годината на всички филми, продуцирани от
-- продуцента на филма "Interstellar".

SELECT name, title, year FROM movie, movieexec WHERE producerc#=cert# AND title='Interstellar' AND cert# IN
(SELECT producerc# FROM movie WHERE title='Interstellar');

SELECT t.name, title, year FROM movie m JOIN (SELECT name, cert# FROM movieexec WHERE EXISTS
(SELECT producerc# FROM movie WHERE title='Interstellar')) t ON m.producerc#=t.cert#;

SELECT name, title, year FROM movie JOIN movieexec ON producerc#=cert# WHERE cert# = ANY
(SELECT producerc# FROM movie WHERE title='Interstellar');

SELECT DISTINCT name, movietitle, movieyear FROM movie JOIN movieexec ON producerc#=cert# JOIN starsin ON year=movieyear
AND title=movietitle WHERE cert# IN (SELECT producerc# FROM movie WHERE title='Interstellar');

-- ______________________________________________

USE ships;

-- Попълнете липсващите части, обозначени с ______ така, че заявката да изведе име и държава на корабите, които никога не са
-- потъвали в битка (може и да не са участвали).

SELECT name, country FROM ships _______________ outcomes ON name=ship _______________classes ON ships.class=classes.class
WHERE _______________;

-- Попълнете липсващите части, обозначени с ______ така, че заявката да изведе име, водоизместимост и брой оръдия на най-леките
-- кораби с най-много оръдия.

SELECT name, displacement, numguns FROM classes c JOIN ships s ON s.class=c.class WHERE displacement =
(SELECT _______________ FROM classes) AND numguns = (SELECT _______________ FROM classes c1 WHERE _______________);

-- Попълнете липсващите части, обозначени с ______ така, че заявката да изведе име на битките, в които е участвал един кораб.

SELECT battle FROM outcomes o1 WHERE _______________ (SELECT * FROM outcomes o2 WHERE _______________);

-- Да се посочи заявката, която извежда име на класа и брой на потъналите в битка кораби за съответния клас, за тези класове
-- с повече от 5 кораба.

SELECT c.class FROM classes c JOIN ships s ON c.class=s.class GROUP BY c.class HAVING COUNT(name) > 5
INTERSECT
SELECT class FROM ships s JOIN outcomes o ON s.name=o.ship WHERE o.result='sunk';

SELECT class, COUNT(DISTINCT name) FROM ships s JOIN outcomes o ON s.name=o.ship WHERE result='sunk' AND class IN
(SELECT c.class FROM classes c JOIN ships s ON c.class=s.class GROUP BY c.class HAVING COUNT(name)>5) GROUP BY class;

SELECT class, COUNT(DISTINCT name) FROM ships s JOIN outcomes o ON s.name=o.ship WHERE result='sunk' AND class IN
(SELECT c.class FROM classes c JOIN ships s ON c.class=s.class WHERE COUNT(name)>5 GROUP BY c.class) GROUP BY class;

SELECT s.class, COUNT(DISTINCT name) FROM ships s JOIN outcomes o ON s.name=o.ship JOIN
(SELECT c.class FROM classes c JOIN ships s ON c.class=s.class GROUP BY c.class, name HAVING COUNT(name)>5) t ON s.class=t.class
WHERE result='sunk' GROUP BY s.class;