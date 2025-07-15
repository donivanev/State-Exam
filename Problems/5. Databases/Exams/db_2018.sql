USE movies;

-- Да се напише заявка, която да изведе име на студио, годината на първия филм за това студио, годината на последния филм
-- за това студио и броя на всички филми за това студио, само за тези студиа започващи с буквата ‘M’.

SELECT S.NAME AS STUDIO_NAME, MIN(M.YEAR) AS FIRST_MOVIE_YEAR, MAX(M.YEAR) AS LAST_MOVIE_YEAR, COUNT(*) AS TOTAL_MOVIES
FROM  STUDIO S JOIN MOVIE M ON S.NAME = M.STUDIONAME WHERE S.NAME LIKE 'M%' GROUP BY S.NAME;

-- Да се напише заявка, която да изведе името на актрисата, участвала в най-много филми, и броя на филмите, в които е участвала.

SELECT TOP 1 MS.NAME AS ACTRESS_NAME, COUNT(*) AS MOVIE_COUNT FROM MOVIESTAR MS JOIN STARSIN SI ON MS.NAME = SI.STARNAME
WHERE MS.GENDER = 'F' GROUP BY MS.NAME ORDER BY COUNT(*) DESC;

-- ______________________________________________

USE ships;

-- Да се напише заявка, която извежда име на клас, годината на първата битка, в която кораб на този клас е участвал, годината
-- на последната битка, в която кораб на този клас е участвал, и броя на всички различни битки, в които кораби на този клас са
-- участвали, само за тези класове, започващи с буквата N. Ако за даден клас няма кораб, който да е участвал в битка, за
-- съответните години да се върне стойност null.

SELECT C.CLASS, MIN(YEAR(B.DATE)) AS FIRST_BATTLE_YEAR, MAX(YEAR(B.DATE)) AS LAST_BATTLE_YEAR, COUNT(DISTINCT B.NAME) AS BATTLE_COUNT
FROM CLASSES C LEFT JOIN SHIPS S ON C.CLASS = S.CLASS LEFT JOIN OUTCOMES O ON S.NAME = O.SHIP LEFT JOIN  BATTLES B ON O.BATTLE = B.NAME
WHERE C.CLASS LIKE 'N%' GROUP BY C.CLASS;

-- Да се напише заявка, която да изведе имената на тези битки, за които броят на корабите от тип 'bb', участвали в тази битка,
-- е по-голям от броя на корабите от тип 'bc', участвали в същата битка. Битки, в които не е участвал нито един кораб, да не се
-- извеждат в резултата.

SELECT B.NAME FROM BATTLES B JOIN OUTCOMES O ON B.NAME = O.BATTLE JOIN SHIPS S ON O.SHIP = S.NAME JOIN CLASSES C ON S.CLASS = C.CLASS
GROUP BY B.NAME HAVING SUM(CASE WHEN C.TYPE = 'bb' THEN 1 ELSE 0 END) > SUM(CASE WHEN C.TYPE = 'bc' THEN 1 ELSE 0 END);