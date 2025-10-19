#include<iostream>
using namespace std;
int main()
{
	//int a=10;
	//int *ptr=&a;
	//cout<<ptr<<endl;
//	cout<<*ptr<<endl;
//	cout<<++(*ptr)<<endl;
    int array[]={1,2,3,4,5};
    int *ptr=array;
    cout<<*ptr<<",";
    cout<<*(ptr+1)<<",";
    cout<<*(ptr+2)<<",";
    cout<<*(ptr+3)<<",";
    cout<<*(ptr+4)<<endl;
    char alp[]={'a','e','i','o','u'};
    char *ptr1=alp;
    cout<<*ptr1<<",";
    cout<<*(ptr1+1)<<",";
    cout<<*(ptr1+2)<<",";
    cout<<*(ptr1+3)<<",";
    cout<<*(ptr1+4)<<endl;
    
}