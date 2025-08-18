CREATE DATABASE film_library;
USE film_library;

CREATE TABLE films(film_id INT auto_increment primary key,
					title varchar(50) not null,
                    genre varchar(50) not null,
                    release_year int(10) not null,
                    ratings int not null,
                    duration_minutes INT not null);
CREATE TABLE directors(director_id INT auto_increment primary key,
					fname varchar(50) not null,
                    lname varchar(50) not null,
                    birth_year int(10) check(birth_year>1900),
                    nationality varchar(100) not null);
                    
INSERT INTO films (title, genre, release_year, ratings, duration_minutes) VALUES
('Inception', 'Sci-Fi', 2010, 9, 148),
('Pulp Fiction', 'Crime', 1994, 9, 154),
('Barbie', 'Fantasy', 2023, 8, 114),
('Spirited Away', 'Animation', 2001, 10, 125),
('Gravity', 'Sci-Fi', 2013, 8, 91);

                    
                    

                    
                    