# Write your MySQL query statement below
with n1 as(
    select * ,
    DENSE_RANK() OVER (PARTITION BY departmentId  ORDER BY salary DESC) AS rank1  
    from Employee 
)
select d.name as Department ,n1.name as Employee , n1.Salary 
from n1
join Department d
on n1.departmentId  = d.id 
where n1.rank1 <= 3
order by d.name , n1.rank1

-- select * from n1;