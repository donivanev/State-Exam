USE movies

-- Да се попълнят празните места в следната заявка така, че тя да извежда името на студиото на филма 'The Usual Suspects' и
-- заглавията на всички филми на същото студио:

-- SELECT s.name, m.title FROM movie ____ JOIN studio s ON m.studioname _____________________ WHERE s.name ____
-- (SELECT _______________ FROM _______________ WHERE title = 'The Usual Suspects' AND year = 1995);

-- Да се посочи коя от следните заявки извежда имената на филмовите звезди, за които няма информация в кои филми са играли:

SELECT DISTINCT starname FROM starsin GROUP BY starname HAVING COUNT(*) = 0;

SELECT ms.name, si.movietitle FROM moviestar ms LEFT JOIN starsin si ON ms.name=si.starname WHERE si.movietitle IS NULL;

SELECT name FROM starsin JOIN moviestar ON starname = name GROUP BY name HAVING COUNT(name) = 0;

SELECT name FROM moviestar WHERE NOT EXISTS (SELECT starname FROM starsin);

-- ______________________________________________

-- Да се напише заявка, която извежда заглавията и дължините в минути на всички цветни филми без най-дългия цветен и без тези
-- с неизвестна дължина. Ако има няколко филма с максимална дължина, нито един от тях не трябва да бъде изведен.

SELECT title, year FROM movie WHERE incolor = 'y' AND length IS NOT NULL AND length <
(SELECT max(length) FROM movie WHERE incolor = 'y' AND length IS NOT NULL)

-- Да се посочи заявката, която извежда имената на тези студиа, които нямат филми или са снимали филми само в една единствена година:

SELECT name FROM Studio WHERE name NOT IN (SELECT studioname FROM Movie) OR COUNT(DISTINCT year) = 1;

SELECT studioname FROM (SELECT studioname, year FROM Movie GROUP BY studioname, year) Years GROUP BY studioname
HAVING COUNT(*) <= 1;

SELECT name FROM Studio LEFT JOIN Movie ON name = studioname GROUP BY name HAVING COUNT(DISTINCT year) <= 1;

SELECT name FROM Studio WHERE NOT EXISTS (SELECT * FROM Movie)
UNION
SELECT studioname FROM Movie GROUP BY studioname HAVING COUNT(DISTINCT year) = 1;