#include<iostream>
using namespace std;
void extract(char d[], char**& s)
{
	int count = 0;
	for (int i = 0;d[i] != '\0';i++)
	{
		if (d[i] == '@')
		{
			count++;
		}
	}
	int n = 0;
	s = new char* [count];
	for (int i = 0;d[i] != '\0';i++)
	{
		int temp = 0;
		if (d[i] == '@')
		{
			for (int j = i;d[j] != '.';j++)
			{
				temp++;
			}
			s[n] = new char[temp];
			n++;
			s[temp + 1] = '\0';
		}

	}
	for (int i = 0;d[i] != '\0';i++)
	{
		int x = 0;
		int y = 0;
		if (d[i] == '@')
		{
			for (int j = i;d[j] != '.';j++)
			{
			  for(int )
			}
			
			
		}

	}
}
void deallocate(char**& s)
{
	delete[]s;
	s = nullptr;
}
int main()
{
	char** service;
	char data[]= "I tried to reach Sarah at her @gmail.com address, but she prefers using her @icloud.com for more privacy, while John sent his update from his @outlook.com account and Janereplied from her @yahoo.com email.";
	extract(data, service);
	deallocate(service);
}