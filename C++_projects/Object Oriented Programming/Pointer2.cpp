#include<iostream>
using namespace std;
void memallo(int* ptr, int& size)
{
	cout << "Enter the size of array:";
	cin >> size;
	ptr = new int[size];
}
void inidata(int* ptr, int& size)
{
	int* temp = ptr;
	for (int i = 0;i < size;i++)
	{
		cout << "Enter data: ";
		cin >> *temp;
		temp++;
	}
}
void display(int* ptr, int& size)
{
	int* temp = ptr;
	cout << endl;
	for (int i = 0;i < size;i++)
	{
		cout << *temp;
		temp++;
	}
}
int main()
{
	int* ptr;
	int size;
	memallo(ptr, size);
	inidata(ptr, size);
	display(ptr, size);
}