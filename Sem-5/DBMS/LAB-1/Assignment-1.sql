-- 1. Create Database
CREATE DATABASE film_library;
USE film_library;

-- 2. Create Tables
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
  duration_minutes INT NOT NULL,
  director_id INT,
  FOREIGN KEY (director_id) REFERENCES directors(director_id)
);

-- 3. Insert Sample Data
INSERT INTO directors (fname, lname, birth_year, nationality) VALUES
('Christopher', 'Nolan', 1970, 'British-American'),
('Quentin', 'Tarantino', 1963, 'American'),
('Greta', 'Gerwig', 1983, 'American'),
('Hayao', 'Miyazaki', 1941, 'Japanese'),
('Alfonso', 'Cuarón', 1961, 'Mexican');

INSERT INTO films (title, genre, release_year, ratings, duration_minutes, director_id) VALUES
('Inception', 'Sci-Fi', 2010, 9, 148, 1),
('Pulp Fiction', 'Crime', 1994, 9, 154, 2),
('Barbie', 'Fantasy', 2023, 8, 114, 3),
('Spirited Away', 'Animation', 2001, 10, 125, 4),
('Gravity', 'Sci-Fi', 2013, 8, 91, 5);

-- 4. Add UNIQUE Constraint on (title, release_year)
ALTER TABLE films
ADD CONSTRAINT unique_title_year UNIQUE (title, release_year);

-- 5. Try inserting duplicate (will throw error)
 INSERT INTO films (title, genre, release_year, ratings, duration_minutes, director_id) VALUES
 ('Inception', 'Sci-Fi', 2010, 9, 148, 1);

-- 6. Rename ratings to imdb_ratings
ALTER TABLE films
CHANGE ratings imdb_ratings INT NOT NULL;

-- 7. Display films with release year and director name
SELECT f.title, f.release_year, CONCAT(d.fname, ' ', d.lname) AS director_name
FROM films f
JOIN directors d ON f.director_id = d.director_id;

