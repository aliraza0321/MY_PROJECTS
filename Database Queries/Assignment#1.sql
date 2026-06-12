--Part A 
--No 1(a) creating tables and add pk and fk on that tables 
CREATE TABLE Users
(
user_id integer Not Null,
username varchar(20),
email varchar(50),
DOB DATE,
createdat DATE,
);

CREATE TABLE Workout_plans
(
planid integer Not Null,
plan_name varchar(20),
trainer_name varchar(20),
created_date date,
difficulty_level varchar(20),
createdat datetime,
);
CREATE TABLE Exercises
(
exercise_id integer Not Null,
plan_id integer Not Null,
exercise_number integer,
name varchar(20),
description varchar(50),
calories_burned integer,

);
CREATE TABLE Reviews
(
reviews_id integer Not Null,
user_id integer Not null,
plan_id integer Not Null,
rating integer,
review_text varchar(20),
createdat date,
);

CREATE TABLE Favorite_plans
(
favorite_id integer Not Null,
user_id integer Not null,
plan_id integer Not null,
favorited_at date,
);

--Adding primary key on all tables

alter table Users add constraint p1 primary key(user_id) --primary key on users is done

Alter table Workout_plans add constraint p2 primary key(planid)  --primery key on workout is done

Alter table Exercises add constraint p3 primary key(exercise_id)--primary key on excercise is done

Alter table Reviews add constraint p4 primary key(reviews_id) --primary key on reviews is done

Alter table Favorite_plans add constraint p5 primary key(favorite_id)--primary on favorite is done

--adding foreign key on all tables

Alter table favorite_plans add constraint f1 foreign key(user_id) --foreign key for user's favorite plan is done
references Users(user_id) on delete cascade on update cascade

Alter table favorite_plans add constraint f2 foreign key(plan_id) --for favorite plan's foreign key is done
references Workout_plans(planid) on delete cascade on update cascade

Alter table Reviews add constraint f3 foreign key(user_id) --for user who will review foreign is done
references Users(user_id) on delete cascade on update cascade

Alter table Reviews add constraint f4 foreign key(plan_id)  --for plan on which user will give review fk is done
references Workout_plans(planid) on delete cascade on update cascade

Alter table Exercises add constraint f5 foreign key(plan_id) --for workout which exercise is added in it fk is done
references Workout_plans(planid) on delete cascade on update cascade

-- No 1(b) :Inserting data in tables
Insert Into Users
Values
(1,	'Ali Raza'	,'aliraza@gmail.com','2001-05-10',	'2026-01-01'),
(2,'Ahmad Khan','ahmadkhan@gmail.com', '2002-08-22',	'2026-01-02'),
(3,'Bilal Ahmed','bilalahmed@gmail.com', '2000-12-05',	'2026-01-03' ),
(4,'Ali Shah',	'hinashah@gmail.com', '2001-03-18',	'2026-01-04'),
(5,'Usman Ali',	'usmanali@gmail.com',' 1999-07-25','	2026-01-05');
Select*from Users;

Insert Into Workout_plans
Values
(1,'Intense Burn','Ali Ahmad','1980-01-01','Advanced','1980-01-01 14:35:20 '),
(2,'Beginner Flex','Haseeb ','2000-06-01','Beginner','2000-06-01 10:05:20'),
(3,'Cardio Extreme','Safyan','2012-03-10','Advanced','2012-03-10 04:50:20'),
(4,'Yoga Light','Ahmad Aslam','2008-05-05','Beginner','2008-05-05 03:30:40'),
(5,'Strength Plus','Usman Coach	','2000-09-09','Intermediate','2000-09-09 11:39:29');
select *from Workout_plans

Insert Into Exercises
Values
(1,	1,	1,	'Burpees','	Full body',	600),
(2,	1,	2, 'Jump Squats	','Legs',	550),
(3,	3,	1,  'Running on spot','	Cardio',400),
(4, 4,	1, 'Stretch','	Flexibility	',100),
(5,	5,	1, 'Deadlift','Strength',	300);
select *from Exercises

Insert Into Reviews
Values
(1,	1,	1,	5,	'Very intense','2020-01-01'),
(2,	1,	2,	4,	'Good for start','2020-01-02' ),
(3,	3,	1,	5,	'Excellent','2019-05-05' ),
(4,	2,	3,	3,	'Hard','2023-06-01'), 
(5,	4,	4,	2,	' easy','2022-02-02 ');
select *from Reviews 

Insert Into Favorite_plans
Values
(1,	1,	1,	'2020-01-01'), 
(2,	1,	2,	'2020-01-03') ,
(3,	3,	5,	'2018-06-06'),
(4,	5,	4,	'2019-12-30 '),
(5,	2,	3,	'2023-06-02 ');
select *from Favorite_plans

--Starting operations on our data
--No 2(a) same user favorite and reviews as workout with plan id 
select  planid,plan_name,f.user_id
from (favorite_plans as f join Reviews as r on f.user_id=r.user_id and f.plan_id=r.plan_id) 
      join Workout_plans as w on w.planid=f.plan_id

--2(b)
--which user age difference with 20 is greater than plan created date that will display
select u.user_id,u.username,f.plan_id,w.created_date,u.DOB
from (Users as u join Favorite_plans as f on u.user_id=f.user_id) 
     join Workout_plans as w on w.planid=f.plan_id
where  Year(w.created_date) <= Year(u.DOB)-20

--2(c)  plan that exist in  favorite or in  reviews will minus from workout_plans's planid
select planid
from Workout_plans
except
(select f .plan_id
from Favorite_plans as f  
union
select r.plan_id
from Reviews as r ) 
 
 --2(d)
 --user who favorite and reveiws same plans will listed
 select u.user_id,u.username,f.plan_id
 from (Users as u join Favorite_plans as f on u.user_id=f.user_id) 
        join Reviews as r on r.user_id=u.user_id 
where f.plan_id=r.plan_id

--2(e)

select user_id
from Users
except
(select user_id 
from Favorite_plans 
union
select user_id 
from Reviews)

--2(f)
--which favorite and reviews date is different that will come
select f.user_id,f.plan_id,f.favorited_at,r.createdat
from (Favorite_plans as f join Reviews as r on f.plan_id=r.plan_id and f.user_id=r.user_id)
where f.favorited_at!=r.createdat

--2(g)
select planid
from Workout_plans
except
(select f.plan_id
from Favorite_plans as f 
intersect
select r.plan_id
from  Reviews as r ) 

--2(h)
select w.planid,w.plan_name,e.exercise_number
from (Workout_plans as w join Reviews as r on w.planid=r.plan_id) 
      join Exercises as e on e.plan_id=w.planid 
where e.exercise_number>=1

--2(i)
select u.user_id,u.username,w.planid,w.trainer_name,w.plan_name,w.created_date
from (Users as u join Reviews as r on u.user_id=r.user_id) 
     join Workout_plans as w on w.planid=r.plan_id
where w.trainer_name like 'A%'
union
select u.user_id,u.username,w.planid,w.trainer_name,w.plan_name,w.created_date
from (Users as u join Favorite_plans as f on u.user_id=f.user_id) 
     join Workout_plans as w on w.planid=f.plan_id
where w.created_date like '2020%';
--not any plan created in 2020 in my data i can also check for 2000

--2(J)
--i don't have year 2020 above all years are belwo for checking i also  check for 2010
select u.user_id,w.planid,w.plan_name,u.DOB,w.created_date
from (Users as u join Favorite_plans as f on u.user_id=f.user_id) 
     join Workout_plans as w on w.planid=f.plan_id
where w.created_date<'2020-01-01'
intersect
select u.user_id,w.planid,w.plan_name,u.DOB,w.created_date
from (Users as u join Reviews as r on u.user_id=r.user_id) 
     join Workout_plans as w on w.planid=r.plan_id
where u.DOB<'1995-01-01'
--if we check older than 35 then no one in our data so empty output
--for understanding i check for 
--where u.DOB<'2005-01-01'

--2(k)
select distinct w.planid
from Workout_plans as w join Exercises as e on w.planid=e.plan_id and exercise_number>=1
where e.calories_burned>500
union
select r.plan_id
from Reviews as r join Users as u on r.user_id=u.user_id 
where u.user_id not in(select u.user_id from Favorite_plans as f 
                       join Users as u on f.user_id=u.user_id)
 
--2(l)
select distinct u.user_id,u.username
from (Favorite_plans as f join Users as u on f.user_id=u.user_id) join Workout_plans as w on w.planid=f.plan_id
where w.created_date<u.DOB
union
select distinct u.user_id,u.username
from (Reviews as r join Users as u on r.user_id=u.user_id) join Workout_plans as w on w.planid=r.plan_id
where w.difficulty_level='Advanced'

--2(m)
select r.user_id, count(*) as total_reviews
from (Reviews as  r join Workout_plans as w 
     on r.plan_id = w.planid )left join Favorite_plans as  f
     on r.user_id = f.user_id and r.plan_id = f.plan_id
where  f.plan_id is null
group by r.user_id
having count(distinct w.difficulty_level) = 1;

--2(n)

select r.plan_id , count(*) as total_reviews
from Reviews as r left join Favorite_plans as f on r.user_id = f.user_id
where f.user_id is null
group by  r.plan_id
having count(distinct r.user_id) > 1;

--2(o)

select u.user_id
from (Users as u join Favorite_plans as f on u.user_id=f.user_id) join Reviews as r on
     r.plan_id=f.plan_id and r.user_id=u.user_id join Exercises as e on e.plan_id=r.plan_id
where e.exercise_number >=2
--i have no exercise number is more than 3  so no null output if i check for 2 then one row come 

--Part B
--1(a)
select plan_id,COUNT(*) as Total
from Exercises
group by plan_id
having count(*)>=2
--for i don't have any plan that have more than 5 excercise therefore null output with 2 is one 

--1(b)
select top 3 plan_id,count(*) as Total_Reviews
from Reviews
group by plan_id
order by Total_Reviews desc 
--in sql server for selecting top 3 use top first desc high reviews user on top 

--1(c)
select AVG(r.rating) as Avg_Rating,w.trainer_name
from Reviews as r join Workout_plans as w on r.plan_id=w.planid 
 where w.trainer_name like '%Ali %'
group by w.trainer_name

--1(d)

select user_id,count(*) as Total_plan
from Favorite_plans  
group by user_id
having count(*)>=2

--1(e)
select r.plan_id,r.reviews_id,count(*) as Total_exercise
from (Exercises as e join Workout_plans as w on e.plan_id=w.planid) 
      join Reviews as r on r.plan_id=w.planid
group by r.plan_id,r.reviews_id
having count(*)>=2

--1(f)
select avg(rating)as Avg_rating,u.DOB
from Reviews as r join Users as u on r.user_id=u.user_id 
where Year(GETDATE()) - Year(u.DOB) >=13 and Year(GETDATE()) - Year(u.DOB) <=19
group by u.DOB 
union
select avg(rating)as Avg_rating,u.DOB
from Reviews as r join Users as u on r.user_id=u.user_id 
group by DOB

--1(g)
select avg(Year(Getdate()-Year(DOB))) as Avg_age
from (Favorite_plans as f join Users as u on f.user_id=u.user_id) join Workout_plans as w on w.planid=f.plan_id
where w.difficulty_level='beginner'

--1(h)
select f.plan_id,avg(e.calories_burned)as Avg_cali
from (Favorite_plans as f join Reviews as r on f.plan_id=r.plan_id and f.user_id=r.user_id) join Users as u 
      on u.user_id=r.user_id join Exercises as e on e.plan_id=r.plan_id
group by f.plan_id
having avg(e.calories_burned)>=450

--1(i)
select count(distinct r.plan_id) * 100.0 / count(w.planid)  as Reviewed_Percentage
from Workout_plans as w  left join Reviews as r on  w.planid = r.plan_id


--Part C
--1(a)
alter table Users add experience_level varchar(15);
Select *from Users

--1(b)
alter table Workout_plans alter column difficulty_level varchar(20);

--1(c)

update Workout_plans
set difficulty_level = 'advanced'
where plan_name like '%intense%';
Select *from Workout_plans

--1(d)
update Exercises
set calories_burned = calories_burned + 50
where plan_id in (
    select plan_id
    from Workout_plans
    where created_date < '2020-01-01'
);

--1(e)
delete from Reviews
where user_id in (
    select user_id
    from Users
    where username like 'test%'
);
select*from Reviews
