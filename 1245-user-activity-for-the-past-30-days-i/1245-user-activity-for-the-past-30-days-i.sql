SELECT 
    activity_date AS day,
    COUNT(distinct user_id) AS active_users
FROM 
    Activity
WHERE 
    DATEDIFF('2019-07-27', activity_date) BETWEEN 0 AND 29
GROUP BY 
    activity_date
ORDER BY 
    activity_date asc ;

