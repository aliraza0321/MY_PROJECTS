#include<iostream>
using namespace std;
int main()
{
	int birthD,birthM,birthY=0;      //birthD for date ,birthM for month of birth and birthY for year of birth 
	int dayNow,monthNow,yearNow=0;
	int totalDay,totalMonth,totalYear=0;
	cout<<"Enter date of birth in following format :-\n";
	cout<<"Day : ";
	cin>>birthD;
	cout<<"Month : ";
	cin>>birthM;
	cout<<"Year : ";
	cin>>birthY;
	while((birthD>31||birthD<0)||(birthM<0||birthM>12))
	{
		cout<<"Wrong input!Enter correct date of birth :-\n";
		cout<<"Day : ";
	    cin>>birthD;
	    cout<<"Month : ";
	    cin>>birthM;
	    cout<<"Year : ";
	    cin>>birthY;
	}
	cout<<"Enter currently date of birth :-\n";
	cout<<"Day : ";
	cin>>dayNow;
	cout<<"Month : ";
	cin>>monthNow;
	cout<<"Year : ";
	cin>>yearNow;
	while((dayNow<0||dayNow>31)||(monthNow<0||monthNow>12)||(yearNow<birthY))
	{
		cout<<"Wrong date!Please Enter valid date :-\n";
	    cout<<"Day : ";
	    cin>>dayNow;
	    cout<<"Month : ";
	    cin>>monthNow;
	    cout<<"Year : ";
	    cin>>yearNow;
	}
	if(dayNow<birthD)
	{
		if(monthNow==1)        //if month is 1 means Jan then previous month is dec that has 31 days 
		{
			dayNow+=31;         
		}
		if(monthNow==2)
		{
		     dayNow+=31;
		}
		if(monthNow==3)
		{
		 if(yearNow%4==0)
			   dayNow+=29;
		 else
			   dayNow+=28;
		}
		if(monthNow==4)
		{
			dayNow+=31;
		}
		if(monthNow==5)
		{
			dayNow+=30;
		}
		if(monthNow==6)
		{
			dayNow+=31;
		}
		if(monthNow==7)
		{
			dayNow+=30;
		}
		if(monthNow==8)
		{
			dayNow+=31;
		}
		if(monthNow==9)
		{
			dayNow+=31;
		}
		if(monthNow==10)
		{
			dayNow+=30;
		}
		if(monthNow==11)
		{
			dayNow+=31;
		}
		if(monthNow==12)
		{
			dayNow+=30;
		}
		monthNow-=1;
		
	}
	while(monthNow<birthM)      // one year has 12 months so add 12 months in monthNow and yearNow decrease by 1
	{
		yearNow--;
		monthNow+=12;	
	}
	totalDay=dayNow-birthD;
	totalMonth=monthNow-birthM;
	totalYear=yearNow-birthY;
	cout<<"Total Days :"<<totalDay<<endl;
	cout<<"Total Months :"<<totalMonth<<endl;
	cout<<"Total Years :"<<totalYear<<endl;
	return 0;
}
