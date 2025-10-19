#include<iostream>
using namespace std;
void updatestr(char []);
int main()
{
	char str[]="I am a student of programmimg of fundamental";
	updatestr(str);
	cout<<str;
}
void updatestr(char data[])
{
	for(int i=0;data[i]!='\0';i++)
	{
		if(data[i]>='a'&&data[i]<='z')
		{
			data[i]-=32;
		}
	}
}