CREATE TABLE department (
    dept_id        INT PRIMARY KEY,
    dept_name      VARCHAR(100) NOT NULL UNIQUE,
    faculty        VARCHAR(100)
);

CREATE TABLE student (
    student_id     INT PRIMARY KEY,
    first_name     VARCHAR(50) NOT NULL,
    last_name      VARCHAR(50) NOT NULL,
    email          VARCHAR(100) UNIQUE,
    enrollment_year INT,
    dept_id        INT,
    FOREIGN KEY (dept_id) REFERENCES department(dept_id)
);

CREATE TABLE society (
    society_id      INT PRIMARY KEY,
    society_name    VARCHAR(100) NOT NULL UNIQUE,
    category        VARCHAR(50),
    established_year INT,
    advisor_name    VARCHAR(100)
);
CREATE TABLE membership (
    student_id   INT,
    society_id   INT,
    join_date    DATE,
    role         VARCHAR(50),
    PRIMARY KEY (student_id, society_id),
    FOREIGN KEY (student_id) REFERENCES student(student_id),
    FOREIGN KEY (society_id) REFERENCES society(society_id)
);
CREATE TABLE event (
    event_id      INT PRIMARY KEY,
    society_id    INT,
    event_name    VARCHAR(150) NOT NULL,
    event_date    DATE,
    venue         VARCHAR(100),
    budget        DECIMAL(10,2),
    FOREIGN KEY (society_id) REFERENCES society(society_id)
);
CREATE TABLE event_registration (
    event_id     INT,
    student_id   INT,
    registration_date DATE,
    attendance_status  VARCHAR(20),
    PRIMARY KEY (event_id, student_id),
    FOREIGN KEY (event_id) REFERENCES event(event_id),
    FOREIGN KEY (student_id) REFERENCES student(student_id)
);
CREATE TABLE sponsor (
    sponsor_id    INT PRIMARY KEY,
    sponsor_name  VARCHAR(100),
    sponsor_type  VARCHAR(50),
    event_id      INT,
    amount        DECIMAL(10,2),
    FOREIGN KEY (event_id) REFERENCES event(event_id)
);


INSERT INTO department VALUES
(1, 'Computer Science', 'Engineering'),
(2, 'Business Administration', 'Management'),
(3, 'Electrical Engineering', 'Engineering');

INSERT INTO student VALUES
(101, 'Ali', 'Khan', 'ali@uni.edu', 2022, 1),
(102, 'Sara', 'Ahmed', 'sara@uni.edu', 2021, 2),
(103, 'Usman', 'Tariq', 'usman@uni.edu', 2023, 1),
(104, 'Hina', 'Malik', 'hina@uni.edu', 2022, 3);

INSERT INTO society VALUES
(1, 'Tech Society', 'Technical', 2015, 'Dr. Hassan'),
(2, 'Business Club', 'Business', 2012, 'Dr. Ali'),
(3, 'Robotics Club', 'Technical', 2018, 'Dr. Fatima');


INSERT INTO membership VALUES
(101, 1, '2024-01-01', 'President'),
(102, 2, '2024-02-01', 'Member'),
(103, 1, '2024-03-01', 'Member'),
(104, 3, '2024-01-15', 'Secretary');

INSERT INTO event VALUES
(1, 1, 'AI Workshop', '2025-03-10', 'Auditorium', 50000),
(2, 2, 'Marketing Seminar', '2025-04-15', 'Hall A', 30000),
(3, 3, 'Robotics Competition', '2025-05-20', 'Lab 1', 70000);

INSERT INTO event_registration VALUES
(1, 101, '2025-02-20', 'Attended'),
(1, 103, '2025-02-22', 'Registered'),
(2, 102, '2025-03-10', 'Attended'),
(3, 104, '2025-04-01', 'Registered');

INSERT INTO sponsor VALUES
(1, 'TechCorp', 'Company', 1, 20000),
(2, 'BizGroup', 'Company', 2, 15000),
(3, 'RoboTech', 'Company', 3, 30000);
select*from student
select*from department
select*from society
select*from event
select*from sponsor

--task1

select s.student_id
from student as s join event_registration as r on  s.student_id = r.student_id
group by s.student_id ,s.dept_id
having count(*) >
(
select avg(cnt)
from (
        select count(*) as cnt
        from student as  s2 join event_registration  as r2 on s2.student_id = r2.student_id
         where s2.dept_id = s.dept_id
       group by  s2.student_id
    )as avg_d
);

--task2
select s.society_id
from society as  s join event as e on s.society_id= e.society_id
group by  s.society_id, s.category
having sum(e.Budget) > (
    select avg(total_budget)
    from (
        select sum(e2.Budget) as total_budget
        from society as  s2 join event as e2 on s2.society_id = e2.society_id
        where s2.category = s.category
        group by s2.society_id
    ) as avg_table
);

--task3
select  *
from event as  e
where e.Budget = (
    select max(e2.Budget)
    from event as e2
     where e2.society_id = e.society_id
);

--task4
select  s.student_id
from student as  s join membership as m on s.student_id = m.student_id
where  not exists (
    select e.event_id 
    from event as e
    where e.society_id = m.society_id
    and not exists (
        SELECT *
        FROM event_registration as r
        WHERE r.student_id = s.student_id AND r.event_id = e.event_id
    )
);

--task5
SELECT s.society_id
FROM society as s
WHERE NOT EXISTS (
    SELECT e.event_id
    FROM event as  e
    WHERE e.society_id = s.society_id
    AND NOT EXISTS (
        SELECT *
        FROM sponsor as sp
        WHERE sp.event_id = e.event_id
    )
);

--task6
SELECT s.student_id
FROM student as s join event_registration as r ON s.student_id = r.student_id
GROUP BY s.student_id, s.dept_id
HAVING COUNT(*) = (
    SELECT MAX(cnt)
    FROM (
        SELECT COUNT(*) AS cnt
        FROM student as s2 join event_registration as r2 ON s2.student_id = r2.student_id
        WHERE s2.dept_id = s.dept_id
        GROUP BY s2.student_id
    ) AS t
);

--task7
SELECT e.event_id
FROM event as e
WHERE (
    SELECT COUNT(*) 
    FROM event_registration as r 
    WHERE r.event_id = e.event_id
) > ANY (
    SELECT COUNT(*)
    FROM event as e2 left join event_registration as r2 ON e2.event_id = r2.event_id
    WHERE e2.society_id <> e.society_id
    GROUP BY e2.event_id
);

--task8
SELECT d.dept_id
FROM department as d
WHERE NOT EXISTS (
    SELECT s.student_id
    FROM student as s
    WHERE s.dept_id = d.dept_id
    AND NOT EXISTS (
        SELECT *
        FROM membership as m
        WHERE m.student_id = s.student_id
    )
);

--task9
SELECT s.society_id
FROM society as s join event as e ON s.society_id = e.society_id
GROUP BY s.society_id, s.category
HAVING SUM(e.Budget) > ALL (
    SELECT SUM(e2.Budget)
    FROM society as s2 join event as e2 ON s2.society_id = e2.society_id
    WHERE s2.category = s.category AND s2.society_id <> s.society_id
    GROUP BY s2.society_id
);

--task10
SELECT s.student_id
FROM student  as s join membership as m ON s.student_id = m.student_id
WHERE NOT EXISTS (
    SELECT *
    FROM event as e join event_registration as r ON e.event_id = r.event_id
    WHERE e.society_id = m.society_id AND r.student_id = s.student_id
);

--task11

SELECT e.event_id
FROM event  as e
WHERE e.Budget > (
    SELECT AVG(e2.Budget)
    FROM event as e2
    WHERE e2.society_id = e.society_id
);

--task 12

SELECT m.society_id
FROM membership  as m join event_registration as r ON m.student_id = r.student_id
GROUP BY m.student_id, m.society_id
HAVING COUNT(*) > ALL (
    SELECT COUNT(*)
    FROM membership as m2 join event_registration as r2 ON m2.student_id = r2.student_id
    WHERE m2.society_id = m.society_id AND m2.student_id <> m.student_id
    GROUP BY m2.student_id
);

--task 13
SELECT m.society_id
FROM membership  as m
GROUP BY m.society_id
HAVING COUNT(*) > (
    SELECT AVG(cnt)
    FROM (
        SELECT COUNT(*) AS cnt
        FROM membership
        GROUP BY society_id
    ) AS t
);



