USE movies;

-- Да се посочи заявката, която извежда име на студио и броя на филмите му, за тези студиа с по-малко от два филма.
-- Студиата, които нямат нито един филм, НЕ трябва да присъстват в резултата.

SELECT S.NAME, COUNT(M.TITLE) as CNT FROM STUDIO S JOIN MOVIE M ON S.NAME = M.STUDIONAME GROUP BY S.NAME HAVING CNT < 2;

SELECT S.NAME, COUNT(M.TITLE) as CNT FROM STUDIO S LEFT JOIN MOVIE M ON S.NAME = M.STUDIONAME WHERE M.TITLE IS NULL
GROUP BY S.NAME HAVING COUNT(M.TITLE) < 2;

SELECT S.NAME, COUNT(M.TITLE) as CNT FROM STUDIO S JOIN MOVIE M ON S.NAME = M.STUDIONAME GROUP BY S.NAME HAVING COUNT(M.TITLE) < 2;

SELECT S.NAME, COUNT(M.TITLE) as CNT FROM STUDIO S JOIN MOVIE M ON S.NAME = M.STUDIONAME WHERE COUNT(M.TITLE) < 2 GROUP BY S.NAME;

-- Да се напише заявка, която да изведе имената на всички продуценти с минимален нетен актив.

SELECT name, networth FROM movieexec WHERE networth = (SELECT MIN(networth) FROM movieexec);

-- ______________________________________________

use movies

-- Да се посочи заявката, която извежда за всеки продуцент името му и броя на филмите му по години. Продуценти, които нямат
-- нито един филм, НЕ трябва да присъстват в резултатното множество.

SELECT ME.NAME, M.YEAR, COUNT(*) AS CNT FROM MOVIEEXEC ME LEFT JOIN MOVIE M ON ME.CERT# = M.PRODUCERC# WHERE M.TITLE IS NULL
GROUP BY ME.CERT#, ME.NAME, M.YEAR;

SELECT ME.NAME, M.YEAR, COUNT(*) AS CNT FROM MOVIEEXEC ME JOIN MOVIE M ON ME.CERT# = M.PRODUCERC#
GROUP BY ME.CERT#, ME.NAME, M.YEAR;

SELECT ME.NAME, M.YEAR, COUNT(*) AS CNT FROM MOVIEEXEC ME, MOVIE M GROUP BY ME.CERT#, ME.NAME, M.YEAR WHERE ME.CERT# = M.PRODUCERC#;

SELECT ME.NAME, M.YEAR, COUNT(*) AS CNT FROM MOVIEEXEC ME JOIN MOVIE M ON ME.CERT# = M.PRODUCERC# ORDER BY ME.CERT#, ME.NAME, M.YEAR;

-- Да се напише заявка, която да изведе името на най-младата звезда (полът е без значение)

SELECT name FROM moviestar WHERE YEAR(birthdate) = (SELECT MIN(YEAR(birthdate)) FROM moviestar)