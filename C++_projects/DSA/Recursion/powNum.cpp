#include<iostream>
using namespace std;
int powFun(int x, int n)
{
	if (n == 0)
		return 1;
	else
		return x * powFun(x, n - 1);
}
int main()
{
    int x,n;
    cout<<"Enter number for base :";
    cin>>x;
    cout<<"Enter number for power :";
    cin>>n;
    cout<<"The new number is : "<<powFun(x,n);
}