# Write your MySQL query statement below
with n1 as (
    select distinct visited_on, 
    sum(amount) over(order by visited_on range between interval 6 day preceding and current row) as amount,
    min(visited_on) over() 1st_date
    from customer
)
select visited_on, amount, round(amount/7,2) average_amount from n1
where visited_on >= 1st_date+6