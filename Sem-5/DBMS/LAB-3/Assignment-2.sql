-- 1. Create Database
CREATE DATABASE assignment_2;
USE assignment_2;

-- 2. Create Tables
CREATE TABLE films (
  film_id INT AUTO_INCREMENT PRIMARY KEY,
  title VARCHAR(100) NOT NULL,
  genre VARCHAR(50) NOT NULL,
  release_year INT NOT NULL,
  ratings INT NOT NULL,
  duration_minutes INT NOT NULL,
  available_on_dvd BOOLEAN DEFAULT TRUE
);

CREATE TABLE directors (
  director_id INT AUTO_INCREMENT PRIMARY KEY,
  fname VARCHAR(50) NOT NULL,
  lname VARCHAR(50) NOT NULL,
  birth_year INT CHECK (birth_year > 1900),
  nationality VARCHAR(100) NOT NULL
);

CREATE TABLE members (
  member_id INT AUTO_INCREMENT PRIMARY KEY,
  fname VARCHAR(50) NOT NULL,
  lname VARCHAR(50) NOT NULL,
  address VARCHAR(100) NOT NULL,
  city VARCHAR(50) NOT NULL,
  zip_code VARCHAR(10) NOT NULL,
  DOB DATE NOT NULL,
  join_date DATE NOT NULL
);

-- 3. Insert Sample Data for films
INSERT INTO films (title, genre, release_year, ratings, duration_minutes, available_on_dvd) VALUES
('Inception', 'Sci-Fi', 2010, 9, 148, TRUE),
('Pulp Fiction', 'Crime', 1994, 5, 154, TRUE),
('The Prestige', 'Thriller', 2006, 4, 130, TRUE),
('Shutter Island', 'Thriller', 2010, 3, 138, TRUE),
('Parasite', 'Drama', 2019, 4, 132, TRUE),
('Titanic', 'Romance', 1997, 5, 195, TRUE),
('Terminator', 'Action', 1991, 4, 137, TRUE),
('Batman Begins', 'Action', 2005, 8, 140, TRUE);

-- 4. Insert Sample Data for members
INSERT INTO members (fname, lname, address, city, zip_code, DOB, join_date) VALUES
('Amit', 'Sharma', 'MG Road', 'Mumbai', '490001', '2000-06-15', '2015-01-10'),
('Priya', 'Singh', 'Park Street', 'Delhi', '490002', '1995-02-20', '2015-01-25'),
('Rahul', 'Patel', 'Marine Drive', 'Mumbai', '400005', '1990-03-01', '2015-01-30'),
('Sneha', 'Kapoor', 'Bandra', 'Mumbai', '490500', '2003-11-11', '2019-07-07'),
('Vikram', 'Rao', 'Andheri', 'Mumbai', '495001', '2001-08-09', '2018-12-20'),
('Neha', 'Mehta', 'Civil Lines', 'Mumbai', '490700', '2005-04-12', '2014-11-15'),
('Arjun', 'Verma', 'MG Road', 'Pune', '497001', '1987-09-15', '2020-06-10'),
('Karan', 'Malhotra', 'Connaught Place', 'Delhi', '491111', '1998-12-02', '2016-02-14'),
('Riya', 'Chopra', 'Powai', 'Mumbai', '490333', '1999-07-21', '2017-03-18');


-- 1. Find names and address of members who joined in January 2015
SELECT fname, lname, address
FROM members
WHERE YEAR(join_date) = 2015 AND MONTH(join_date) = 1;

-- 2. Find names of members over 16 years of age, and lives in Mumbai
SELECT fname, lname
FROM members
WHERE TIMESTAMPDIFF(YEAR, DOB, CURDATE()) > 16
  AND city = 'Mumbai';

-- 3. Find film name, rating where rating is between 3 and 5 and available on DVD
SELECT title, ratings
FROM films
WHERE ratings BETWEEN 3 AND 5
  AND available_on_dvd = TRUE;

-- 4. Produce the list of films of any decade except 1980s whose names are between P & T
SELECT title, release_year
FROM films
WHERE release_year NOT BETWEEN 1980 AND 1989
  AND title BETWEEN 'P' AND 'T';

-- 5. List all members names and zip codes, where zip code starts with 49
SELECT fname, lname, zip_code
FROM members
WHERE zip_code LIKE '49%';

-- 6. List of all members sorted in descending order by DoB
SELECT fname, lname, DOB
FROM members
ORDER BY DOB DESC;

-- 7. Which members joined before Dec 31, 2020, order the results by last_name and first_name
SELECT fname, lname, join_date
FROM members
WHERE join_date < '2020-12-31'
ORDER BY lname, fname;


