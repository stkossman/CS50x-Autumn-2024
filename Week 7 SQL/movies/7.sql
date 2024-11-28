select m.title, r.rating from movies m
join ratings r on m.id = r.movie_id
where m.year = 2010
order by r.rating desc, m.title asc;
