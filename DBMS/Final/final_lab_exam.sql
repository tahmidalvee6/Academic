-- Create Database
CREATE DATABASE IF NOT EXISTS iiuc_4dm;

-- Use Database
USE iiuc_4dm;

-- Create tables
CREATE TABLE IF NOT EXISTS C241135 (
    s_id INT PRIMARY KEY,
    s_name VARCHAR(50) NOT NULL,
    s_phone VARCHAR(50),
    s_address VARCHAR(50)
);

CREATE TABLE IF NOT EXISTS teacher1 (
    t_id INT PRIMARY KEY,
    t_name VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS teacher2 (
    T_id INT PRIMARY KEY,
    T_name VARCHAR(50) NOT NULL,
    T_dept VARCHAR(50),
    T_salary INT
);

CREATE TABLE IF NOT EXISTS students (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    class VARCHAR(10)
);

CREATE TABLE IF NOT EXISTS courses (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(50),
    student_id INT,
    FOREIGN KEY (student_id) REFERENCES students(student_id) ON DELETE SET NULL
);

-- Insert into tables
INSERT INTO C241135 (s_id, s_name, s_phone, s_address) VALUES 
    (101, 'Hasan', '123456789', 'DHK'),
    (102, 'Kamal', '987654321', 'CTG'),
    (103, 'Rony', NULL, 'DHK'),
    (104, 'Rakib', '234681369', 'COM'),
    (105, 'Hasan', '234681369', 'CTG');

INSERT INTO teacher1 (t_id, t_name) VALUES 
    (11, 'A'),
    (12, 'B'),
    (13, 'C');

INSERT INTO teacher2 (T_id, T_name, T_dept, T_salary) VALUES 
    (201, 'Azad', 'CSE', 1000),
    (202, 'Kamal', 'EEE', 2000),
    (203, 'Hasan', 'CE', 1000),
    (204, 'Kamal', 'EEE', 1000),
    (205, 'Rony', 'CSE', 2000),
    (206, 'Rakib', 'CSE', 4000);

INSERT INTO students (student_id, student_name, class) VALUES
    (1, 'Alice', '4DM'),
    (2, 'Bob', '4DM'),
    (3, 'Charlie', '4DM'),
    (4, 'David', '4DM');

INSERT INTO courses (course_id, course_name, student_id) VALUES
    (101, 'Database', 1),
    (102, 'Math', 1),
    (103, 'Physics', 2),
    (104, 'Chemistry', NULL);

-- ========================================
-- SELECT (Basic SELECT)
-- ========================================
SELECT * FROM C241135;
SELECT * FROM teacher1;
SELECT * FROM teacher2;
SELECT * FROM students;
SELECT * FROM courses;

-- ========================================
-- SELECT (Column Projection - specific columns only)
-- ========================================
SELECT s_id FROM C241135;
SELECT s_name FROM C241135;
SELECT s_phone FROM C241135;
SELECT s_address FROM C241135;

-- ========================================
-- SELECT (Conditional Selection - using WHERE)
-- ========================================
SELECT * FROM C241135 WHERE s_id = 102;
SELECT * FROM C241135 WHERE s_address = 'DHK';
SELECT s_id FROM C241135 WHERE s_name = 'Rakib';
SELECT s_name FROM C241135 WHERE s_id = 102;

-- ========================================
-- SELECT (Distinct Selection)
-- ========================================
SELECT DISTINCT s_address FROM C241135;

-- ========================================
-- SELECT (Column Manipulation)
-- ========================================
SELECT s_id + 5 FROM C241135;
SELECT s_id + 5 AS new_s_id FROM C241135;

-- ========================================
-- SELECT (Range and Set Conditions)
-- ========================================
SELECT * FROM C241135 WHERE s_id > 102;
SELECT * FROM C241135 WHERE s_id BETWEEN 102 AND 104;
SELECT * FROM C241135 WHERE s_id IN(101, 104);
SELECT * FROM C241135 WHERE s_id % 2 = 0;

-- ========================================
-- SELECT (Pattern Matching with LIKE)
-- ========================================
-- Names starting with 'K'
SELECT * FROM teacher2 WHERE UPPER(T_name) LIKE 'K%';

-- Names ending with 'L'
SELECT * FROM teacher2 WHERE UPPER(T_name) LIKE '%L';

-- Names starting with 'K' and ending with 'L'
SELECT * FROM teacher2 WHERE UPPER(T_name) LIKE 'K%L';

-- Names containing 'A'
SELECT * FROM teacher2 WHERE UPPER(T_name) LIKE '%A%';

-- Names containing 'A' followed by 'D'
SELECT * FROM teacher2 WHERE UPPER(T_name) LIKE '%A%D%';

-- Names with exactly 5 characters
SELECT * FROM teacher2 WHERE UPPER(T_name) LIKE '_____';

-- Specific characters at positions (A_D pattern)
SELECT * FROM teacher2 WHERE UPPER(T_name) LIKE 'A_D%';

-- Using REGEXP for character sets (MySQL alternative to [AHK]%)
SELECT * FROM teacher2 WHERE T_name REGEXP '^[AHK]';

-- Escape wildcard character
SELECT * FROM teacher2 WHERE T_name LIKE '%\\%%';

-- Case-insensitive search
SELECT * FROM teacher2 WHERE T_name LIKE '%kamal%';



-- ========================================
-- GROUP BY Queries
-- ========================================
-- Basic GROUP BY
SELECT T_dept FROM teacher2 WHERE T_id > 201 GROUP BY T_dept;

-- GROUP BY with COUNT
SELECT T_dept, COUNT(*) AS total_teachers FROM teacher2 WHERE T_id > 201 GROUP BY T_dept;

-- GROUP BY with SUM
SELECT T_dept, SUM(T_salary) AS Total_salary FROM teacher2 WHERE T_id > 201 GROUP BY T_dept;

-- GROUP BY with MIN
SELECT T_dept, MIN(T_salary) AS Min_salary FROM teacher2 WHERE T_id > 201 GROUP BY T_dept;

-- GROUP BY with MAX
SELECT T_dept, MAX(T_salary) AS Max_salary FROM teacher2 WHERE T_id > 201 GROUP BY T_dept;

-- GROUP BY with AVG
SELECT T_dept, AVG(T_salary) AS AVG_salary FROM teacher2 WHERE T_id > 201 GROUP BY T_dept;

-- Specific department max salary
SELECT T_dept, MAX(T_salary) AS Max_salary_CSE FROM teacher2 WHERE T_dept = 'CSE' GROUP BY T_dept;

-- GROUP BY with HAVING
SELECT T_dept, SUM(T_salary) AS total_salary FROM teacher2 GROUP BY T_dept HAVING SUM(T_salary) > 2000;

-- GROUP BY multiple columns
SELECT T_dept, T_salary, COUNT(*) AS count_teachers FROM teacher2 GROUP BY T_dept, T_salary;

-- GROUP BY with ORDER BY
SELECT T_dept, SUM(T_salary) AS total_salary FROM teacher2 GROUP BY T_dept ORDER BY total_salary DESC;

-- ========================================
-- ORDER BY Queries
-- ========================================
-- Ascending order
SELECT * FROM teacher2 WHERE T_dept = 'CSE' ORDER BY T_id ASC;

-- Descending order
SELECT * FROM teacher2 WHERE T_dept = 'CSE' ORDER BY T_id DESC;

-- Order by department
SELECT * FROM teacher2 ORDER BY T_dept DESC;

-- Multiple column ordering
SELECT * FROM teacher2 ORDER BY T_salary DESC, T_dept ASC;

-- Order by calculated column
SELECT T_name, T_salary * 2 AS double_salary FROM teacher2 ORDER BY double_salary DESC;

-- Order by string length
SELECT *, LENGTH(T_name) AS name_length FROM teacher2 ORDER BY LENGTH(T_name) ASC;

-- Random order
SELECT * FROM teacher2 ORDER BY RAND();

-- Custom ordering with CASE
SELECT * FROM teacher2 
ORDER BY CASE WHEN T_dept = 'CSE' THEN 1 ELSE 2 END ASC, T_salary DESC;

-- Subquery with ORDER and LIMIT
SELECT * FROM (SELECT * FROM teacher2 ORDER BY T_salary DESC LIMIT 3) AS t;

-- ========================================
-- HAVING Query (Fixed)
-- ========================================
SELECT T_dept, AVG(T_salary) AS AVG_salary 
FROM teacher2 
GROUP BY T_dept 
HAVING COUNT(*) > 1;

-- ========================================
-- ALTER TABLE
-- ========================================
ALTER TABLE C241135 ADD COLUMN s_cgpa DECIMAL(3,2);
ALTER TABLE C241135 DROP COLUMN s_cgpa;

-- ========================================
-- UPDATE DATA
-- ========================================
UPDATE C241135 SET s_name = 'Abid' WHERE s_id = 105;

-- ========================================
-- DELETE DATA
-- ========================================
DELETE FROM C241135 WHERE s_id = 105;

-- ========================================
-- TRUNCATE TABLE
-- ========================================
TRUNCATE TABLE teacher1;

-- ========================================
-- JOIN TABLES
-- ========================================
-- INNER JOIN
SELECT s.student_name, c.course_name 
FROM students s 
INNER JOIN courses c ON s.student_id = c.student_id;

-- LEFT JOIN
SELECT s.student_name, c.course_name 
FROM students s 
LEFT JOIN courses c ON s.student_id = c.student_id;

-- RIGHT JOIN
SELECT s.student_name, c.course_name 
FROM students s 
RIGHT JOIN courses c ON s.student_id = c.student_id;

-- FULL OUTER JOIN (MySQL simulation)
SELECT s.student_name, c.course_name
FROM students s
LEFT JOIN courses c ON s.student_id = c.student_id
UNION
SELECT s.student_name, c.course_name
FROM students s
RIGHT JOIN courses c ON s.student_id = c.student_id;

-- CROSS JOIN
SELECT s.student_name, c.course_name 
FROM students s 
CROSS JOIN courses c;

-- SELF JOIN
SELECT s1.student_name AS student1, s2.student_name AS student2 
FROM students s1 
INNER JOIN students s2 ON s1.student_id < s2.student_id;

-- NATURAL JOIN
SELECT * FROM students NATURAL JOIN courses;

-- JOIN USING
SELECT * FROM students s 
INNER JOIN courses c USING(student_id);

-- ANTI JOIN (students without courses)
SELECT s.student_name 
FROM students s 
LEFT JOIN courses c ON s.student_id = c.student_id 
WHERE c.course_id IS NULL;

-- SEMI JOIN (students with courses)
SELECT s.student_name 
FROM students s 
WHERE s.student_id IN (SELECT student_id FROM courses WHERE student_id IS NOT NULL);

-- ========================================
-- DROP TABLES (Disable foreign key checks first)
-- ========================================
SET FOREIGN_KEY_CHECKS = 0;

DROP TABLE IF EXISTS courses;
DROP TABLE IF EXISTS students;
DROP TABLE IF EXISTS teacher2;
DROP TABLE IF EXISTS teacher1;
DROP TABLE IF EXISTS C241135;

SET FOREIGN_KEY_CHECKS = 1;

-- ========================================
-- SQL Query Execution Order
-- ========================================
-- SELECT -> FROM -> WHERE -> GROUP BY -> HAVING -> ORDER BY
-- Note: <> is the 'not equal' operator
