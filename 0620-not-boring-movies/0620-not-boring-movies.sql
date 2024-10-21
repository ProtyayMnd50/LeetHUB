# Write your MySQL query statement below
with tab1 as
(select * from
Cinema where id%2=1 and description not in('boring')
)
select * from tab1 order by rating desc;
