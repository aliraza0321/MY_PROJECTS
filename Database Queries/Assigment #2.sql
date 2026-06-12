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

--Part A
--part 1
select w.planid,
(select count(*) from Reviews as r where r.plan_id=w.planid)
+(select count(*) from Favorite_plans as f where f.plan_id=w.planid)as popularity
from Workout_plans as w
where  (
    select avg(r.rating)
    from Reviews as r
    where r.plan_id = w.planid
)
>
(
select avg(r2.rating)
from Reviews as  r2 join Workout_plans as w1 on r2.plan_id = w1.planid
where w1.difficulty_level = w.difficulty_level
)
and
(
select count(*)
from Exercises as e
where e.plan_id = w.planid
) >= 3
and
(
(select count(*) from Reviews as r where r.plan_id=w.planid) 
+(select count(*) from Favorite_plans as f where f.plan_id=w.planid)
)
>
(
select avg(popularity)
from  (
    select 
       ( 
        (select count(*) from Reviews as r where r.plan_id=w.planid) 
         +(select count(*) from Favorite_plans as f where f.plan_id=w.planid) )as popularity
    from Workout_plans as  w2
    where Year(w2.createdat) = Year(w.createdat)
       ) as yearly_pop
     )
order by popularity desc;


--part 2
select u.user_id
from  Users as u
where exists (  --check any user give any review if give then true and check other condition
    select *
    from Reviews r
    where r.user_id = u.user_id
)
and
not exists  --check null or row if null then means true if row then this is false
--null means not exist so true 
--i check null return 
(
    select *
    from Reviews as r
    where r.user_id = u.user_id and r.plan_id not in --detect wrong plan that is not in top 3 
    (
        select top 3 plan_id 
        from Favorite_plans
        group by  plan_id
        order by count(*) desc
    )
);

--part 3
select f1.user_id , f2.user_id 
from Favorite_plans as f1 join  Favorite_plans as f2 on f1.plan_id = f2.plan_id 
      and f1.user_id != f2.user_id
where not exists (--return null if not exist 
    select *
    from Reviews as r1 join Reviews as r2  on r1.plan_id = r2.plan_id
    where r1.user_id = f1.user_id and r2.user_id = f2.user_id
);


--part 4

select  f.user_id
from Favorite_plans as f join Reviews as r on f.plan_id = r.plan_id
join Users as u on r.user_id = u.user_id
where r.rating =(
select max(r2.rating)
from Reviews r2
where r2.plan_id = r.plan_id)
and

u.DOB =  --means user big dob that means smallest one 
(
select  max(u2.DOB)--max  dob means this is smallest  then all
from Reviews as r3 join Users as u2 on r3.user_id = u2.user_id
where r3.plan_id = r.plan_id--checks that r3 plan is same our high rated plan r
)

--part 5
select u.user_id,u.username,w.trainer_name
from (Favorite_plans as f join Workout_plans as w on f.plan_id=w.planid) 
join Users as u on u.user_id=f.user_id
where w.trainer_name in
--checks that favorite plan of w trainer is also reviewed by same user
(
select w.trainer_name
from Reviews as r join Workout_plans as w on r.plan_id=w.planid
join Users as u1 on u1.user_id=r.user_id
where u.user_id=u1.user_id--check review and favorite is by same user
)


--part 6
select planid
from Workout_plans as w
where(
select avg(r.rating)
from Reviews as r
where r.plan_id=w.planid
)
>
(
select avg(rating)
from Reviews
)
and
(
select count(*)
from Favorite_plans  as f
where f.plan_id=w.planid
)
<
(

select avg(count_per) --avg of favorites per plan 
from(--find favorite's count on per plan
select count(*)as  count_per
from Favorite_plans
group by plan_id
) t
)
and
(--who has only greater than aur equal to 2 excercises
select count(*)
from Exercises as e
where e.plan_id=w.planid
) >=2

--Part B
--part 1
Create trigger detect1
on Favorite_plans
After Insert,update
as IF (
   select count(*)
   from Favorite_plans as f join inserted as i 
   on f.user_id=i.user_id
)>5
Begin
 print 'Spam detected'
End

--part 2
Create trigger duplicate1
on Reviews
After Insert,update
as If exists( --if exists means condition is true 
select * 
from Reviews as r join inserted as i on r.plan_id=i.plan_id
and r.review_text=i.review_text
)
Begin
print 'Dupicate review text'
end



--Part C
--part 1

Create View rating_user as 
select user_id
from Reviews
group by user_id
having min(rating)=max(rating);--min and max same means same rating for all plans

select *from rating_user

--part 2

create view give_rating
as
select user_id
from Reviews
where plan_id=(
select top 1  plan_id
from Reviews
group by plan_id
order by avg(rating) desc
)
and
rating=(
select min(rating)
from Reviews
where plan_id =(
select top 1  plan_id
from Reviews
group by plan_id
order by avg(rating) desc
)
)
select*from give_rating

