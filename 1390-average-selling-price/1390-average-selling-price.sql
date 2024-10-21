WITH tab1 AS (
    SELECT pr.product_id, pr.price, us.units 
    FROM Prices pr 
    LEFT JOIN UnitsSold us ON pr.product_id = us.product_id
    AND us.purchase_date >= pr.start_date 
    AND us.purchase_date <= pr.end_date
),
tab2 AS (
    SELECT product_id,
           SUM(price * COALESCE(units, 0)) AS tot,
           COUNT(product_id) AS count_product_id,
           SUM(COALESCE(units, 0)) AS den  
    FROM tab1
    GROUP BY product_id
)

SELECT product_id,
       COALESCE(ROUND((tot / NULLIF(den, 0)), 2), 0) AS average_price 
FROM tab2
ORDER BY product_id;  -- To maintain a clear order in output
