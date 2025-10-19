#include<iostream>
using namespace std;
int main()
{
	int n1,n2,n3,dig;
	cout<<"Enter greatest digit ";
	cin>>dig;
	while(dig<0)
	{
		cout<<"Enter a valid digit ";
		cin>>dig;
	}
	for(n1=0;n1<=dig;n1++)
	{
		for(n2=0;n2<=dig;n2++)
		{
			for(n3=0;n3<=dig;n3++)
			{
				if(n1*n2*n3==dig)
				{
					cout<<"digit is product of "<<n1<<","<<n2<<","<<n3;
					cout<<endl;
				} 
			}
		}
	}
	
	
}
