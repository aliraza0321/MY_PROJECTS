#include<iostream>
using namespace std;
int main()
{
	int limit;
	int value;
	cout<<"Enter starting limit of prime numbers : ";
	cin>>value;
	cout<<"Enter limit of prime numbers :";
	cin>>limit;
	while(value<=limit)
	{
			bool isprime=true;

		int fact=2;
		while(fact<value)
		{
			if(value%fact==0)
			{
				isprime=false;
				break;
			}
			fact++;
		}
		if(isprime)
		{
			cout<<value<<" ";
		}
		value++;
	}
}
/*{
	bool isprime=true;
	int n;
	cin>>n;
	int i=2;
	while(i<=n/2)
	{
		if(n%i==0)
		{
		isprime =false;
		break;}
		i++;
	}
	if(isprime)
	cout<<"Prime";
	else
	cout<<"Not";
	
}*/