#include<iostream>
using namespace std;
int main()
{

	int a[4] = { 10,5,8,3 };
	int temp,cn,i,j;
	for (int i = 0;i < 4;i++)
	{
		cn = i;
		for (int j = i + 1;j < 4;j++)
		{
			if (a[cn] < a[j])        //find maximum digit and put on first position 
			{
				cn = j;
			       
			}
		}
		temp = a[cn];
		a[cn] = a[i];
		a[i] = temp;
	}
	
	for (int j = 1;j < 4;j++)
	{
		cn = j;
		for (int k = j + 1;k < 4;k++)
		{
			if(a[cn]>a[k])               //find minimum digit and put on second position 
				{                       
				cn = k;
				}
		}
		temp = a[cn];
		a[cn] = a[j];
		a[j] = temp;
	}
    cout<<"First element is fist maximum and 2nd element is first minimum\n";
	for (int i = 0;i < 4;i++)
	{
		cout << a[i] << " ";
	}
}