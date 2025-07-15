USE movies;

-- Да се посочи заявката, която извежда имената на всички филмови звезди, чието име не завършва на "а" и са играли както в
-- цветни, така и в черно бели филми.

SELECT name FROM MovieStar, StarsIn, Movie WHERE name = starName AND movieTitle = title AND movieYear = year
AND name != '%a' AND inColor = 'y' AND inColor = 'n';

SELECT MovieStar.name FROM MovieStar WHERE NOT (name LIKE '%a') AND name IN (SELECT starName FROM StarsIn
JOIN Movie ON movieTitle = title AND movieYear = year WHERE inColor = 'y' OR inColor = 'n');

SELECT DISTINCT starName FROM StarsIn INNER JOIN Movie ON movieTitle = title AND movieYear = year WHERE starName NOT LIKE '%a'
AND inColor = 'y' AND starName = (SELECT starName FROM StarsIn, Movie WHERE inColor = 'n');

SELECT starName FROM StarsIn JOIN Movie ON movieTitle = title AND movieYear = year WHERE starName NOT LIKE '%a' AND inColor = 'y'
INTERSECT
SELECT starName FROM StarsIn JOIN Movie ON movieTitle = title AND movieYear = year WHERE inColor = 'n';

-- Посочете заявката, която извежда за всяка филмова звезда, играла в най много 5 филма, следната информация:
-- име; рождена година; брой студиа, с които е работила.
-- Ако за дадена звезда няма информация в какви филми е играла, за нея също да се извежда ред (с брой студиа, равен на 0).

SELECT DISTINCT name, birthdate.year, COUNT(studioName) FROM MovieStar, StarsIn, Movie WHERE name = starname AND
((movieTitle = title AND movieYear = year) OR title IS NULL) GROUP BY name, birthdate.year HAVING COUNT(title) <= 5;

SELECT name, YEAR(birthdate), COUNT(DISTINCT studioName) FROM MovieStar LEFT OUTER JOIN StarsIn ON name = starname
LEFT JOIN Movie ON movieTitle = title AND movieYear = year GROUP BY name HAVING COUNT(title) <= 5;

SELECT StarsIn.starname, YEAR(birthdate), COUNT(DISTINCT studioName) FROM Movie JOIN StarsIn ON movieTitle = title
AND movieYear = year RIGHT OUTER JOIN MovieStar ON MovieStar.name = StarsIn.starname GROUP BY StarsIn.starname
HAVING COUNT(DISTINCT title) <= 5;

SELECT name, year(birthdate), COUNT(SELECT DISTINCT studioName FROM Movie JOIN StarsIn ON title = movieTitle AND year = movieYear
WHERE starname = name) FROM MovieStar HAVING COUNT(SELECT * FROM StarsIn WHERE starname = name) <= 5 ORDER BY name, year(birthdate);

-- ______________________________________________

-- Да се посочи заявката, която извежда имената и адресите на всички актриси от София, както и на всички филмови студиа от София.
-- Резултатите да са сортирани по адрес.

SELECT MS.name, MS.address FROM MovieStar AS MS JOIN Studio S ON MS.address = S.address WHERE MS.address LIKE '%Sofia%'
AND gender = 'F' ORDER BY MS.address;

SELECT * FROM (SELECT name, address FROM MovieStar WHERE gender = 'F'
UNION
SELECT name, address FROM Studio) T WHERE T.address LIKE '%Sofia%' ORDER BY T.address;

SELECT name, address FROM MovieStar MS WHERE gender = 'F' ORDER BY address
UNION ALL
SELECT name, address FROM Studio WHERE address LIKE '%Sofia%' ORDER BY address;

SELECT DISTINCT name, address FROM MovieStar
INTERSECT
Studio WHERE address IS NOT NULL AND gender LIKE 'F' GROUP BY address HAVING address LIKE '%Sofia%';

SELECT DISTINCT name, address FROM MovieStar FULL JOIN Studio ON address LIKE '%Sofia%' WHERE gender LIKE 'F' ORDER BY address;

-- Да се посочи заявката, която за всяко студио с най много три черно бели филма извежда името му, адреса и средната дължина
-- на филмите (без значение дали са цветни) на това студио. Студиа без филми също да се извеждат.

SELECT name, address, AVG(length) AS avgLength FROM Studio LEFT JOIN Movie ON name = studioName GROUP BY studioName, address
HAVING COUNT(inColor = 'y') <= 3;

SELECT DISTINCT name, address, avgLength FROM Studio, (SELECT studioName, AVG(length) AS avgLength FROM Movie GROUP BY studioName)
Averages WHERE NAME = ANY (SELECT studioName FROM Movie WHERE inColor = 'n' GROUP BY studioName HAVING COUNT(title) <= 3);

SELECT Studio.name, Studio.address, AVG(Movie.length) AS avgLength FROM Movie RIGHT JOIN Studio ON studioName = name
GROUP BY name, address HAVING (SELECT COUNT(*) FROM Movie WHERE inColor = 'n') <= 3;

SELECT name, address, AVG(length) AS avgLength FROM Studio LEFT JOIN Movie ON name = studioName WHERE NAME NOT IN
(SELECT studioName FROM Movie WHERE inColor = 'n' GROUP BY studioName HAVING COUNT(*) > 3) GROUP BY name, address;