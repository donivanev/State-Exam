USE movies;

-- Да се посочи заявката, която извежда името на продуцента и имената на филмите, продуцирани от продуцента на 'Pretty Woman'.
-- Възможно е името на продуцента на филма да не е известно.

SELECT t.name, title FROM movie m JOIN (SELECT name, cert# FROM movieexec WHERE cert# IN
(SELECT producerc# FROM movie WHERE title = 'Pretty Woman')) t ON m.producerc# = t.cert#;

SELECT name, title FROM (SELECT cert# FROM movieexec
INTERSECT
SELECT producerc# FROM movie WHERE title ='Pretty Woman') t

SELECT name, title FROM movie m JOIN movieexec me ON m.producerc# = me.cert# WHERE title = 'Pretty Woman';

SELECT name, title FROM movie m LEFT JOIN movieexec me ON m.producerc# = me.cert# WHERE me.cert# NOT IN
(SELECT producerc# FROM movie WHERE title='Pretty Woman');

-- Посочете заявката, която за актьорите, участвали в най много филми на съответното студио, извежда име на студио, име на актьор
-- и брой филми, в които е участвал актьорът. В резултата не трябва да се включват филми, за които името на студиото не е известно.

SELECT studioname, starname, COUNT(starname) FROM movie JOIN starsin ON title=movietitle AND year=movieyear
WHERE studioname IS NOT NULL GROUP BY studioname, starname HAVING COUNT (SELECT starname FROM movie, starsin
WHERE title=movietitle AND year=movieyear) >= MAX(starname);

SELECT studioname, starname, COUNT(starname) FROM movie m LEFT JOIN starsin ON title=movietitle AND year=movieyear
WHERE studioname IS NOT NULL GROUP BY studioname, starname HAVING COUNT(SELECT starname FROM movie, starsin
WHERE title=movietitle AND year=movieyear) >= ALL (SELECT COUNT(*) FROM movie, starsin WHERE title=movietitle AND year=movieyear
GROUP BY studioname, starname);

SELECT studioname, starname, COUNT(DISTINCT starname) FROM movie m JOIN starsin ON title=movietitle AND year=movieyear
WHERE studioname IS NOT NULL GROUP BY m.studioname, starname HAVING COUNT(starname) >= ALL (SELECT COUNT(DISTINCT starname)
FROM movie, starsin WHERE title=movietitle AND year=movieyear AND studioname=m.studioname GROUP BY studioname, starname);

SELECT studioname, starname, COUNT(*) FROM movie m JOIN starsin ON title=movietitle AND year=movieyear WHERE studioname IS NOT NULL
GROUP BY studioname, starname HAVING COUNT(*) >= ALL (SELECT COUNT(*) FROM movie, starsin WHERE title=movietitle AND year=movieyear
AND studioname=m.studioname GROUP BY studioname, starname);

-- ______________________________________________

USE ships;

-- Да се посочи заявката, която извежда всички държави, които имат поне един кораб, участвал в битка, както и броя на потъналите
-- кораби за всяка от държавите.

SELECT c.country , COUNT(o.result) FROM classes c left join ships s ON c.class=s.class LEFT JOIN outcomes o ON s.name=o.ship
WHERE result='sunk' OR result IS NOT NULL GROUP BY c.country;

SELECT c.country , COUNT(o.result) FROM classes c JOIN ships s ON c.class=s.class JOIN outcomes o ON s.name=o.ship
WHERE result='sunk' GROUP BY c.country;

SELECT c.country , COUNT(o.result) FROM classes c join ships s ON c.class=s.class JOIN outcomes o ON s.name=o.ship
JOIN battles b ON o.battle=b.name ORDER BY c.country HAVING result ='sunk';

SELECT DISTINCT c.country, (SELECT COUNT(o.result) FROM classes c1 JOIN ships s ON c1.class=s.class JOIN outcomes o ON s.name=o.ship
WHERE result='sunk' AND c1.country=c.country) FROM classes c;

-- Да се посочи заявката, която извежда имената на битките, които са по-мащабни (с кораби от повече държави) от битката в
-- Коралово море (Coral Sea).

SELECT DISTINCT battle FROM outcomes o1 WHERE (SELECT COUNT(DISTINCT country) FROM outcomes o,ships s,classes c
WHERE o.ship=s.name AND s.class=c.class AND battle=o1.battle) > (SELECT count(DISTINCT country)
FROM outcomes o,ships s,classes c WHERE o.ship=s.name AND s.class=c.class AND battle='Coral Sea')

SELECT DISTINCT battle FROM outcomes, (SELECT count(DISTINCT country) as NumCountries FROM outcomes o,ships s,classes c
WHERE o.ship=s.name AND s.class=c.class AND battle='Coral Sea') as t HAVING (SELECT count(DISTINCT country)
FROM outcomes o1,ships s,classes c WHERE o1.ship=s.name AND s.class=c.class AND battle=o1.battle) > (SELECT NumCountries FROM t);

SELECT DISTINCT battle FROM outcomes o, ships s, classes c WHERE o.ship=s.name AND s.class=c.class GROUP BY battle
HAVING COUNT(DISTINCT country)>(SELECT COUNT(country) FROM outcomes o, classes c, ships s WHERE ship=name AND s.class=c.class
AND battle='Coral Sea');

SELECT DISTINCT battle FROM outcomes o CROSS JOIN classes c GROUP BY battle HAVING COUNT(DISTINCT country) > 
(SELECT COUNT(DISTINCT country) FROM outcomes o, classes c WHERE battle='Coral Sea');