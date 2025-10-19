#include<iostream>
using namespace std;

int calculateAvg(int x, int y)
{
	int result = x / y;
	cout << "Running avg is " << result << endl;
    return result;
}
int sum(int a, int b)
{
	int result = a + b;
	cout << "Total sum is " << result << endl;
    return result;
}
int main()
{
	int count = 5;
	int num, s = 0;
	int avg;
	for (int i = 0;i <= count;i++)
	{
		cout << "Number entered:";
		cin >> num;
		s = sum(s, num);
		cout << "Count"<<count;
		avg = calculateAvg(s, count);


	}
}
