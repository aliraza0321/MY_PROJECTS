#include<iostream>
using namespace std;
int main()
{
	int arr[10]={12,23,43,21,22,10,9,67,30,40};
	int target;
	int size=10;
	int center=size/2;
	int mid1=center/2;
	int mid2=center+mid1;
	int start=0;
	int end=size-1;
	char op;
	cout<<"Your sorted array is : ";
	for(int i=0;i<size;i++)
	{
		int cn=i;
		for(int j=i+1;j<size;j++)
		{
			if(arr[j]<arr[cn])
			{
				cn=j;
			}
		}
		int temp=arr[cn];
		arr[cn]=arr[i];
		arr[i]=temp;
	}
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	do{
	cout<<"Enter target value: ";
	cin>>target;
	while(start<=end)
	{
		if(target==arr[start])
		{
			cout<<"Value is found at "<<start<<" index";
			break;
		}
		else if(target==arr[mid1])
		{
			cout<<"Value is found at "<<mid1<<" index";
			break;
		}
		else if(target==arr[end])
		{
			cout<<"Value is found at "<<end<<" index";
			break;
		}
		else if(target==arr[mid2])
		{
			cout<<"Value is found at "<<mid2<<" index";
			break;
		}
		else if(target>arr[start]&&target<arr[mid1])
		{
			start+=1;
			end=mid1-1;
		}
		else if(target>arr[mid1]&&target<arr[mid2])
		{
			start=mid1+1;
			end=mid2-1;
		}
		else if(target>arr[mid2]&&target<arr[end])
		{
			start=mid2+1;
			end=end-1;
		}
		else
		{
			cout<<"Value is not found in this array ";
			break;
		}
	}
	cout<<"\nDo you want to search any number more enter y or Y for yes : ";
	cin>>op;
    }while(op=='Y'||op=='y');
}