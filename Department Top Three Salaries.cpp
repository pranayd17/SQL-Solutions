WITH cte AS
(select e.id as empid,e.name as Employee,e.salary as Salary,
d.name as Department,
dense_rank() OVER (partition by e.departmentId order by salary desc) as rnk
from Employee e left join Department d
on e.departmentId=d.id)

select Department, Employee, Salary
from cte
where rnk<=3
