USE pc;

-- Посочете заявката, която извежда кодовете и цените на всички лаптопи, чийто екран е с диагонал между 13 и 15 инча включително
-- и за които съществува поне един персонален компютър със същото количество RAM памет:

SELECT code, price FROM Laptop WHERE screen BETWEEN 13 AND 15 AND ram IN (SELECT ram FROM PC);

SELECT code, price FROM Laptop WHERE screen >= 13 AND screen <= 15 AND ram = (SELECT ram FROM PC);

SELECT code, price FROM Laptop WHERE screen BETWEEN 13 AND 15 HAVING COUNT(SELECT ram FROM PC) >= 1;

SELECT code, price FROM Laptop WHERE EXISTS (SELECT * FROM PC WHERE ram = L.ram)

-- За всеки производител да се изведе името и броят 15-инчови лаптопи. Ако даден производител няма никакви лаптопи или има,
-- но нито един от тях не е 15-инчов, срещу името му да се изведе числото 0:

SELECT maker, COUNT(screen = 15) FROM Product NATURAL JOIN Laptop GROUP BY maker;

SELECT maker, COUNT(code) AS laptops FROM Product LEFT JOIN Laptop ON Product.model = Laptop.model HAVING screen = 15
GROUP BY maker;

SELECT maker, COUNT(code) FROM Laptop RIGHT JOIN Product ON Laptop.model = Product.model AND screen = 15 GROUP BY maker;

SELECT maker, COUNT(DISTINCT code) FROM Product LEFT OUTER JOIN Laptop ON Product.model = Laptop.model GROUP BY maker;
HAVING screen = 15;

-- ______________________________________________

USE movies;

-- Посочете заявката, която извежда имената на всички студиа, които имат поне един цветен филм и едновременно с това
-- поне един филм с неизвестна дължина:

SELECT studioName FROM Movie WHERE inColor != 'Y' AND studioName = (SELECT studioName FROM Movie WHERE length IS NULL);

SELECT studioName FROM Movie WHERE inColor = 'Y' AND length = NULL;

SELECT studioName FROM Movie WHERE inColor = 'Y'
INTERSECT
SELECT studioName FROM Movie WHERE length IS NULL;

SELECT name FROM Studio LEFT JOIN Movie ON name = studioName WHERE inColor = 'Y' OR length = NULL;

-- Посочете заявката, която за всяка актриса извежда името и броя на черно-белите филми, в които е участвала. Ако за дадена
-- актриса няма информация в какви филми е участвала или е играла само в цветни филми, срещу нейното име да се изведе числото 0.

SELECT name, COUNT(DISTINCT title) FROM Movie RIGHT JOIN StarsIn ON title = movieTitle AND year = movieYear
RIGHT JOIN MovieStar ON starName = name WHERE gender = 'F' GROUP BY name HAVING inColor = 'N';

SELECT name, COUNT(title) FROM MovieStar LEFT JOIN StarsIn ON name = starName LEFT JOIN Movie ON movieTitle = title
AND movieYear = year AND inColor = 'N' WHERE gender = 'F' GROUP BY name;

SELECT name, COUNT(title) FROM MovieStar LEFT JOIN StarsIn ON name = starName LEFT JOIN Movie ON movieTitle = title
AND movieYear = year HAVING inColor = 'N' AND gender = 'F' GROUP BY name;

SELECT starName, COUNT(*) FROM StarsIn LEFT JOIN Movie ON title = movieTitle AND year = movieYear
WHERE inColor = 'N' AND gender = 'F' GROUP BY name;