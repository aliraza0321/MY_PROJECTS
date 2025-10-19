#include<iostream>
#include"nPr.cpp"
using namespace std;
int combination(int, int);
//int factorial(int);
//int permutation(int, int);
int main()
{
	int n, r;
	cout << "Enter two n and r for finding combination :";
	cin >> n >> r;
	int result = combination(n, r);
	cout << "Combination of " << n << "C" << r << " is " << result;
}
int combination(int n, int r)
{
	int numenator = permutation(n, r);
	int denominator = factorial(r);
	int result = numenator / denominator;
	return result;
}
/*int permutation(int n, int r)
{
	int numenator = factorial(n);
	int denomenator = factorial(n - r);
	int result = numenator / denomenator;
	return result;
}
int factorial(int x)
{
	int result = 1;
	for (int i = 1;i <= x;i++)
	{
		result *= i;
	}
	
	return result;
}*/