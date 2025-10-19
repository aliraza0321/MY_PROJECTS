#include<iostream>
using namespace std;
int main()
{
	int num,sum=0;
	for(num=501;num<3000;num++)  //sum of all natural numbers that are multiple of 3 or 5 but not both 
	{                            //numbers greater than 500 and less than 3000
		if(((num%3==0)||(num%5==0))&&(num%3!=num%5))
		{
			sum=sum+num;
		}
	}
	cout<<"Sum is "<<sum;
	return 0;
}
