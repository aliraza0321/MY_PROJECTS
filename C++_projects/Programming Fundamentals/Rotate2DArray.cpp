#include<iostream>
using namespace std;
int main()
{
	int arr[3][3] = {{ 4, 8 ,12 },
	                 { 3, 7, 11 },
	                 { 2, 6, 10 }};
	for (int i = 0;i < 3;i++)
	{
		for (int j = i;j < 3;j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	
	for (int i = 0;i < 3;i++)
	{
		int temp = arr[i][0];
		arr[i][0] = arr[i][2];
		arr[i][2] = temp;
	  }
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
}