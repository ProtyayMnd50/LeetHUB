# Write your MySQL query statement below
SELECT nw.id AS Id
FROM Weather prev
JOIN Weather nw
ON nw.recordDate = DATE_ADD(prev.recordDate, INTERVAL 1 DAY)
WHERE nw.temperature > prev.temperature;
