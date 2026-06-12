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


--Task 1 Views
--part 1
create view v1
as
select s.society_name,count(m.student_id) as total_members,count(m.student_id) as total_events,sum(sp.amount) as _amount
from society as s join membership as m on s.society_id=m.society_id
join event as e on e.society_id=s.society_id join sponsor as sp 
on sp.event_id=e.event_id
group by s.society_name
select *from v1
--part 2
create view v2
as 
select st.first_name,st.last_name,d.dept_name,count(ms.society_id) as total_societies,count(et.event_id) as total_event
from student as st join department  as d on st.dept_id=d.dept_id 
join membership as ms on st.student_id=ms.student_id join event_registration as et
on et.student_id=st.student_id
group by st.first_name,st.last_name,d.dept_name
select *from v2

--part 3
create view v3
as 
select budget,event_id
from event
where budget>(select avg(budget) from event)

select *from v3

--part 4
create view v4
as
select s.society_name,avg(budget)as Avg_budget,max(budget) as max_budget,min(budget)as min_budget
from society as s join event as e on s.society_id=e.society_id
group by s.society_name
select *from v4
--here each soiciety has only one event therefore all values are same

--part 5
create view v5
as
select s.student_id
from student as s join membership as m on s.student_id=m.student_id
group by s.student_id
having count(*)>1--all have oonly one socitey so no displayS
select *from v5

--part 6
create view v6
as
select event_name,society_name,count(s.society_id)as total,sum(budget)as amount
from event as e join society as s on e.society_id=s.society_id join sponsor as sp
on sp.event_id=e.event_id
group by event_name,society_name
select *from v6

--part 7
create view v7
as 
select s.student_id
from student as s left join event_registration  as e on s.student_id=e.student_id
where e.student_id is null
--every student is registered so no ouput
select *from v7

--part 8
create view v8
as
select e.society_id
from event as e left  join sponsor as s on e.event_id=s.event_id
where s.event_id is null  --every one is sponsored
select *from v8


--part 9
create view v9
as
select d.dept_id,count(er.event_id) as total
from department as d join student as s on s.dept_id=d.dept_id join event_registration as er on er.student_id=s.student_id
group by d.dept_id
having avg(er.student_id)>
(select avg(student_id) from event_registration  )
select*from v9

--part 10
create view v10
as
select society_name,count(student_id)as members,count(e.event_id)as event,count(*)as sponspor,avg(budget)as budget
from society as s join event as e on s.society_id=e.society_id join event_registration 
as er on er.event_id=e.event_id join sponsor as sp on sp.event_id=er.event_id
group by society_name
select*from v10

--tASK 2
--part 1

create procedure take_data10
@given_id integer
as
begin
select count(*) as total_members,count(sp.event_id) as total_evennts,sum(sp.amount) toal_sponspor,sum(budget) as budget_
from society as s join event as e on e.society_id=s.society_id join sponsor as sp on sp.event_id=e.event_id
join membership as m on m.society_id=s.society_id
where s.society_id=@given_id
group by s.society_id
end
exec take_data10 @given_id=1

--part 2
create procedure take_data20
@id integer
as 
begin
select count( distinct m.society_id) as total_society,count( distinct er.event_id)
as total_event,count(distinct er2.event_id)as total_attended
from student as s join membership as  m on  s.student_id = m.student_id
join event_registration as er on s.student_id = er.student_id join  event_registration as  er2 on s.student_id = er2.student_id
and er2.attendance_status = 'Attended'
where s.student_id = @id
group by  s.student_id
end
exec take_data20 @id=101

--part 3
create procedure increase_budget
@sid integer,
@percent integer
as
begin
update event
set budget = budget + (budget * @percent / 100)
where society_id = @sid;
end
exec increase_budget @sid = 1, @percent = 10;
select*from event

--part 4
create procedure transfer_student
@sid integer,
@old_society int,
@new_society int
as 
begin
-- remove from old society
delete from membership
where student_id = @sid and society_id = @old_society;
-- add to new society
insert into membership
values (@sid, @new_society, GETDATE(), 'Member');
end
exec transfer_student @sid = 101,@old_society = 1,@new_society = 3;
select*from membership

--part 5
create procedure delete_event1
@id integer
as
begin
delete from event
where event_id=@id
end
exec delete_event1 @id=2

--part 6
create procedure top_socities
@top integer
as
begin
select top (@top) s.society_name,sum(amount)as total_amount
from society as s join event as e on s.society_id=e.society_id join sponsor as sp on sp.event_id=e.event_id
group by s.society_name
order by total_amount desc
end
exec top_socities @top=3

--part 7
create procedure list_student1
@id integer
as 
begin 
select er.student_id,society_id
from event as e join event_registration as er on e.event_id=er.event_id
where society_id=@id
group by society_id,er.student_id
having count(er.event_id)=
(
select count(*)
from event
where society_id = 1)
end
exec list_student1 @id=1

--part 8
create procedure create_table
as
begin
create table temp_sponsorship
(
society_id integer,
total_amount integer
);
insert into temp_sponsorship
select s.society_id,sum(amount)as total_amount
from society as s join event as e on s.society_id=e.society_id join sponsor as sp on sp.event_id=e.event_id
group by s.society_id
select*from temp_sponsorship
end
exec create_table

--part 9
create procedure insert_check
@eid integer,
@sid integer,
@ename varchar(150),
@edate date,
@venue varchar(100),
@budget decimal(10,2)
as
begin
declare @avg_budget decimal(10,2)
select @avg_budget = avg(budget)
from event
if @budget >= @avg_budget
begin
insert into event
values(@eid,@sid,@ename,@edate,@venue,@budget)
print 'Event inserted successfully'
end
else
begin
print 'Insertion not allowed: Budget below average'
end
end
exec insert_check @eid = 4,@sid = 1,@ename = 'Data Science Workshop',@edate = '2025-06-01',@venue = 'Lab 2',
@budget = 80000

--part 10
create procedure student_report
@sid integer
as
begin
select s.student_id,s.first_name,s.last_name,m.society_id,m.role,er.event_id,er.attendance_status
from student as s join membership as m on s.student_id = m.student_id
join event_registration as er on s.student_id = er.student_id
where s.student_id = @sid
end
exec student_report @sid=101