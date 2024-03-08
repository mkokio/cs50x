
write a SQL query to determine the number of movies with an IMDb rating of 10.0.

Your query should output a table with a single column and a single row
(not counting the header) containing the number of movies with a 10.0 rating.

CREATE TABLE movies (
    id INTEGER,
    title TEXT NOT NULL,
    year NUMERIC,
    PRIMARY KEY(id)
);

CREATE TABLE ratings (
    movie_id INTEGER NOT NULL,
    rating REAL NOT NULL,
    votes INTEGER NOT NULL,
    FOREIGN KEY(movie_id) REFERENCES movies(id)
