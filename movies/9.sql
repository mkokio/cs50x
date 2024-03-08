SELECT DISTINCT name FROM movies, stars, people WHERE movies.id = stars.movie_id AND stars.person_id = people.id AND movies.year = 2014 ORDER BY people.birth;
