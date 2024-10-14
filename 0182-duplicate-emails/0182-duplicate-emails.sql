# Write your MySQL query statement below

select email as Email from
(
select email,count(email)
from person
group by email
having count(email)>1
) as als;
