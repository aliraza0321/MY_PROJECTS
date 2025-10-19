#include<iostream>
using namespace std;
int main()
{
	int limit,i,k,term,n1=0,n2=1,next=0;
	cout<<"Enter limit that how many fibonacci numbers you want to display ";
	cin>>limit;
	for(i=1;i<=limit;i++)
	{
		n1=0,n2=1;
		cout<<"Which number you want to display ";
		cin>>term;
		next=n1+n2;
		if(term==1)
		{
			cout<<"F"<<term<<" is "<<n1<<endl;
		}
		if(term==2)
		{
			cout<<"F"<<term<<" is "<<n2<<endl;
		}
		if(term==3)
		{
			cout<<"F"<<term<<" is "<<next<<endl;
		}
		for(k=3;k<term;k++)
		{
			
			
			n1=n2;
			n2=next;
			next=n1+n2;
		}
		if(term>3) 
		cout<<"F"<<term<<" is "<<next<<endl;
	
	}
}
