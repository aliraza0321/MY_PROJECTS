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
				if(a+b+c==1000)
				{
					cout<<a<<" +"<<b<<" +"<<c<<" = "<<"1000 "<<endl;
				}
			}
		}
	}
}
