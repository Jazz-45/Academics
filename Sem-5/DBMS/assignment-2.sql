CREATE DATABASE `assignment-2`;
USE `assignment-2`;

CREATE TABLE films (
    film_id INT PRIMARY KEY,
    title VARCHAR(100),
    genre VARCHAR(50),
    release_year INT,
    ratings DECIMAL(2,1),
    duration_minutes INT,
    available_on_dvd BOOLEAN
);

CREATE TABLE directors (
    director_id INT PRIMARY KEY,
    fname VARCHAR(50),
    lname VARCHAR(50),
    birth_year INT,
    nationality VARCHAR(50)
);

CREATE TABLE members (
    member_id INT PRIMARY KEY,
    fname VARCHAR(50),
    lname VARCHAR(50),
    address VARCHAR(100),
    city VARCHAR(50),
    zip_code VARCHAR(10),
    DOB DATE,
    join_date DATE
);

SELECT fname, lname, address
FROM members
WHERE MONTH(join_date) = 1 AND YEAR(join_date) = 2015;

SELECT fname, lname
FROM members
WHERE city = 'Mumbai'
  AND TIMESTAMPDIFF(YEAR, DOB, CURDATE()) > 16;

SELECT title, ratings
FROM films
WHERE ratings BETWEEN 3 AND 5
  AND available_on_dvd = TRUE;

SELECT title, release_year
FROM films
WHERE release_year NOT BETWEEN 1980 AND 1989
  AND title BETWEEN 'P' AND 'Tz';

SELECT fname, lname, zip_code
FROM members
WHERE zip_code LIKE '49%';

SELECT fname, lname, DOB
FROM members
ORDER BY DOB DESC;

SELECT fname, lname, join_date
FROM members
WHERE join_date < '2020-12-31'
ORDER BY lname ASC, fname ASC;
