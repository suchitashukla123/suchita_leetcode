-- Write your PostgreSQL query statement below
select Department , Employee , Salary from (
    select d.name as Department,
           e.name as Employee,
           e.salary as Salary,
           dense_rank() over (
            partition by departmentID
            order by salary desc
           )as rank
           from Employee e 
           left join Department as d
           on e.departmentId = d.id
) t 
where rank <=3