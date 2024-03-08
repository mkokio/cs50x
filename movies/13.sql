SELECT name FROM people, movie, stars
(SELECT title FROM people, movies, stars
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id
AND name ='Kevin Bacon'
AND birth = 1958);

list the names of all people who starred in a movie in which Kevin Bacon also starred.

    Your query should output a table with a single column for the name of each person.
    There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
    Kevin Bacon himself should not be included in the resulting list.
