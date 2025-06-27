# Write your MySQL query statement below
(
    select u.name as results
    from Users u
    join MovieRating m
    on u.user_id = m.user_id     
    group by u.user_id     
    ORDER BY COUNT(*) DESC, name ASC
    limit 1
) 
union all

(
    select title as results
    from Movies m
    join MovieRating mr
    on m.movie_id = mr.movie_id   
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29' 
    group by m.movie_id 
    order by avg(rating) desc , title asc
    limit 1
) ;