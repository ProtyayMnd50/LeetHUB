# Write your MySQL query statement below

-- with
-- t1 as(
-- select s.student_id ,s.student_name, e.subject_name, 
-- count(e.subject_name) as attended_exams
-- from Students s
-- left join Examinations e on e.student_id=s.student_id
-- group by subject_name,student_name
-- order by student_id,subject_name
-- )

-- select * from t1;
-- select t1.student_id,t1.student_name,t1.subject_name,sj.subject_name,t1.attended_exams from Subjects sj left join t1 on sj.subject_name=t1.subject_name
-- order by t1.student_id,t1.subject_name;


-- select s.student_id ,s.student_name, e.subject_name, 
-- count(e.subject_name) as attended_exams
-- from Students s
-- left join Examinations e on e.student_id=s.student_id
-- group by subject_name,student_name
-- order by student_id,subject_name;

-- select e.student_id ,e.subject_name, sj.subject_name from 
-- Subjects sj left join Examinations e on sj.subject_name=e.subject_name
-- order by e.student_id, e.subject_name
-- with t1 as(
-- select s.student_id , s.student_name,sj.subject_name from Students s  join Subjects sj
-- ),
-- t2 as
-- (
--     select * from Examinations
-- )

-- select t1.student_id,t1.student_name,t1.subject_name,t2.student_id,t2.subject_name from t1 left join t2 on t1.student_id=t2.student_id
-- group by ;

-- select * from t3;


SELECT 
    s.student_id,
    s.student_name,
    subj.subject_name,
    COALESCE(COUNT(e.subject_name), 0) AS attended_exams
FROM 
    Students s
CROSS JOIN 
    Subjects subj
LEFT JOIN 
    Examinations e 
ON 
    e.student_id = s.student_id 
    AND e.subject_name = subj.subject_name
GROUP BY 
    s.student_id, s.student_name, subj.subject_name
ORDER BY 
    s.student_id, subj.subject_name;

