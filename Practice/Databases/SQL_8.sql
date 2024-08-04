/* 
1. Създайте БД "test"
2. Създайте следните таблици в нея:
	а) Product(maker, model, type), където моделът е низ от точно 4 символа, maker - един символ, а type - низ до 7 символа
	б) Printer(code, model, color, price), където code е цяло число, color е 'y' или 'n' и по подразбиране е 'n', 
	   price - цена с точност два знака след десетичната запетая
	в) Classes(class, type), където class е до 50 символа, а type може да бъде 'bb' или 'bc'
3. Добавете редове с примерни данни към новосъздадените таблици. Добавете информация за принтер, за който знаем само кода и модела
4. Добавете към Classes колона bore - число с плаваща запетая
5. Напишете заявка, която премахва колоната price от Printer
6. Изтрийте всички таблици и БД, които сте създали
*/

CREATE DATABASE test

CREATE TABLE Product (
	maker CHAR(1),
	model CHAR(4),
	type VARCHAR(7)
);

CREATE TABLE Printer (
	code INT,
	model CHAR(4),
	color CHAR(1) DEFAULT 'n',
	price DECIMAL(9, 2)
);

CREATE TABLE Classes (
	class VARCHAR(50),
	type CHAR(2)
);

INSERT INTO Printer(code, model) VALUES (1, '1234');
INSERT INTO Printer(code, model, color) VALUES (2, '1235', null);

ALTER TABLE Classes ADD bore DECIMAL(9, 2)
ALTER TABLE Printer DROP COLUMN price

DROP TABLE Product
DROP TABLE Printer
DROP TABLE Classes
DROP DATABASE test