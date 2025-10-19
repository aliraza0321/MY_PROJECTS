#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char data[100]="My,name,is,Ali,Raza";
	char list[100][100];
	char delimiter=',';
	int k=0;
	for(int i=0;i<100&&data[i]!='\0';i++)
	{
		for(int j=0;j<100&&data[i]!=delimiter&&data[i]!='\0';j++)
		{
			list[k][j]=data[i];
			i++;
		} 
		k++;
	}
	for(int i=0;i<100&&list[4][i]!='\0';i++)
	{
		cout<<list[0][i];
	}
}