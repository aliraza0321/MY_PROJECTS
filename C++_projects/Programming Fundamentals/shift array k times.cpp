#include<iostream>
using namespace std;
int main()
{
	int arr[5]={1,2,3,4,5};
	int temp,k,i,j;
	cout<<"Enter digit for rotating array left or right side: ";
	cin>>k;
	if(k>=0)
	{
		for(i=0;i<k;i++)
		{
			temp=arr[5-1];
			for(j=5-1;j>0;j--)
			{
				arr[j]=arr[j-1];
			}
			arr[0]=temp;
			
		}
	}
	else
	{
		for(i=k;i<0;i++)
		{
			temp=arr[0];
			for(j=0;j<4;j++)
			{
				arr[j]=arr[j+1];
				
			}
			arr[4]=temp;
		}
	}
	cout<<"Rotated array : "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
}