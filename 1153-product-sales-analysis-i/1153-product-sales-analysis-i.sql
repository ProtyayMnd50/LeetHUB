# Write your MySQL query statement below
select pr.product_name,sl.year,sl.price from Sales sl join product pr
on sl.product_id=pr.product_id;