#include<iostream>
using namespace std;
int main()
{
	const int size = 20;
	int a[size];
	int  count = 0;
	int uni[size];
	int n=0,cn=0,temp=0,limit=0;
	cout << "Enter the values of array:\n";
	for (int i = 0;i < size;i++)
	{
		cin >> a[i];
		if (a[i] == -99)
		{
			break;
		}
		count++;
	}
	cout << "\n...Original values of Array...\n";
	for (int i = 0;i < count;i++)
	{
		cout << a[i] << " ";
	}
	int x,y=0;
	for (int i = 0;i < count;i++)
	{
		x = 0;
		for (int j = 0;j < count;j++)
		{
			if (a[i] == a[j])
			{
				x++;
			}
		}
		if (x == 1)
		{
			uni[y] = a[i];
			y++;
		}
	 }
	cout << "\nUnique elements in array :";
	for (int i = 0;i <y;i++)
	{
		cout << uni[i] << " ";
	}
	for (int i = 0;i < count;i++)
	{
		for (int j = i + 1;j < count;j++)
		{
			if (a[i] == a[j])
			{
				for (int k = j;k < count;k++)
				{
					a[k] = a[k + 1];
				}
				j--;
				count--;
			}
		}

	}
	for (int i = 0;i < count;i++)
	{
		
		cn = i;
		for (int j = i + 1;j < count;j++)
		{
			if (a[cn] > a[j])
			{
				cn = j;
			}
		}
		temp = a[cn];
		a[cn] = a[i];
		a[i] = temp;
	}
	cout << "\nDistinct elements in arrray: ";
	for (int i = 0;i < count;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	
}
