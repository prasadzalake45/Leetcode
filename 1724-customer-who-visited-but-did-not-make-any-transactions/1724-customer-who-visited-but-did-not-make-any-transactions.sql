# Write your MySQL query statement below


select v.customer_id,COUNT(*) as count_no_trans

from Visits as v

LEFT JOIN Transactions as t

ON v.visit_id=t.visit_id

WHERE transaction_id is NULL
GROUP BY customer_id;