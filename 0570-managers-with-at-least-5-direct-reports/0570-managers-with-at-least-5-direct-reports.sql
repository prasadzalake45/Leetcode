select m.name
from employee e
inner join employee m
where e.managerid=m.id
GROUP by e.managerid
having COUNT(*)>=5;
