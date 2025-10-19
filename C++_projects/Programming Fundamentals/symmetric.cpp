#include<iostream>
using namespace std;
void ini(int [],int);
bool isSymm(int [],int);
int main()
{
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;
	int arr[size];
	cout<<"Enter the values of array:";
	ini(arr,size);
	int sym=isSymm(arr,size);
	if(sym)
	{
		cout<<"Your array is symmtric";
			
	}
	else
	{
		cout<<"Not symmtric";
	}
	
}
void ini(int A[],int limit)
{
	for(int i=0;i<limit;i++)
	{
		cin>>A[i];
	}
}
bool isSymm(int A[],int limit)
{
	for(int i=0;i<limit;i++)
	{
		if(A[i]!=A[limit-1-i])
		{
			return 0;
		}
	}
	return 1;
}