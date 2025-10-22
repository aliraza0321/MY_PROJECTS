#include<iostream>
using namespace std;
void compress(int d[][4], int**& p)
{
	int count = 0;
	for (int i = 0;i < 4;i++)
	{
		count = 0;
		for (int j = 0;j < 4;j++)
		{
			if (d[i][j] > 0)
			{
				count++;
			}
		}
		p[i] = new int[count + 1];
		p[i][count] = -1;
	}
	for (int i = 0;i < 4;i++)
	{
		int x = 0;
		for (int j = 0;j < 4;j++)
		{
			if (d[i][j] > 0)
			{
				p[i][x] = d[i][j];
				x++;
			}
		}
		
	}
}
int main()
{
	int data[4][4] = { {32,0,45,0},{0,12,0,0},{0,0,0,0},{76,33,21,0} };
	int** ptr=new int*[4];
	compress(data, ptr);
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;ptr[i][j]!=-1;j++)
		{
			cout << ptr[i][j]<<" ";
		}
		cout << endl;
	}

}