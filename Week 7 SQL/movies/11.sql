select m.title from movies m
join ratings r on m.id = r.movie_id
join stars s on m.id = s.movie_id
join people p on s.person_id = p.id
where p.name = 'Chadwick Boseman'
order by r.rating desc
limit 5;
