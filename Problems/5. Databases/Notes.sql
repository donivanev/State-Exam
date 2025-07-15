/*
-- 1 --

USE ships - смяна на текущата база
AS - преименуване на колони
SELECT * FROM table - селектира всичко от дадена таблица
SELECT, FROM, WHERE, AND, OR

< - лексикографско сравнение
LIKE, NOT LIKE - проверка за съвпадане на низ с даден шаблон
% - последователност от 0 или повече символи
_ - точно 1 символ

DATE(), YEAR(), MONTH()
SELECT name, year(birthdate) FROM moviestar WHERE month(birthdate) = 7;

IS NULL - проверява дали стойността не е NULL (= NULL е грешно)
ORDER BY (ASC/DESC) - сортира по нарастващ/намаляващ ред

-- 2 --

SELECT column JOIN table ON primary_key = foreign_key

Съединение на таблица със себе си:
	• SELECT m1.title FROM Movie m1, Movie m2 WHERE m2.title = 'Star Wars' AND m1.length > m2.length

DISTINCT - премахва повторенията от резултата

UNION - прави обединение на 2 заявки като премахва повторенията (UNION ALL запазва повторенията)
INTERSECT - прави сечение на 2 заявки като премахва повторенията
EXCEPT - прави разлика на 2 заявки като премахва повторенията

ORDER BY не се слага в подзаявки, а извън тях

-- 3 --

Оператори за проверки върху списъци
	• s IN (L) -> Връща TRUE, ако s е сред елементите на списъка L
	• s NOT IN (L) -> Връща TRUE, ако s не е сред елементите на списъка L
	• s > ALL(L) -> Връща TRUE, ако s е по-голям от всички елементи на списъка L
	• s > ANY(L) -> Връща TRUE, ако s е по-голям от поне един от елементите на списъка

SELECT * FROM Movie WHERE year IN (1980, 1985, 1990);

SELECT * FROM starsin WHERE starname IN (SELECT name FROM moviestar WHERE gender = 'F')
≡
SELECT starsin. * FROM starsin JOIN moviestar ON starname = name WHERE gender = 'F'

Подзаявки във FROM клаузата
	• SELECT movietitle, starname, birthdate FROM StarsIn, (SELECT name, birthdate FROM MovieStar WHERE gender = 'F') Actresses
	WHERE starname = name
Задължително трябва да укажем име на таблицата, дори и никъде да не го използваме

EXISTS - връща стойност TRUE, ако в резултата от подзаявката има поне един ред

Корелативна подзаявка - подзаявка, която използва стойности от външната заявка (те са бавни заявки)
	• SELECT DISTINCT title FROM movie m WHERE year < ANY (SELECT year FROM movie WHERE title = m.title);

-- 4 --

COALESCE(...) - получава параметри и връща първият който е различен от NULL
			  - премахва NULL стойностите

Когато в една заявка има повече от един оператор JOIN и поне един от тях е OUTER JOIN, 
редът на прилагането им има значение. Ако са само INNER JOIN – няма

При OUTER JOIN има разлика дали дадено условие ще бъде в ON или в WHERE
При INNER JOIN няма, понеже се свежда до подмножество на декартово произведение
При LEFT JOIN ползваме
	• ON, ако имаме условие за дясната таблица
	• WHERE, ако имаме условие за лявата, напр. класове, започващи с "X"

-- 5 --

COUNT(), SUM(), AVG(), MIN(), MAX()
COUNT(*) - брои всички колони
COUNT(DISTINCT column) - брой колоните и премахва повтарящите се

GROUP BY - групира по колона

SELECT YEAR(birthdate), COUNT(*) FROM moviestar GROUP BY YEAR(birthdate)

Важни правила:
	• Не можем да използваме агрегатни функции в WHERE клауза
	• При GROUP BY и ORDER BY можем да използваме само колоните по които групираме и агрегатни функции
	• HAVING се използва само след GROUP BY и не може да съществува без него
	• В HAVING клаузата може да стои само това, по което сме групирали или агрегатна функция
	• NULL стойностите се игнорират при агрегиране, но не и при групиране

Ред на изпълнение на функциите:

FROM ...
... JOIN ... ON ...
WHERE ...
GROUP BY ...
HAVING ...
SELECT ...
ORDER BY ...

-- 8 --

BEGIN TRANSACTION;

INSERT INTO battles (name, date) VALUES ('Denmark Strait', '1941-05-24')
INSERT INTO studio(name) SELECT DISTINCT studioname FROM movie WHERE studioname NOT IN (SELECT name FROM studio);
UPDATE printer SET price = price * 0.9 WHERE color = 'y';
DELETE FROM moviestar WHERE name LIKE 'Jen%';

ROLLBACK TRANSACTION;

-- 9 --

INT, VARCHAR(n), CHAR(n), FLOAT / REAL, DECIMAL(n, d) – дробно число с n цифри, d след десетичната запета, DATE, DATETIME

CREATE TABLE t ();
ALTER TABLE t ADD c ...
ALTER TABLE t DROP column c ...
DROP TABLE t

gender CHAR(1) DEFAULT '?'

CREATE DATABASE db
DROP DATABASE db

-- Други --

SELECT TOP 1 * FROM printer ORDER BY price DESC
При MySQL, TOP = LIMIT

SELECT DISTINCT class FROM outcomes JOIN ships on ship = name WHERE result = 'sunk';
NO -> SELECT DISTINCT class FROM outcomes JOIN ships on ship = name WHERE result != 'sunk'

INSTEAD
SELECT class FROM classes WHERE class NOT IN 
(SELECT DISTINCT class FROM outcomes JOIN ships ON ship = name WHERE result = 'sunk');

SELECT * FROM classes WHERE EXISTS (SELECT * FROM ships);

При подзаявки във FROM клаузата задължително трябва да укажем име на таблицата, дори и да не го ползваме
SELECT movietitle, starname, birthdate FROM starsin, (SELECT name, birthdate FROM moviestar WHERE gender = 'F') Actresses 
WHERE starname = name;

CROSS JOIN - декартово произведение
(INNER) JOIN - сечение на таблици, избира записите които имат съвпадащи стойности и в двете таблици
NATURAL JOIN - съединение на таблици ако дадени редове съвпадат (не се поддържа в MSSQL)
LEFT (OUTER) JOIN - лява разлика, прави INNER JOIN като връща всички редове от лявата таблица (т.е. не губим 
информация от нея) и съвпадащите записи от дясната таблица
RIGHT (OUTER) JOIN - дясна разлика, прави INNER JOIN като връща всички редове от дясната таблица (т.е. не губим 
информация от нея) и съвпадащите записи от лявата таблица
FULL (OUTER) JOIN - запазваме всички редове от двете таблици, UNION

При INNER JOIN няма значение коя от двете колони с едни и същи имена ще вземем
Достатъчно е JOIN JOIN ... RIGHT JOIN, т.е. само последния да е десен за да покаже нулевите стойности
Където има първичен ключ не може да има NULL
В SELECT пишем същото по което сме JOIN-нали
DELETE -> само когато трием редове от таблица, DROP -> всичко друго

INSERT 2.3!!! -> подобна може да се падне на изпита

Важни подсказки според условието:
	• Поне два различни -> JOIN на таблица със себе си
	• Ако за ... няма ..., той също трябва да излезе в резултата -> LEFT JOIN и IS NULL
	• Ако не е в колекцията или не удовлетворява условието да се вписва 0 -> LEFT JOIN + ON ... AND ...
	• Колекцията да има поне X записа -> GROUP BY ... HAVING(*) >= X
	• Е по-голяма от ... на който и да е ... -> > ALL()
	• За всеки/всяка -> GROUP BY
*/