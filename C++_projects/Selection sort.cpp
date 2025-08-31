#include<iostream>
using namespace std;
int main()
{
	int arr[7]={3,2,4,5,6,1,7};
	int i,j,count,temp;
	for(i=0;i<7;i++)
	{
	    count=i;
		for(j=i;j<7;j++)
		{
			if(arr[j]<arr[count])
			{
				count=j;
			}
		}
	    temp=arr[count];
		arr[count]=arr[i];
		arr[i]=temp;
	}
	for(int i=0;i<7;i++)
	{
		cout<<arr[i]<<" ";
	}
}