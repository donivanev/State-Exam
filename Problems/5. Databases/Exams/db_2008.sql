USE ships;

-- Посочете заявката, която извежда имената на битките, в които няма оцелели кораби (всички участвали кораби са потънали)

select distinct b.name from Battles b join Outcomes o on b.name = o.battle where o.result = 'sunk';

select o.battle from Outcomes o group by o.battle,o.result having o.result = 'sunk';

select distinct o.battle from Outcomes o left join Outcomes o1 on o.battle = o1.battle and o.ship = o1.ship and o1.result = 'sunk'
group by o.battle having count(o.ship)= count(o1.ship); -- ✓

select o.battle from Outcomes o group by o.battle having count(case when o.result = 'sunk' then 'Y' end) = 0;

-- ______________________________________________

-- Посочете заявката, която извежда за всеки клас годината на най-рано и най-късно пуснатия на вода кораб:

select c.class, min(ss.launched), max(ss.launched) from classes c join ships ss on ss.class = c.class;

select c.class, min(ss.launched), max(ss.launched) from classes c join ships ss on ss.class = c.class group by c.class; -- ✓

select c.class, min(ss.launched), max(ss.launched) from classes c join ships ss on ss.class = c.class group by c.class
having min(ss.launched) and max(ss.launched);

select c.class, min(ss.launched) from classes c join ships ss on ss.class = c.class
union all
select c.class, max(ss.launched) from classes c join ships ss on ss.class = c.class;

-- Посочете заявката, която извежда държавата/държавите с най-много класове:

select c.country from classes c where not exists
(select * from classes c1 where c1.country != c.country and count(c1.class) > count(c.class));

select c.country from classes c group by c.country having max(count(c.class));

select c.country from classes c where count(*) =
(select max(count(c1.class) from classes c1 group by c1.country) group by c.country;

select c.country from classes c group by c.country having count(*) >= all (select count(*) from classes c1 group by c1.country); -- ✓