#include<iostream>
using namespace std;
int main()
{
	const int size = 10;     //here we declare constant type variable for size of arry 
	int n[size], dig;
	cout << "Enter the values of array:";
	for (int i = 0;i < size;i++)
	{
		cin >> n[i];
	}
	cout << "Enter the digit which sum we will find in array:";
	cin >> dig;
	for (int j = 0;j < size;j++)
	{
		for (int k = 0;k < size;k++)
		{
			for (int x = 0;x < size;x++)
			{
				if (n[j] + n[k] + n[x] == dig)    //here we will check that which number's sum is equal to digit 
				{
					cout << n[j] << " " << n[k] << " " << n[x];
					cout << endl;
				}
			}
		}
	}




}