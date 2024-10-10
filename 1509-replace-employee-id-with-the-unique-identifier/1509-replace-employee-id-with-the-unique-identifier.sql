# Write your MySQL query statement below


select emp.unique_id as unique_id,emp2.name 
from Employees emp2
LEFT JOIN EmployeeUNI as emp
ON emp2.id=emp.id;