#include<iostream>
using namespace std;
void encrypt(char [],int );
void decrypt(char [],int );
int main()
{
	char password[50];
	cout<<"Enter data for password\n ";
	cin.getline(password,50);
	cout<<"\n\nYour Encrypt password\n\n";
	encrypt(password,50);
	for(int i=0;password[i]!='\0';i++)
	{
		cout<<password[i];
	}
	cout<<"\n\nYour real password : "<<endl; 
	decrypt(password,50);
	for(int i=0;password[i]!='\0';i++)
	{
		cout<<password[i];
	}
}
void encrypt(char data[],int size)
{
	for(int i=0;data[i]!='\0';i++)
	{
		data[i]=(data[i]^5);
	}
}
void decrypt(char data[],int size)
{
	for(int i=0;data[i]!='\0';i++)
	{
		data[i]=(data[i]^5);
	}
}
