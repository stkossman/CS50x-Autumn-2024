select p.name from people p
join stars s on p.id = s.person_id
join movies m on s.movie_id = m.id
where m.title = "Toy Story";
