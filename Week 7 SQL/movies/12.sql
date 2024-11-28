select m.title from movies m
join stars s on m.id = s.movie_id
join people p on s.person_id = p.id
where p.name in ("Bradley Cooper", "Jennifer Lawrence")
group by m.title
having count(distinct p.name) = 2;
