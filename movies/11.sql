SELECT title, rating FROM movies, stars, people, ratings WHERE movies.id = stars.movie_id AND people.id = stars.person_id AND people.name = 'Chadwick Boseman' ORDER BY ratings.rating DESC;

list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in,
starting with the highest rated.

    Your query should output a table with a single column for the title of each movie.
    You may assume that there is only one person in the database with the name Chadwick Boseman.
