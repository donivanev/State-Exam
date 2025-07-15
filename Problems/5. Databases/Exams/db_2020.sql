use movies

-- Да се напише заявка, която извежда имената и рождените дати на всички филмови звезди, чието име не съдържа "Jr." и
-- са играли в поне един цветен филм. Първо да се изведат най-младите звезди, а звезди, родени на една и съща дата, да се
-- изведат по азбучен ред.
SELECT name, birthdate FROM moviestar WHERE name NOT LIKE '%Jr.%' AND EXISTS (SELECT * FROM movie JOIN starsin ON
title = movietitle AND year = movieyear) ORDER BY YEAR(birthdate) DESC, name ASC

-- Да се напише заявка, която извежда следната информация за всяка актриса, играла в най-много 6 филма:
--      • име;
--      • рождена година (напр. ако актрисата е родена на 1.1.1995 г., в колоната да пише 1995);
--      • брой различни студиа, с които е работила.
-- Ако за дадена актриса няма информация в какви филми е играла, за нея също да се изведе ред с горната информация, като за
-- брой студиа се изведе 0.

SELECT name, YEAR(birthdate), COUNT(DISTINCT studioname) FROM moviestar LEFT JOIN starsin ON name = starname
LEFT JOIN movie ON movietitle = title AND movieyear = year GROUP BY name, birthdate HAVING COUNT(title) <= 6

-- ______________________________________________

-- Да се напише заявка, която извежда имената и адресите на всички студиа, които имат поне един цветен и поне един черно-бял филм.
-- Резултатът да се сортира възходящо по адрес.

SELECT name, address FROM studio WHERE name IN (SELECT studioname FROM movie WHERE incolor = 'Y' INTERSECT
SELECT studioname FROM movie WHERE incolor = 'N') ORDER BY address ASC

-- Да се напише заявка, която за всяко студио с най-много три филма извежда:
--      • името му;
--      • адреса;
--      • средната дължина на филмите на това студио.
-- Студиа без филми също да се изведат (за средна дължина да се извежда null или 0).

SELECT name, address, AVG(length) FROM studio LEFT JOIN movie ON name = studioname GROUP BY name, address
HAVING COUNT(title) <= 3