SELECT name FROM people WHERE people.id IN
(SELECT movies.id, people.name FROM people, movies, stars
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id
AND name ='Kevin Bacon'
AND birth = 1958);
