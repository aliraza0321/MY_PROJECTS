#include<iostream>
using namespace std;
int main()
{
		int matrix[3][3]={{1,2,3}
	                 ,{4,5,6}
	                 ,{7,8,9}};
    cout<<"Original matrices "<<endl;
    for(int row =0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			cout<<matrix[row][col]<<" ";
		}
		cout<<endl;
	}
	for(int row=0;row<3;row++)
	{
		for (int col=row;col<3;col++)
		{
			int temp=matrix[row][col];
			matrix[row][col]=matrix[col][row];
			matrix[col][row]=temp;
		}
	}
	
cout<<"Rotated by 90 angle clockwise "<<endl;
    for(int row =0;row<3;row++)
	{
		for(int col=3-1;col>=0;col--)
		{
			cout<<matrix[row][col]<<" ";
		}
		cout<<endl;
	}
}