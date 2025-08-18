CREATE DATABASE film_library_2;
USE film_library_2;

CREATE TABLE directors (
  director_id INT AUTO_INCREMENT PRIMARY KEY,
  fname VARCHAR(50) NOT NULL,
  lname VARCHAR(50) NOT NULL,
  birth_year INT CHECK (birth_year > 1900),
  nationality VARCHAR(100) NOT NULL
);

CREATE TABLE films (
  film_id INT AUTO_INCREMENT PRIMARY KEY,
  title VARCHAR(50) NOT NULL,
  genre VARCHAR(50) NOT NULL,
  release_year INT NOT NULL,
  ratings INT NOT NULL,
  duration_minutes INT NOT NULL
);

INSERT INTO directors (fname, lname, birth_year, nationality) VALUES
('Christopher', 'Nolan', 1970, 'British-American'),
('Quentin', 'Tarantino', 1963, 'American'),
('Greta', 'Gerwig', 1983, 'American'),
('Hayao', 'Miyazaki', 1941, 'Japanese'),
('Alfonso', 'Cuarón', 1961, 'Mexican');

-- 5. Insert sample data into films
INSERT INTO films (title, genre, release_year, ratings, duration_minutes) VALUES
('Inception', 'Sci-Fi', 2010, 9, 148),
('Pulp Fiction', 'Crime', 1994, 9, 154),
('Barbie', 'Fantasy', 2023, 8, 114),
('Spirited Away', 'Animation', 2001, 10, 125),
('Gravity', 'Sci-Fi', 2013, 8, 91);

ALTER TABLE films
CHANGE ratings imdb_ratings INT NOT NULL;

SELECT * FROM films;

ALTER TABLE films
ADD CONSTRAINT title UNIQUE (title);

INSERT INTO films (title, genre, release_year, imdb_ratings, duration_minutes) VALUES
('Inception', 'Sci-Fi', 2010, 9, 148);
SELECT * FROM films;
SELECT * FROM directors;

