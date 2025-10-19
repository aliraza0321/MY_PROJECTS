#include<iostream>
using namespace std;
int fac(int n)
{
   if(n==1)
   {
    return n;
   }
    return n*fac(n-1);
}
int main()
{
    int num;
    cout<<"Enter number for factorial : ";
    cin>>num;
    int res=fac(num);
    cout<<"factorial of  "<<num<<" is: "<<res;
}