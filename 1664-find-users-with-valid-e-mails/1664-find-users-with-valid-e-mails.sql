SELECT user_id, name, mail
FROM Users
WHERE mail COLLATE utf8mb3_bin REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$';
