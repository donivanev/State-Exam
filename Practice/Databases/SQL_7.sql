BEGIN TRANSACTION

USE movies

SELECT * FROM moviestar
SELECT * FROM movieexec
SELECT * FROM movie

-- 1. Да се добави информация за актрисата Nicole Kidman. За нея знаем само, че е родена на 20-и юни 1967

INSERT INTO moviestar(name, address, gender, birthdate) VALUES ('Nicole Kidman', NULL, NULL, '1967-06-20')

-- 2. Да се изтрият всички продуценти с печалба (networth) под 10 милиона

DELETE FROM movieexec WHERE networth < 10000000

-- 3. Да се изтрие информацията за всички филмови звезди, за които не се знае адресът

DELETE FROM moviestar WHERE address IS NULL

-- 4. Да се добави титлата "Pres." пред името на всеки продуцент, който е и президент на студио

UPDATE movieexec SET name = 'Pres.' + name WHERE cert# IN (SELECT producerc# FROM movie)

USE pc

SELECT * FROM product
SELECT * FROM pc

-- 1. Използвайки две INSERT заявки, съхранете в базата от данни факта, че персонален компютър модел 1100 е направен от
-- производителя C, има процесор 2400 MHz, RAM 2048 MB, твърд диск 500 GB, 52x DVD устройство и струва $299.
-- Нека новият компютър има код 12. Забележка: моделът и CD са от тип низ.
-- Упътване: самото вмъкване на данни е очевидно как ще стане, помислете в какъв ред е по-логично да са двете заявки

INSERT INTO product(model, maker, type) VALUES ('1100', 'C', 'PC')
INSERT INTO pc(code, model, speed, ram, hd, cd, price) VALUES (12, '1100', 2400, 2048, 500, '52x', 299)

-- 2. Да се изтрие всичката налична информация за компютри модел 1100

DELETE FROM pc WHERE model = '1100'

-- 3. За всеки персонален компютър се продава и 15-инчов лаптоп със същите параметри, но с $500 по-скъп. Кодът на такъв лаптоп
-- е със 100 по-голям от кода на съответния компютър. Добавете тази информация в базата

-- DELETE FROM laptop WHERE model NOT IN (SELECT model FROM product WHERE type <> 'Printer')

-- 4. Да се изтрият всички лаптопи, направени от производител, който не произвежда принтери.

-- 5. Производител А купува производител B. На всички продукти на В променете производителя да бъде А.

UPDATE product SET maker = 'A' WHERE maker = 'B'

-- 6. Да се намали два пъти цената на всеки компютър и да се добавят по 20 GB към всеки твърд диск.
-- Упътване: няма нужда от две отделни заявки

UPDATE pc SET price = price / 2, hd = hd + 20

-- 7. За всеки лаптоп от производител B добавете по един инч към диагонала на екрана

UPDATE laptop SET screen = screen + 1 WHERE model IN (SELECT model FROM product WHERE maker = 'B')
 
USE ships

SELECT * FROM classes
SELECT * FROM ships
SELECT * FROM outcomes

-- 1. Два британски бойни кораба (type = 'bb') от класа Nelson - Nelson и Rodney - са били пуснати на вода едновременно
-- през 1927 г. Имали са девет 16-инчови оръдия (bore) и водоизместимост от 34 000 тона (displacement). Добавете тези факти към
-- базата от данни.

INSERT INTO classes(class, type, country, numguns, bore, displacement) VALUES ('Nelson', 'bb', 'Gt.Britain', 9, 16, 34000)
INSERT INTO ships(name, class, launched) VALUES ('Nelson', 'Nelson', '1927')
INSERT INTO ships(name, class, launched) VALUES ('Rodney', 'Nelson', '1927')

-- 2. Изтрийте от Sh) под 10 милиона.ips всички кораби, които са потънали в битка

DELETE FROM ships WHERE name IN (SELECT name FROM outcomes WHERE result = 'sunk')

-- 3. Променете данните в релацията Classes така, че калибърът (bore) да се измерва в сантиметри (в момента е в инчове,
-- 1 инч ~ 2.54 см) и водоизместимостта да се измерва в метрични тонове (1 м.т. = 1.1 т.)

UPDATE classes SET bore = bore * 2.54, displacement = displacement / 1.1

-- 4. Изтрийте всички класове, от които има по-малко от три кораба

DELETE FROM classes WHERE class NOT IN (SELECT class FROM ships GROUP BY class HAVING COUNT(*) >= 3)

-- 5. Променете калибъра на оръдията и водоизместимостта на класа Iowa, така че да са същите като тези на класа Bismarck

UPDATE classes SET bore = (SELECT bore FROM classes WHERE class = 'Bismarck'),
displacement = (SELECT displacement FROM classes WHERE class = 'Bismarck') WHERE class = 'Iowa'

ROLLBACK TRANSACTION