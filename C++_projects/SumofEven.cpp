#include<iostream>
using namespace std;
int main()
{
   long limit =4000000;
   int i=0,k=1,next,sum=0;
   next=i+k;
   while(next<4000000)
   {
   	    if(next%2==0)
   	    {
   	    	
   	    	sum=sum+next;
		   }
		   i=k;
		   k=next;
		   next=i+k;
   }
   cout<<"\nSum of even values is "<<sum;
   	
}
/*	nextTerm=n1+n2;
	while(nextTerm<limit)
	{
		cout<<","<<nextTerm;
		n1=n2;
		n2=nextTerm;
		nextTerm=n1+n2;
	}
	return 0;
}*/
