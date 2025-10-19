#include<iostream>
using namespace std;
int main()
{
	int a[7] = { -6,-4,0,1,4,56,589};
	int index, num;
	cout << "Enter index where you want to add a digit :";
	cin >> index;
	while (index >=7 || index < 0)
	{
		cout << "Enter valid index :";
		cin >> index;
	}
	cout << "Enter number that you want to add :";
	cin >> num;
	for (int i = 6;i >= index;i--)
	{
		a[i + 1] = a[i];
	}
	a[index] = num;
	for (int i = 0;i < 8;i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}