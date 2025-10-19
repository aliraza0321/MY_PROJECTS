#include<iostream>
using namespace std;
int gcd(int, int);
int lcm(int, int);
int smaller(int, int);
int main()
{
	int n1, n2;
	cout << "Enter two digits :";
	cin >> n1 >> n2;
	int GCD = gcd(n1, n2);
	int LCM = lcm(n1, n2);
	cout << "GCD of " << n1 << " and " << n2 << " is " << GCD << endl;
	cout << "LCM of " << n1 << " and " << n2 << " is " << LCM << endl;
}
int smaller(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
}
int gcd(int x, int y)
{
	int limit = smaller(x, y);
	int result;
	for (int i = 1;i <= limit;i++)
	{
		if (x % i == 0 && y % i == 0)
		{
			result = i;
		}
		
	}
	return result;
}
int lcm(int x, int y)
{
	int result;
	result = x * y / gcd(x, y);
	return result;
}