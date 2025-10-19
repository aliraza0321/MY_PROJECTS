#include<iostream>
using namespace std;
int fact(int);
int combination(int, int);
int main()
{
	int n;
	cout << "Enter n  for pascal triangle:";
	cin >> n;
	int iCj;
		for (int i = 0; i <= n;i++)
		{
			for(int k=n-i;k>=0;k--)
			{
				cout<<" ";
			}
			for (int j = 0;j <= i;j++)
			{
			     iCj= combination(i, j);
				cout <<iCj<< " ";
			}
			cout << endl;
		}

}
int fact(int x)
{
	int result = 1;
	for (int i = 1;i <= x;i++)
	{
		result *= i;
	}
	return result;
}
int combination(int n, int r)
{
	int result= fact(n) / (fact(r) * fact(n - r));
	return result;
}
