# Write your MySQL query statement below
select p.firstname as firstName, p.lastname as lastName , a.city as city , a.state from Person as p
left join Address as a 
on p.personId = a.personId