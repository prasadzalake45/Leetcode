# Write your MySQL query statement below


select uni.unique_id  ,e.name from Employees as e
LEFT JOIN EmployeeUNI as uni
ON e.id=uni.id;