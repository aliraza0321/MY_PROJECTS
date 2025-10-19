#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	for(a=0;a<=1000;a++)
	{
		for(b=0;b<=1000;b++)
		{
			for(c=0;c<=1000;c++)
			{
				if((a*a)+(b*b)+(c*c)==1000)
				{//square of a,b,c satisfies the equation that is given in question 
					cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
				}
			}
		}
	}
}
