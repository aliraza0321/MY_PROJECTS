Create Table student(
FName varchar(10),
LName varchar(10),
DOB varchar(10),
RSN varchar(5),
primary key (RSN),
Unique(RSN)
);
Insert Into student(FName,LName,RSN)
values ('ali','raza','1');
select*
from student;
