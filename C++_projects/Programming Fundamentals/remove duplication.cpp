#include<iostream>
using namespace std;
int main()
{
	int arr[5]={1,2,1,2,1};
	int n=5;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				for(int k=j;k<n;k++)
				{
					arr[j]=arr[j+1];
				}
				j--;
				n--;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}