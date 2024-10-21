with tab0 as
(
select sn.user_id,cnf.action from
Signups sn left join Confirmations cnf
on sn.user_id=cnf.user_id
),
tab1 as
(
select user_id,count(user_id) from Confirmations
group by user_id
),
tab2 as
(
select user_id,
count(case when action='timeout' then user_id end)as TIMEOUT,
count(case when action='confirmed' then user_id end)as CONFIRMED,
count(case when action='timeout' then user_id end)+ count(case when action='confirmed' then user_id end) as TOTAL,
round(CAST(count(case when action='confirmed' then user_id end)as float)/CAST(count(case when action='timeout' then user_id end)+ count(case when action='confirmed' then user_id end) as float),2) as confirmation_rate
from tab0
group by user_id
)

select user_id,ifnull(confirmation_rate,0) as confirmation_rate from tab2;


