#include<iostream>
using namespace std;
int main()
{
	int a[100];
	int count = 0;
	cout << "Enter the values of array :\n";
	for (int i = 0;i < 100;i++)
	{
		cin >> a[i];
		if (a[i] == -1)
		{
			break;
		}
		count++;
	}
	cout << "\n...Original Array...\n";
	for (int i = 0;i < count;i++)
	{
		cout << a[i] << " ";

	}
	cout << endl<<endl;
	for (int i=0;i  <count;i+=2)     //start form 0 and add 2 for checking even index
	{
		
		 int cn = i;
		int temp;
		for (int j = i + 2;j<count;j += 2)
		{
			if (a[cn] >a[j])
			{
				cn = j;
			}
		}
		temp = a[cn];
		a[cn] = a[i];
		a[i] = temp;
	}
	for (int i = 1;i < count;i+=2)       //staart from 1 for checking odd num
	{
		int cn = i;
		int temp;
		for (int j = i + 2;j < count;j += 2)
		{
			if (a[cn] < a[j])
			{
				cn = j;
			}
		}
		temp = a[cn];
		a[cn] = a[i];
		a[i] = temp;
	}
	cout << "index: ";
	for (int i = 0;i < count;i++)
	{
		cout  << i<<"   ";
	}cout << endl;
	cout << "value: ";
	for (int j = 0;j < count;j++)
	{
		cout << a[j] << "   ";
	}
}