----- JOINS -----

USE movies

-- 1. Напишете заявка, която за всеки филм, по-дълъг от 120 минути, извежда заглавие, година, име и адрес на студио.

SELECT title, year, studioname, address FROM movie JOIN studio ON studioname = name WHERE length > 120

-- 2. Напишете заявка, която извежда името на студиото и имената на актьорите, участвали във филми, произведени от това студио,
-- подредени по име на студио.

SELECT DISTINCT studioname, starname FROM movie JOIN starsin ON title = movietitle AND year = movieyear ORDER BY studioname

-- 3. Напишете заявка, която извежда имената на продуцентите на филмите, в които е играл Harrison Ford.

SELECT DISTINCT name FROM movieexec JOIN movie ON cert# = producerc# JOIN starsin ON title = movietitle AND year = movieyear
WHERE starname = 'Harrison Ford'

-- 4. Напишете заявка, която извежда имената на актрисите, играли във филми на MGM.

SELECT name FROM moviestar JOIN starsin ON name = starname JOIN movie ON movietitle = title AND movieyear = year
WHERE studioname = 'MGM' and gender = 'F'

-- 5. Напишете заявка, която извежда името на продуцента и имената на филмите, продуцирани от продуцента на 'Star Wars'.

SELECT name, title FROM movieexec JOIN movie ON cert# = producerc# WHERE producerc# IN
(SELECT producerc# FROM movie WHERE title = 'Star Wars')

-- 6. Напишете заявка, която извежда имената на актьорите, които не са участвали в нито един филм. 

SELECT name FROM moviestar WHERE name NOT IN (SELECT starname FROM starsin) 

USE pc

-- 1. За всеки модел компютри да се изведат цените на различните конфигурации от този модел. Ако няма конфигурации за даден модел,
-- да се изведе NULL. Резултатът да има две колони: model и price.

SELECT DISTINCT product.model, price FROM product LEFT JOIN pc ON product.model = pc.model WHERE type = 'PC'

-- 2. Напишете заявка, която извежда производител, модел и тип на продукт за тези производители, за които съответният продукт не
-- се продава (няма го в таблиците PC, Laptop или Printer).

SELECT maker, model, type FROM product WHERE model NOT IN (SELECT model FROM pc) AND model NOT IN (SELECT model FROM laptop)
AND model NOT IN (SELECT model FROM printer)
-- or
SELECT maker, p.model, type FROM product p LEFT JOIN
(SELECT model FROM pc UNION ALL SELECT model FROM laptop UNION ALL SELECT model FROM printer) t
ON p.model = t.model WHERE t.model IS NULL

USE ships

-- 1. Напишете заявка, която за всеки кораб извежда името му, държавата, броя оръдия и годината на пускане (launched).

SELECT name, country, numguns, launched FROM ships JOIN classes ON ships.class = classes.class 

-- 2.  Напишете заявка, която извежда имената на корабите, участвали в битка от 1942г.

SELECT ship FROM outcomes JOIN battles ON battle = name WHERE YEAR(date) = '1942'