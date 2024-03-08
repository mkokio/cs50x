SELECT title FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id
WHERE id IN
(SELECT id FROM )
AND name = 'Bradley Cooper';
AND name IN ('Jennifer Lawrence');

list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.

    Your query should output a table with a single column for the title of each movie.
    You may assume that there is only one person in the database with the name Bradley Cooper.
    You may assume that there is only one person in the database with the name Jennifer Lawrence.
