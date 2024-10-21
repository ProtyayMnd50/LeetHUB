-- with tab0 as
-- (
-- select sn.user_id,cnf.action from
-- Signups sn left join Confirmations cnf
-- on sn.user_id=cnf.user_id
-- ),
-- tab1 as
-- (
-- select user_id,count(user_id) from Confirmations
-- group by user_id
-- ),
-- tab2 as
-- (
-- select user_id,
-- count(case when action='timeout' then user_id end)as TIMEOUT,
-- count(case when action='confirmed' then user_id end)as CONFIRMED,
-- count(case when action='timeout' then user_id end)+ count(case when action='confirmed' then user_id end) as TOTAL,
-- (CAST(count(case when action='confirmed' then user_id end)as float)/CAST(count(case when action='timeout' then user_id end)+ count(case when action='confirmed' then user_id end) as float)) as confirmation_rate
-- from tab0
-- group by user_id
-- )

-- select user_id,ifnull(confirmation_rate,0) as confirmation_rate from tab2;

WITH tab0 AS (
    SELECT sn.user_id, cnf.action 
    FROM Signups sn 
    LEFT JOIN Confirmations cnf ON sn.user_id = cnf.user_id
),
tab1 AS (
    SELECT user_id, COUNT(user_id) AS count_user_id 
    FROM Confirmations 
    GROUP BY user_id
),
tab2 AS (
    SELECT user_id,
           COUNT(CASE WHEN action = 'timeout' THEN user_id END) AS TIMEOUT,
           COUNT(CASE WHEN action = 'confirmed' THEN user_id END) AS CONFIRMED,
           COUNT(CASE WHEN action = 'timeout' THEN user_id END) + COUNT(CASE WHEN action = 'confirmed' THEN user_id END) AS TOTAL,
           CASE 
               WHEN COUNT(CASE WHEN action = 'timeout' THEN user_id END) + COUNT(CASE WHEN action = 'confirmed' THEN user_id END) = 0 THEN 0
               ELSE ROUND(
                   CAST(COUNT(CASE WHEN action = 'confirmed' THEN user_id END) AS FLOAT) / 
                   CAST(COUNT(CASE WHEN action = 'timeout' THEN user_id END) + COUNT(CASE WHEN action = 'confirmed' THEN user_id END) AS FLOAT), 2
               )
           END AS confirmation_rate
    FROM tab0
    GROUP BY user_id
)

SELECT user_id, IFNULL(confirmation_rate, 0) AS confirmation_rate 
FROM tab2;

