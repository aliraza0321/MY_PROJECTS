#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int num,size=0;
	int dig[10], a;
	cout << "Enter a number that has  : ";
	cin >> num;
	while (num <= 0)
	{
		cout << "Please enter Positive number : ";
		cin >> num;

	}
	int original = num;
	int i = 0;
	while (num > 0)
	{
	    a = num % 10;
		dig[i] = a;
		i++;
		num /= 10;
	}
	for (int j = 0;j < i;j++)
	{
		cout << dig[j] << " ";
	}
	cout << endl;
	cout << i;
	cout << endl;
	int remainder =0;

	for (int j = 0;j < i;j++)
	{
		remainder = remainder+pow(dig[j], i);
	}
	cout << remainder;
	cout << endl;
	if (original == remainder)
	{
		cout << "Number is armstrong number ";
	}
	else
	{
		cout << "Not armstrong number ";
	}
	
}