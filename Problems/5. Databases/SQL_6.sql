----- ALL -----

USE movies

-- 1. Всички филми, чието заглавие съдържа едновременно думите 'Star' и 'Trek' (не непременно в този ред).
-- Резултатите да се подредят по година (първо най-новите филми), а филмите от една и съща година - по азбучен ред

SELECT title FROM movie WHERE title LIKE '%Star%' AND title LIKE '%Trek%' ORDER BY year DESC, title

-- 2. Заглавията и годините на филмите, в които са играли звезди, родени между 1.1.1970 и 1.7.1980

SELECT DISTINCT movietitle, movieyear FROM starsin JOIN moviestar ON starname = name
WHERE birthdate BETWEEN '1970-01-01' AND '1980-07-01'

USE pc

-- 1. Компютрите, които са по-евтини от всеки лаптоп на същия производител

SELECT code FROM pc JOIN product p ON pc.model = p.model
WHERE price < ALL(SELECT price FROM laptop JOIN product ON laptop.model = product.model WHERE maker = p.maker)

-- 2. Компютрите, които са по-евтини от всеки лаптоп и принтер на същия производител

SELECT code FROM pc JOIN product p ON pc.model = p.model
WHERE price < ALL(SELECT price FROM laptop JOIN product ON laptop.model = product.model WHERE maker = p.maker)
AND price < ALL(SELECT price FROM printer JOIN product ON printer.model = product.model WHERE maker = p.maker)

USE ships

-- 1. Имената и годините на пускане на всички кораби, които имат същото име като своя клас

-- Грешна !!!
SELECT name, launched FROM ships WHERE name = class

SELECT name, launched FROM ships JOIN classes ON ships.class = classes.class WHERE name = classes.class

-- 2. Имената на всички кораби, за които едновременно са изпълнени следните условия:
-- участвали са в поне една битка и имената на корабите започват с 'C' или 'K'

SELECT DISTINCT name FROM ships JOIN outcomes ON name = ship AND (name LIKE 'C%' OR name LIKE 'K%')

-- 3. Всички държави, които имат потънали в битка кораби

SELECT DISTINCT country FROM classes JOIN ships ON classes.class = ships.class JOIN outcomes ON name = ship
WHERE result = 'sunk'

-- 4. Всички държави, които нямат нито един потънал кораб

SELECT DISTINCT country FROM classes WHERE country NOT IN
(SELECT country FROM classes JOIN ships ON classes.class = ships.class JOIN outcomes ON name = ship WHERE result = 'sunk')

-- 5. (От държавен изпит) Имената на класовете, за които няма кораб, пуснат на вода (launched) след 1921 г.
-- Ако за класа няма пуснат никакъв кораб, той също трябва да излезе в резултата



-- 6. Името, държавата и калибъра (bore) на всички класове кораби с 6, 8 или 10 оръдия. Калибърът да се изведе в см (1 инч ~ 2.54 см)

SELECT name, country, bore * 2.54 FROM ships JOIN classes ON ships.class = classes.class WHERE numguns IN (6, 8, 10)

SELECT name, country, bore * 2.54 FROM ships JOIN classes ON ships.class = classes.class
WHERE numguns = 6 OR numguns = 8 OR numguns = 10

-- 7. Държавите, които имат класове с различен калибър (напр. САЩ имат клас с 14 калибър и класове с 16 калибър, докато
-- Великобритания има само класове с 15)

SELECT country FROM classes

-- 8. Страните, които произвеждат кораби с най-голям брой оръдия (numguns)

SELECT country FROM classes

--------------------------------------------------------------------------------------------------------

USE movies

-- 1. Без повторение заглавията и годините на всички филми, заснети преди 1982, в които е играл поне един актьор (актриса),
-- чието име не съдържа нито буквата 'k', нито 'b'. Първо да се изведат най-старите филми

-- Грешна !!!
-- Starsin има само препратки към истинските ключове
-- С JOIN гарантираме, че взимаме истински филми, а не просто съвпадения от starsin
-- В starsin ги има тези заглавията и годините, но НЕ знаем дали реално съществуват в movie, ако не направим JOIN
SELECT DISTINCT movietitle, movieyear FROM starsin WHERE movieyear < 1982 AND
(starname NOT LIKE '%k%' AND starname NOT LIKE '%b%') ORDER BY movieyear

-- Вярна
SELECT DISTINCT title, year FROM movie JOIN starsin ON title = movietitle AND
year = movieyear WHERE starname NOT LIKE '%k%' AND starname NOT LIKE '%b%' AND year < 1982

-- 2. Заглавията и дължините в часове (length е в минути) на всички филми, които са от същата година, от която е и
-- филмът Terms of Endearment, но дължината им е по-малка или неизвестна

SELECT title, length / 60 FROM movie WHERE year = (SELECT year FROM movie WHERE title = 'Terms of Endearment')
AND (length < (SELECT length FROM movie WHERE title = 'Terms of Endearment') OR length IS NULL)

-- 3. Имената на всички продуценти, които са и филмови звезди и са играли в поне един филм преди 1980 г. и поне един след 1985 г.

-- Тук няма нужда от JOIN, защото искаме условие за самата стойност name
-- Това, което се изисква в задачата (name) не е информация от две таблици, за да правим JOIN
SELECT name FROM movieexec WHERE name IN (SELECT name FROM moviestar)
AND name IN (SELECT starname FROM starsin WHERE movieyear < 1980)
AND name IN (SELECT starname FROM starsin WHERE movieyear > 1985)

-- 4. Всички черно-бели филми, записани преди най-стария цветен филм (InColor = 'y' / 'n') на същото студио

SELECT title FROM movie m WHERE incolor = 'n' AND
year < (SELECT MIN(year) FROM movie WHERE incolor = 'y' AND studioname = m.studioname)

-- 5. Имената и адресите на студиата, които са работили с по-малко от 5 различни филмови звезди.
-- Студиа, за които няма посочени филми или има, но не се знае кои актьори са играли в тях, също да бъдат изведени.
-- Първо да се изведат студиата, работили с най-много звезди

SELECT name, address FROM studio LEFT JOIN movie ON name = studioname LEFT JOIN starsin ON title = movietitle AND year = movieyear
GROUP BY name, address HAVING COUNT(DISTINCT starname) < 5 ORDER BY COUNT(DISTINCT starname) DESC

-- 6. За всеки актьор/актриса изведете броя на различните студиа, с които са записвали филми

SELECT name, COUNT(DISTINCT studioname) FROM moviestar JOIN starsin ON name = starname JOIN movie ON movietitle = title AND movieyear = year
GROUP BY name

-- 7. За всеки актьор/актриса изведете броя на различните студиа, с които са записвали филми, включително и за тези,
-- за които нямаме информация в какви филми са играли

SELECT name, COUNT(DISTINCT studioname) FROM moviestar LEFT JOIN starsin ON name = starname LEFT JOIN movie ON movietitle = title AND movieyear = year
GROUP BY name

-- 8. Изведете имената на актьорите, участвали в поне 3 филма след 1990 г.

SELECT name FROM moviestar JOIN starsin ON name = starname WHERE movieyear > 1990 GROUP BY name HAVING COUNT(*) >= 3

USE pc

-- 1. Да се изведат различните модели компютри, подредени по цена на най-скъпия конкретен компютър от даден модел

SELECT model, MAX(price) AS max_price FROM pc GROUP BY model ORDER BY max_price DESC

USE ships

-- 1. За всеки кораб, който е от клас с име, несъдържащо буквите i и k, да се изведе името на кораба и през коя година
-- е пуснат на вода (launched). Резултатът да бъде сортиран така, че първо да се извеждат най-скоро пуснатите кораби

SELECT name, launched FROM ships JOIN classes ON ships.class = classes.class WHERE classes.class NOT LIKE '%i%'
AND classes.class NOT LIKE '%k%' GROUP BY name, launched ORDER BY launched DESC

-- 2. Да се изведат имената на всички битки, в които е повреден (damaged) поне един японски кораб

SELECT battle FROM outcomes JOIN ships ON ship = name JOIN classes ON ships.class = classes.class 
WHERE result = 'damaged' AND country = 'Japan'

-- 3. Да се изведат имената и класовете на всички кораби, пуснати на вода една година след кораба 'Rodney' и броят на оръдията
-- им е по-голям от средния брой оръдия на класовете, произвеждани от тяхната страна

SELECT name, classes.class FROM ships JOIN classes ON ships.class = classes.class
WHERE launched = 1 + (SELECT launched FROM ships JOIN classes ON ships.class = classes.class WHERE name = 'Rodney')
-- AND numguns > AVG(SELECT launched FROM classes WHERE country =)

-- 4. Да се изведат американските класове, за които всички техни кораби са пуснати на вода в рамките на поне 10 години
-- (например кораби от клас North Carolina са пускани в периода от 1911 до 1941, което е повече от 10 години, докато кораби
-- от клас Tennessee са пуснати само през 1920 и 1921 г.)

SELECT classes.class FROM classes JOIN ships ON classes.class = ships.class WHERE country = 'USA' GROUP BY classes.class
HAVING MAX(launched) - MIN(launched) < 10

-- 5. За всяка битка да се изведе средният брой кораби от една и съща държава (например в битката при Guadalcanal са
-- участвали 3 американски и един японски кораб, т.е. средният брой е 2)

SELECT battle, AVG(country_ship_count) FROM (SELECT battle, country, COUNT(*) AS country_ship_count FROM outcomes
JOIN ships ON ship = name JOIN classes ON ships.class = classes.class GROUP BY battle, country) AS per_country_counts
GROUP BY battle

-- 6. За всяка държава да се изведе: броят на корабите от тази държава, броя на битките, в които е участвала,
-- броя на битките, в които неин кораб е потънал ('sunk') (ако някоя от бройките е 0 – да се извежда 0)



-- 7. Изведете броя на потъналите американски кораби за всяка проведена битка с поне един потънал американски кораб



-- 8. Битките, в които са участвали поне 3 кораба на една и съща страна



-- 9. Имената на класовете, за които няма кораб, пуснат на вода след 1921 г., но имат пуснат поне един кораб



-- 10. (*) За всеки кораб намерете броя на битките, в които е бил увреден. Ако корабът не е участвал в битки или
-- пък никога не е бил увреждан, в резултата да се вписва 0



-- 11. (*) Намерете за всеки клас с поне 3 кораба броя на корабите от този клас, които са победили в битка

