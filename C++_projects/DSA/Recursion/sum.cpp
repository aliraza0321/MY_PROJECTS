#include<iostream>
using namespace std;
int sum(int n)
{
   if(n==0)
   {
    return n;
   }
    return n+sum(n-1);
}
int main()
{
    int num;
    cout<<"Enter limit of numbers : ";
    cin>>num;
    int res=sum(num);
    cout<<"Sum of numbers till "<<num<<" is: "<<res;
}