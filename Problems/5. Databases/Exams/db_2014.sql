USE pc;

-- Посочете заявката, която извежда всички производители на настолни компютри, които произвеждат и лаптопи.

select distinct maker from product where product.type = 'PC' and maker in
(select maker from product join laptop on product.model = laptop.model);

select maker from product p1 cross join product p2 where p1.maker = p2.maker and p1.type = 'PC' and p2.type = 'Laptop'
group by maker;

select distinct maker from product where type = 'PC' and type = 'Laptop';

select maker from product where type = 'PC'
union
select maker from product where type = 'Laptop';

-- Посочете заявката, която извежда кодовете, моделите и размерите на екраните на всички лаптопи, чиито производители имат
-- не повече от три модела принтери (евентуално 0).

select code, model, screen from laptop, product where maker is having count(printer.model) <= 3;

select code, l.model, screen from product p left join laptop l on p.model = l.model having count
(select * from product where maker = p.maker and type = 'Printer') <= 3;

select code, l.model, screen from laptop l inner join product p on l.model = p.model where maker not in
(select maker from product where type = 'Printer' group by maker having count(*) > 3);

select l.code, l.model, l.screen from laptop l join product p on l.model = p.model where maker in
(select maker from product where type = 'Printer' group by maker having count(*) <= 3)

select l.code, l.model, l.screen from product p left join laptop l on p.model = l.model
left join printer on p.model = printer.model group by l.code having count(distinct printer.code) <= 3;

-- ______________________________________________

USE ships;

-- Посочете заявката, която извежда имената на всички кораби, пуснати на вода в година, в която е имало битка
-- (не е задължително корабът да е участвал в нея).

select name from ships where launched = any (select year(date) from battles where count(*) >= 1);

select distinct ships.name from battles , ships where launched = year(date);

select name from battles where exists (select distinct * from ships where year(date) = launched);

select distinct name from ships join battles on launched = year(date);

-- Посочете заявката, която за всички държави, които имат най-много 3 (евентуално 0) кораба, извежда името на държавата и
-- броя потънали кораби (който също може да бъде 0).

select country, count(result) from classes c left join ships s on c.class = s.class left join outcomes o on s.name = o.ship
where o.result = 'sunk' group by country having count(ship) <= 3;

select country, count(result is 'sunk') from ships, classes, outcomes where count(ship) <= 3 or ship is null;

select distinct classes.country, sunk_cnt from classes right join
(select country, count(*) as sunk_cnt from classes c join ships s on c.class = s.class join outcomes o on s.name = o.ship
where result = 'sunk' group by country) sunk on classes.country = sunk.country where sunk_cnt <= 3;

select country, count(result = 'sunk') as sunk_cnt from ships s join outcomes o on s.name = o.ship right join classes c
on s.class = c.class where count(*) <= 3 group by country, sunk_cnt;

select distinct country, (select count(*) from classes c2 join ships s on c2.class = s.class join outcomes o on s.name = o.ship
where c2.country = c.country and result = 'sunk') from classes c where (select count(*) from classes c2
join ships s on c2.class = s.class where c2.country = c.country) <= 3;