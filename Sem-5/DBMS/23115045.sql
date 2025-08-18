CREATE DATABASE `23115045`;
USE `23115045`;

CREATE TABLE pupil(Std_id INT auto_increment primary key,
					fname varchar(50) not null,
                    lname varchar(50) not null,
                    age int(10) check(age>5),
                    email varchar(100) unique);
                    
INSERT INTO pupil(fname,lname,age,email)
	VALUES('x','y',18,'xyz@gmail.com'),
		('w','z',17,'abc@gmail.com');
        
SELECT * FROM pupil;

RENAME TABLE pupil to pupil1;

ALTER TABLE pupil1 ADD column enrollment INT(30);
ALTER TABLE pupil1 RENAME column fname TO f1name;
ALTER TABLE pupil1 MODIFY column fname CHAR(50);
ALTER TABLE pupil1 DROP column age;

DROP table pupil1;
DROP database `23115045`



