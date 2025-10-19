#include<iostream>
using namespace std;
int main()
{
	const int size = 50;
	int a[size];
	int count = 0;
	cout << "Enter the values in zeros and ones format only :";
	for (int i = 0;i < size;i++)
	{
		cin >> a[i];
		while (a[i] < -1 || a[i]>1)      //for checking digit is valid or not
		{
			cout << "Please enter valid values of array:";
			cin >> a[i];
		}
		if (a[i] == -1)        //when user will enter -1 loop terminate 
		{
			break;
		}
		count++;          // count countes the number of array 
	}
	cout << "\n...Original Array...\n";
	for (int i = 0;i < count;i++)
	{
		cout << a[i] << " ";
	}
	for (int i = 0;i < count;i++)
	{
		int temp;
		int cn = i;
		for (int k = i + 1;k < count;k++)
		{
			if (a[cn] > a[k])        // move zeros to left side and one to right side 
			{
				cn = k;
			}

		}
		temp = a[cn];        //after checking conditions swap elements 
		a[cn] = a[i];
		a[i] = temp;
	}
	cout << "\n...Segregatead Array...\n";
	for (int j = 0;j < count;j++)
	{
		cout << a[j] << " ";
	}
}