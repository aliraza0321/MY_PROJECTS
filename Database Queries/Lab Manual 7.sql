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


--Tasks on Triggers
--part1
create trigger t1 on event
instead of insert
as
begin
  if exists(select *from inserted where budget<0)
  begin
     print('No negative budget event is allowed')
  end
else
begin
INSERT INTO event
SELECT * FROM inserted
end
end
INSERT INTO event VALUES
(6, 1, 'AI Workshops', '2025-03-10', 'Auditorium', -5000)

--part2
CREATE TABLE membership_audit
(
student_id INT,
society_id INT,
join_date DATE,
action_time DATETIME
)
create trigger t2 on membership
after insert
as
begin
insert into membership_audit
select student_id, society_id, join_date, GETDATE()
from   inserted
end

--part3
create trigger t_3 on society
instead of delete,update
as
begin
if exists(select* from  event as e join deleted as d on d.society_id=e.society_id)
begin
print'This society has active event';
end
else
begin
delete from society
where society_id in(select society_id from deleted)
end
end

--part 4
create table registration_summary
(
event_id int,
total_reg int
)
create trigger t4 on event_registration
after insert
as
begin
 update registration_summary
 set total_reg=total_reg+1
 where event_id in(select event_id from inserted)
end

--part 5
create trigger t5 on event
instead of update
as
begin
if exists(
select *from 
inserted as i join sponsor as s on i.event_id=s.event_id
group by i.event_id,i.budget
having i.budget<sum(s.amount)
)
begin
print'Invalid update opeation'
end
else
update event
set budget=i.budget
from event as s join inserted as i on s.event_id=i.event_id
end
end

--part 6
create trigger t6 on event_registration
instead of insert
as
if exists(
select student_id
from event_registration
group by student_id
having count(*)>=5
)
begin
print'Not allowed limit is exceed'
end
else
begin
insert into event_registration
select *from inserted
end
--part 7
create trigger t7 on sponsor
instead of insert
as
if exists(select *
from inserted as i join sponsor as s on i.sponsor_name=s.sponsor_name and i.event_id=s.event_id
)
begin
print'Duplicate sponsor is not allowed'
end
else
begin
insert into sponsor
select *from inserted
end


--part 8
create trigger t8 on membership
after delete
as
delete e
from event_registration as e join event as et on e.event_id=et.event_id
join deleted as d on d.student_id=e.student_id and d.society_id=et.society_id

--part 9
create table budget_history_table
(
event_id INT,
old_budget DECIMAL(10,2),
new_budget DECIMAL(10,2),
change_date DATETIME
)
create trigger t9 on event
after update
as
insert into budget_history_table 
select i.event_id,d.budget,i.budget,GETDATE()
from inserted as i join deleted as d on i.event_id=d.event_id

--part 10
create trigger t10 on membership
instead of insert
as
insert into membership
select student_id,society_id,join_date,isNull(role,'Member')
from inserted
