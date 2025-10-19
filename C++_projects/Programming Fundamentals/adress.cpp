#include<iostream>
using namespace std;
void changeA(int* ptr)
{
	*ptr=20;
}
int main()
{
	int a=10;
	changeA(&a);
	cout<<a;
/*	int a=9;
	cout<<&a<<endl;
	int* ptr=&a;
	cout<<ptr<<endl;
	cout<<*(ptr);*/
//	int *ptr=NULL;
//	cout<<ptr;

}