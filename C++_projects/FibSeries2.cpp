#include<iostream>
using namespace std;
int main()
{
	int n1=0,n2=1,nextTerm,limit;
	cout<<"Enter a limit of Fibonacci series : ";
	cin>>limit;
	nextTerm=n1+n2;
	cout<<n1<<","<<n2;
	while(nextTerm<limit)
	{
		cout<<","<<nextTerm;
		n1=n2;
		n2=nextTerm;
		nextTerm=n1+n2;
	}
	return 0;
}
