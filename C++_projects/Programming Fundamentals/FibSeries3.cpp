#include<iostream>
using namespace std;
int main()
{
	int startlimit,endlimit;
	int n1=0,n2=1,nextTerm;
	cout<<"Enter starting and ending limit of fibonacci series :";
	cin>>startlimit>>endlimit;
	while(n1<endlimit)   //here check that n1 is smaller than finallimit
	{
		if(n1>startlimit)
		{
			cout<<n1<<" ";
		}
		nextTerm=n1+n2;
		n1=n2;
		n2=nextTerm;
	}   
	return 0;
	}
	

