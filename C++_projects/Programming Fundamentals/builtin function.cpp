#include<iostream>
#include<ctype.h>
#include<stdio.h>
using namespace std;
int main()
{
	int dig=0,pun=0,other=0,lc=0,uc=0,sp=0;
	char c;
	cout<<"Enter a whole string : ";
	while((c=getchar())!='\n')
	{
		if(islower(c))
		{
			lc++;
		}
		else if(isupper(c))
		{
			uc++;
		}
		else if(isspace(c))
		{
			sp++;
		}
		else if(isdigit(c))
		{
			dig++;
		}
		else if(ispunct(c))
		{
			pun++;
		}
		else
		{
			other++;
		}
	}
	cout<<"You typed : "<<endl;
	cout<<"Small letter : "<<lc<<endl;
	cout<<"Capital Letter : "<<uc<<endl;
	cout<<"Digts : "<<dig<<endl;
	cout<<"Space : "<<sp<<endl;
	cout<<"Punctuation : "<<pun<<endl;
	cout<<"Others : "<<other<<endl;
}