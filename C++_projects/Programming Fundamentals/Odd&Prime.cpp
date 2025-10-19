#include<iostream>
using namespace std;
int prime(int[]);
int odd(int[]);
int main()
{
	int arr[20];
	int size = 20;
	cout << "Enter the values of array randomly:";
	for (int i = 0;i < size;i++)
	{
		cin >> arr[i];
	}

}
int prime(int arr[], int size)
{
	int pri[] = { 0 };
	int limit=0;
	for (int i = 0;i < size;i++)
	{
		for (int j = 2;j <= arr[i];j++)
		{
			if (arr[i] % j != 0)
			{
				pri[limit] = arr[i];
			}
		}
	}
	return (pri[], limit);
}