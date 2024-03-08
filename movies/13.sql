SELECT name FROM people, movies, stars
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id AND movie.id IN
(SELECT movies.id FROM people, movies, stars
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id
AND name ='Kevin Bacon'
AND birth = 1958);
