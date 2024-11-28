select p.name from people p
join directors d on p.id = d.person_id
join movies m on d.movie_id = m.id
join ratings r on r.movie_id = m.id
where m.id == d.movie_id and r.rating >= 9;
