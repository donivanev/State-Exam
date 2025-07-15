-- Всички класове с поне 3 кораба
SELECT class FROM ships GROUP BY class HAVING COUNT(*) >= 3
-- Тоест искаме броят на редовете (кораби) с еднакъв class да е ≥ 3

-- Имената на битките, в които са участвали поне 3 кораба
SELECT battle FROM outcomes GROUP BY battle HAVING COUNT(*) >= 3

-- Когато е нужна втора групировка над резултат от GROUP BY или искаме да приложим AVG() върху нещо,
-- което не е колона, а агрегатен резултат (като COUNT(*)), тогава единственият чист начин е с вложена заявка (във FROM)

-- Ако в SELECT имаме комбинация от неагрегатна и агрегатна колона, то задължително накрая трябва да има GROUP BY
-- HAVING след GROUP BY се използва САМО за филтриране

-- SELECT 1 в подзаявка означава: ако има редове, изпълни действието, независимо какви точно са тези редове.
SELECT name FROM moviestar ms WHERE NOT EXISTS (SELECT 1 FROM starsin si WHERE si.starname = ms.name)
-- еквивалентно на
SELECT * FROM moviestar ms WHERE NOT EXISTS (SELECT si.starname FROM starsin si WHERE si.starname = ms.name)

SELECT distinct ships.name FROM battles, ships WHERE launched = YEAR(date)

-- HAVING screen = 15 - грешно
-- COUNT(screen = 15) – уж брои само 15-инчови → но брои ВСИЧКИ редове (в SQL, COUNT(TRUE) ≡ 1)

-- При колебание между LEFT и RIGHT JOIN определяме основната таблица!