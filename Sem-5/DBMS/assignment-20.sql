CREATE DATABASE `assignment-20`;
USE `assignment-20`;

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


INSERT INTO members VALUES
(1, 'Alice', 'Patel', '123 Elm St', 'Mumbai', '49001', '2005-05-10', '2015-01-15'),
(2, 'Bob', 'Sharma', '456 Maple Rd', 'Mumbai', '49123', '2008-07-20', '2016-03-10'),
(3, 'Carol', 'Mehta', '789 Oak Ln', 'Delhi', '48055', '1990-12-01', '2014-11-25'),
(4, 'David', 'Yadav', '321 Pine Dr', 'Mumbai', '49599', '2000-02-28', '2021-06-05'),
(5, 'Eve', 'Singh', '654 Cedar Pl', 'Mumbai', '49212', '2010-09-30', '2020-12-15');


INSERT INTO films VALUES
(101, 'Pioneer', 'Sci-Fi', 1975, 4.2, 130, TRUE),
(102, 'Quantum Quest', 'Adventure', 1985, 3.8, 110, TRUE),
(103, 'Rocket To The Moon', 'Sci-Fi', 1990, 4.7, 115, FALSE),
(104, 'Tiger Hunt', 'Action', 2005, 2.9, 105, TRUE),
(105, 'Phoenix Rising', 'Drama', 2010, 3.5, 140, TRUE),
(106, 'Zodiac Mystery', 'Thriller', 1979, 4.0, 125, TRUE);

-- Query 1:
SELECT fname, lname, address
FROM members
WHERE MONTH(join_date) = 1 AND YEAR(join_date) = 2015;

-- Query 2: 
SELECT fname, lname
FROM members
WHERE city = 'Mumbai'
  AND TIMESTAMPDIFF(YEAR, DOB, CURDATE()) > 16;

-- Query 3: Film name and rating where rating is between 3 and 5 and available on DVD
SELECT title, ratings
FROM films
WHERE ratings BETWEEN 3 AND 5
  AND available_on_dvd = TRUE;

-- Query 4: List of films of any decade except 1980s whose names are between P & T
SELECT title, release_year
FROM films
WHERE release_year NOT BETWEEN 1980 AND 1989
  AND title BETWEEN 'P' AND 'Tz';

-- Query 5: List all members names and zip codes, where zip code starts with 49
SELECT fname, lname, zip_code
FROM members
WHERE zip_code LIKE '49%';

-- Query 6: List of all members sorted in descending order by DoB
SELECT fname, lname, DOB
FROM members
ORDER BY DOB DESC;

-- Query 7: Which members joined before Dec 31st, 2020, order the results by last_name and first_name
SELECT fname, lname, join_date
FROM members
WHERE join_date < '2020-12-31'
ORDER BY lname ASC, fname ASC;
