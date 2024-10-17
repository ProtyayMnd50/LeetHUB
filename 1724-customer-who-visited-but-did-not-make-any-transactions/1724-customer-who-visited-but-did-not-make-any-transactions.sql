# Write your MySQL query statement below
select customer_id, count(customer_id) as count_no_trans from
(select vst.visit_id,vst.customer_id from
Visits vst left join Transactions trn 
on vst.visit_id=trn.visit_id
where trn.transaction_id is null
) tmp
group by customer_id;