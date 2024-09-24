# Write your MySQL query statement below
# Write your MySQL query statement below

select max(salary) as SecondHighestSalary  from Employee 
WHERE salary !=(select max(salary) from Employee);