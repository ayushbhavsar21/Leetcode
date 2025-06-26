/* Write your T-SQL query statement below */
select
    'Low Salary' as category,
    sum(if(a.income < 20000, 1, 0)) as accounts_count
from 
    Accounts a

union 

select
    'Average Salary' as  category,
    sum(if(a.income between 20000 and 50000, 1, 0))as accounts_count
from 
    Accounts a

union 

select
    'High Salary' as  category,
    sum(if(a.income > 50000, 1, 0)) as accounts_count
from 
    Accounts a