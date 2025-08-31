#include<iostream>
using namespace std;
int main()
{
	int arr[2][3]={{1,2,3}
	              ,{4,5,6}};
	int  newA[3][2];
	int matrix[3][3]={{1,2,3}
	                 ,{4,5,6}
	                 ,{7,8,9}};
    cout<<"Original matrices "<<endl;
	for(int row =0;row<2;row++)
	{
		for(int col=0;col<3;col++)
		{
			cout<<arr[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int row =0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			cout<<matrix[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<"Transpose of matrices\n";
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<2;col++)
		{
			newA[row][col]=arr[col][row];
		}
		
	}
	
		for(int row =0;row<3;row++)
	{
		for(int col=0;col<2;col++)
		{
			cout<<newA[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int row=0;row<3;row++)
	{
		for (int col=row;col<3;col++)
		{
			int temp=matrix[row][col];
			matrix[row][col]=matrix[col][row];
			matrix[col][row]=temp;
		}
	}
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			cout<<matrix[row][col]<<" ";
		}
		cout<<endl;
	}
}