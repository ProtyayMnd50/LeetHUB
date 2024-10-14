# Write your MySQL query statement below
select pr.firstName,pr.lastName,ad.city,ad.state
from Person pr left join Address ad
on pr.personId=ad.personId;