# Write your MySQL query statement below
with sel(vid,cid)as
(select vst.visit_id,vst.customer_id from
Visits vst left join Transactions trn 
on vst.visit_id=trn.visit_id
where trn.visit_id is null
)

select cid as customer_id,count(cid) as count_no_trans
from sel
group by cid;