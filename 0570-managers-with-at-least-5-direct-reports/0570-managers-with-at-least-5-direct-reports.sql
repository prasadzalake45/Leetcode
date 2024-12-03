select m.name
from employee e
inner join employee m
where e.managerid=m.id
group by e.managerid
having count(*) >=5