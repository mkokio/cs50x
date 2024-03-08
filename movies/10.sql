SELECT  DISTINCT name FROM movies, people, ratings, directors WHERE movies.id = ratings.movie_id AND rating >= 9.0 AND people.id = directors.person_id AND directors.movie_id = movies.id;
