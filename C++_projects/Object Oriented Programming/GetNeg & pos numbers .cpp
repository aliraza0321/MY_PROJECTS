#include<iostream>
using namespace std;
void sepData(int data[][5], const int& n, const int& m, int**& pos, int**& neg)
{
	int count1 = 0;
	int count2 = 0;
	pos = new int* [n];
	neg = new int* [n];
	for (int i = 0;i < n;i++)
	{
		count1 = 0;
		count2 = 0;
		for (int j = 0;j < m;j++)
		{
			if (data[i][j] > 0)
			{
				count1++;
			}
			else
				count2++;
		}
		pos[i] = new int [count1 + 1];
		neg[i] = new int [count2 + 1];
		pos[i][count1] = -1;
		neg[i][count2] = -1;
	}
	for (int i = 0;i < n;i++)
	{
		int x = 0;
		int y = 0;
		for (int j = 0;j < m;j++)
		{
			if (data[i][j] > 0)
			{
				pos[i][x] = data[i][j];
			}
			else
			{
				neg[i][y] = data[i][j];
				y++;
			}

		}
	}

}
int main()
{
	const int n = 3, m = 5;
	int data[n][m] = { {10, -3, 5, -7 ,8},
					  {-8, 9, -1, -6, -4},
					   {7, -5, 4,-9, 23 } };
	int** pos = new int* [n];
	int** neg = new int* [n];
	sepData(data, n, m, pos, neg);
	
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;pos[i][j] != -1;j++)
		{
			cout << pos[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;neg[i][j] != -1;j++)
		{
			cout << neg[i][j] << " ";
		}
		cout << endl;
	}
}