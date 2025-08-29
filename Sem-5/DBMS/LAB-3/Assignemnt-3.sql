-- 1. Create Database
CREATE DATABASE assignment_3;
USE assignment_3;

-- 2. Create Tables
CREATE TABLE Dept (
  deptno INT PRIMARY KEY,
  deptname VARCHAR(50) NOT NULL,
  locno INT NOT NULL
);

CREATE TABLE Location (
  locno INT PRIMARY KEY,
  city VARCHAR(50) NOT NULL
);

CREATE TABLE Salgrade (
  grade INT PRIMARY KEY,
  lowsal INT NOT NULL,
  hisal INT NOT NULL
);

CREATE TABLE Emp (
  empno INT PRIMARY KEY,
  empname VARCHAR(50) NOT NULL,
  hire_date DATE NOT NULL,
  mgr INT,
  job VARCHAR(50) NOT NULL,
  salary INT NOT NULL,
  commission INT,
  deptno INT,
  grade INT,
  FOREIGN KEY (deptno) REFERENCES Dept(deptno),
  FOREIGN KEY (grade) REFERENCES Salgrade(grade)
);

-- 3. Insert Sample Data
-- Locations
INSERT INTO Location VALUES
(10, 'Toronto'),
(20, 'New York'),
(30, 'London'),
(40, 'Paris'),
(50, 'Tokyo'),
(60, 'Sydney'),
(70, 'Berlin'),
(80, 'Mumbai'),
(90, 'Dubai'),
(100, 'Singapore');

-- Departments
INSERT INTO Dept VALUES
(10, 'HR', 10),
(20, 'Finance', 20),
(30, 'IT', 30),
(40, 'Marketing', 40),
(50, 'Operations', 50),
(60, 'Admin', 60),
(70, 'Research', 70),
(80, 'Sales', 80),
(90, 'Support', 90),
(100, 'Legal', 100);

-- Salary Grades
INSERT INTO Salgrade VALUES
(1, 1000, 3000),
(2, 3001, 5000),
(3, 5001, 7000),
(4, 7001, 9000),
(5, 9001, 12000),
(6, 12001, 15000),
(7, 15001, 20000),
(8, 20001, 30000),
(9, 30001, 50000),
(10, 50001, 100000);

-- Employees
INSERT INTO Emp VALUES
(101, 'Smith', '2015-01-10', NULL, 'Manager', 12000, NULL, 10, 5),
(102, 'Allen', '2016-03-15', 101, 'Analyst', 8000, 500, 20, 4),
(103, 'Ward', '2017-06-20', 101, 'Clerk', 2000, NULL, 20, 1),
(104, 'Jones', '2014-09-25', 101, 'Manager', 15000, 1000, 30, 6),
(105, 'Martin', '2018-11-30', 104, 'Salesman', 4000, 800, 80, 2),
(106, 'Blake', '2019-01-05', 104, 'Salesman', 4500, 700, 80, 2),
(107, 'Clark', '2016-07-22', 101, 'Manager', 20000, NULL, 40, 7),
(108, 'Scott', '2020-10-10', 107, 'Analyst', 7000, NULL, 40, 3),
(109, 'Davies', '2012-02-28', NULL, 'Director', 50000, NULL, 50, 9),
(110, 'Adams', '2021-04-01', 109, 'Clerk', 2500, NULL, 50, 1);

-- =====================================================
-- Queries
-- =====================================================

-- 1. Name, department number, and department name for all employees
SELECT e.empname, e.deptno, d.deptname
FROM Emp e
JOIN Dept d ON e.deptno = d.deptno;

-- 2. List all jobs in department 80 with location
SELECT DISTINCT e.job, d.deptname, l.city
FROM Emp e
JOIN Dept d ON e.deptno = d.deptno
JOIN Location l ON d.locno = l.locno
WHERE e.deptno = 80;

-- 3. Employee’s name, department name, location ID, and city of employees who earn a commission
SELECT e.empname, d.deptname, d.locno, l.city
FROM Emp e
JOIN Dept d ON e.deptno = d.deptno
JOIN Location l ON d.locno = l.locno
WHERE e.commission IS NOT NULL;

-- 4. Name, job, deptno, and deptname of employees who work in Toronto
SELECT e.empname, e.job, e.deptno, d.deptname
FROM Emp e
JOIN Dept d ON e.deptno = d.deptno
JOIN Location l ON d.locno = l.locno
WHERE l.city = 'Toronto';

-- 5. Employee’s name & number along with their manager’s name & number
SELECT e.empname AS Employee, e.empno AS Emp_No,
       m.empname AS Manager, m.empno AS Mgr_No
FROM Emp e
LEFT JOIN Emp m ON e.mgr = m.empno;

-- 6. Employees who work in same department as another employee
SELECT e1.empname, e1.deptno, e2.empname AS Colleague
FROM Emp e1
JOIN Emp e2 ON e1.deptno = e2.deptno
WHERE e1.empno <> e2.empno
ORDER BY e1.deptno;

-- 7. Name, job, department name, salary, and grade for all employees
SELECT e.empname, e.job, d.deptname, e.salary, s.grade
FROM Emp e
JOIN Dept d ON e.deptno = d.deptno
JOIN Salgrade s ON e.grade = s.grade;

-- 8. Name and hire date of employees hired after Davies
SELECT e.empname, e.hire_date
FROM Emp e
WHERE e.hire_date > (SELECT hire_date FROM Emp WHERE empname = 'Davies');

