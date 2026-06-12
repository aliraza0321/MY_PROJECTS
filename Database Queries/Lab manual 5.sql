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

--Task 1
--part 1
select society_name
from society as s join event as e on s.society_id=e.society_id
where e.budget =(select max(budget) from event)

--part 2
select s.student_id
from (student as s join event_registration as er on s.student_id=er.student_id)
    join event as e on e.event_id=er.event_id
where e.budget >(select avg(budget) from event) 

--part 3

select society_id
from society 
where society_id=(
select society_id from event group by event_id,society_id having count(*)>avg(event_id));

--part 4
select s.student_id
from student as s
join membership as m on s.student_id = m.student_id
where m.society_id in (
    select society_id
    from membership
    group by society_id
    having COUNT(student_id) = (
        select max(member_count)
        from (
            select COUNT(student_id) as member_count
            from membership
            group by society_id
        ) as temp
    )
);

--part 5
select e.event_id
from event as e join sponsor as s on e.event_id=s.event_id
where s.amount>(select avg(amount) from sponsor)

--part 6
select dept_id
from student 
group by dept_id
having count(*)>=ALL(select count(*) from student group by dept_id)


--part7
select student_id
from event_registration as er join event as e on er.event_id=e.event_id
where society_id in(select society_id from society where category='Technical')

--part 8
select society_id
from event 
group by society_id
having sum(budget) >(select avg(budget) from event);


--part 9
select student_id,amount
from (event_registration as er join sponsor as s on er.event_id=s.event_id)
where amount>=(select max(amount) from sponsor)

--part 10
select society_id,budget
from event 
where budget>=(select avg(budget) from event)

--part 11

select er.student_id,e.budget
from event_registration as er join event as e on er.event_id=e.event_id
where e.budget =(select top 1 budget from event order by budget desc)

--part 12
select s.student_id
from student as s
join membership as m on s.student_id = m.student_id
where m.society_id in (
    select society_id
    from membership
    group by society_id
    having COUNT(*) = (
        select MAX(member_count)
        from (
            select COUNT(*) as member_count
            from membership
            group by society_id
        ) t
    )
);


--part 13
select dept_id,count(*)
from student 
group by dept_id
having count(*) >ALL(select count(*) from student group by dept_id);

--part 14
select event_id,budget
from event 
where budget>any(
select budget from event as e join
society as s on e.society_id=s.society_id where s.category='Business');

--part 15
select student_id
from membership 
where student_id not in (select student_id from event_registration )

--part 16
select society_id,amount
from event as e join sponsor as s on e.event_id=s.event_id
where s.amount <(
select avg(amount) from 
sponsor)

--part 17
select max(budget)
from event 
where budget>(select avg(budget) from event)

--part 18
select s.student_id
from student as s
where not exists (
    select e.event_id
    from event as e
    where e.budget > (select AVG(budget) from event)
    AND not exists (
        select 1
        from event_registration as er
        where  er.student_id = s.student_id
        AND er.event_id = e.event_id
    )
);

--part 19
select e.event_id, e.event_name, COUNT(er.student_id) as total_registrations
from event as  e left join event_registration as er on e.event_id = er.event_id
group by e.event_id, e.event_name
having count(er.student_id) = (
    select max(reg_count)
    from (
        select count(*) as reg_count
        from event_registration
        group by  event_id
    ) t
);

--part 20
select s.society_id
from society  as s
where not exists (
    select e.event_id
    from event as e
    where e.society_id = s.society_id
    AND e.budget <= (
        select avg(e2.budget)
        from event as e2
        JOIN society as s2 ON e2.society_id = s2.society_id
        JOIN student as st ON st.dept_id = (
            select dept_id 
            from department 
            where dept_name = 'Computer Science'
        )
    )
);

--part 21
select s.student_id
from student s
where not exists (
    select 1
    from event_registration  as er
    join event as  e on er.event_id = e.event_id
    where er.student_id = s.student_id
    AND e.budget < (select avg(budget) from event)
);