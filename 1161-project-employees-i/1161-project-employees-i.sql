# Write your MySQL query statement below
with tab0
as(
select pr.project_id,pr.employee_id,emp.experience_years from Project pr left join Employee emp
on pr.employee_id=emp.employee_id
)
select project_id,round(avg(experience_years),2)as average_years 
from tab0
group by project_id;