select distinct p1.name from people p
join stars s on p.id = s.person_id
join stars s1 on s.movie_id = s1.movie_id
join people p1 on s1.person_id = p1.id
where p.name = "Kevin Bacon" and p.birth = 1958 and p1.name != "Kevin Bacon";
