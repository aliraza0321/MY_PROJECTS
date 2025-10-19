#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int num,a;
	cout<<"Enter a number that is perfect square :";
	cin>>num;
	do
	{
	   a=sqrt(num);	
     if(num==a*a)
     {
     	cout<<"Number is perfect square\n ";
	 }
	 else
	 {
	 	cout<<"Not perfect square\n ";
	 }
	 cout<<"Enter a number that is perfect square :";
	cin>>num;
    }while(num!=-1);
    return 0;
}
