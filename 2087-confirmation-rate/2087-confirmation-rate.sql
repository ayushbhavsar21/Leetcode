SELECT 
  a.user_id, 
  ROUND( IF(COUNT(b.action) = 0, 0, SUM(b.action = 'confirmed') / COUNT(b.action) ), 2) AS confirmation_rate
FROM Signups a
LEFT JOIN Confirmations b 
  ON a.user_id = b.user_id
GROUP BY a.user_id
ORDER BY confirmation_rate;
