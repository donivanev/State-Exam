USE PC

-- Да се напише заявка, която извежда кодовете, цените и имената на производителите на всеки персонален компютър, който удовлетворява
-- някое от следните условия:
--      • моделът започва с буквата "А" и завършва с цифрата 2;
--      • моделът е неизвестен (NULL в колоната model на таблицата PC).
-- За компютърни конфигурации с неизвестен модел трябва да се изведе NULL в колоната за производител.

SELECT code, price, maker FROM pc LEFT JOIN product ON pc.model = product.model WHERE pc.model LIKE 'A%2' OR pc.model IS NULL

-- Да се посочи заявката, която извежда без повторение имената на всички производители, които имат едновременно поне един модел
-- персонален компютър и поне два модела лаптопи:

(SELECT maker FROM Product WHERE type = 'PC' AND COUNT(model) >= 1)
INTERSECT
(SELECT maker FROM Product WHERE type = 'Laptop' AND COUNT(model) >= 2);

SELECT maker FROM Product p WHERE type = 'Laptop' AND EXISTS (SELECT * FROM Product WHERE type = 'PC' AND maker = p.maker)
GROUP BY maker HAVING COUNT(*) >= 2;

SELECT DISTINCT maker FROM Product WHERE type = 'PC' AND maker = (SELECT maker FROM Product GROUP BY maker HAVING COUNT(maker) >= 2
AND type = 'Laptop');

(SELECT maker FROM Product WHERE type = 'Laptop' GROUP BY maker HAVING COUNT(*) >= 2)
EXCEPT
(SELECT maker FROM Product WHERE type != 'PC');

-- ______________________________________________

-- Да се напише заявка, която намира средната цена на всички лаптопи, удовлетворяващи поне едно от следните условия:
--      • RAM паметта им е между 16 и 32 GB включително;
--      • производителят е неизвестен (колоната maker има стойност NULL).
-- Заявката да изведе точно една стойност. Ако не съществува нито един лаптоп, удовлетворяващ някое от условията, заявката да изведе стойността NULL.

SELECT AVG(price) FROM Laptop JOIN Product ON Laptop.model = Product.model WHERE ram BETWEEN 16 AND 32 OR maker IS NULL;

-- Коя от следните заявки извежда информация колко различни модела 14-инчови лаптопи произвежда всеки от производителите?
-- В резултатната таблица трябва да бъдат изведени без повторение абсолютно всички производители без изключение, дори и да нямат лаптопи изобщо.
-- От даден модел лаптопи може да има няколко различни конфигурации – в резултата трябва да бъде третиран като един модел.

-- А)
SELECT DISTINCT maker, (SELECT COUNT(*) FROM Laptop WHERE screen = 14) FROM Product p;

-- Б)
SELECT maker, COUNT(DISTINCT Laptop.model) FROM Laptop RIGHT JOIN Product ON Laptop.model = Product.model AND screen = 14 GROUP BY maker;

-- В)
SELECT DISTINCT maker, COUNT(Laptop14.model) FROM Product LEFT JOIN (SELECT model, screen FROM Laptop) Laptop14 ON Product.model = Laptop14.model
GROUP BY maker HAVING screen = 14;

-- Г)
SELECT maker, COUNT(DISTINCT Laptop.model) FROM Product LEFT JOIN Laptop ON Product.model = Laptop.model WHERE Laptop.screen = 14 GROUP BY maker;