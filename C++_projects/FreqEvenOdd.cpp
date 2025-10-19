#include<iostream>
using namespace std;
int main()
{
	int num,n1=0,n2=0;
	cout<<"Enter a number ";
	cin>>num;
	while(num<=0)
	{
		cout<<"Enter a valid number ";
		cin>>num;
	}
	do
	{
	if(num%2==0)
	{
		n1++;
	}
	if(num%2==1)
	{
		n2++;
	}
	cout<<"Enter a number ";
	cin>>num;
    }while(num!=-1);
    cout<<"Frequency of Even numbers :"<<n1<<endl;
    cout<<"Frequency of Odd number :"<<n2<<endl;
    return 0;
}
