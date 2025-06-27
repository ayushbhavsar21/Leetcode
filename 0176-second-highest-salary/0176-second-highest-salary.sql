# Write your MySQL query statement below
select distinct salary as SecondHighestSalary 
from Employee 
union all

select null as SecondHighestSalary
union all

select null as SecondHighestSalary


order by SecondHighestSalary desc
limit 1
offset 1;