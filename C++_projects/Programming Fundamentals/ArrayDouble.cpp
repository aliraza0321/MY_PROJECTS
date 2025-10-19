#include<iostream>
using namespace std;
void showArray(int [],int);
void doubleArray(int [],int);
void TripleArray(int [],int);
int main()
{
	const int size=5;
	int Arr[size]={2,3,4,5,6};
	cout<<"Array before any operation:"<<endl;
    showArray(Arr,size);
    doubleArray(Arr,size);
    cout<<"\nAfter doubling :"<<endl;
    showArray(Arr,size);
    TripleArray(Arr,size);
    cout<<"\nAfter Quadripling:"<<endl;
    showArray(Arr,size);
}
void showArray(int n[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<n[i]<<" ";
	}
}
void doubleArray(int n[],int size)
{
	for(int i=0;i<size;i++)
	{
		n[i]*=n[i];
	}
}
void TripleArray(int n[],int size)
{
	for(int i=0;i<size;i++)
	{
		n[i]*=n[i];
	}
}