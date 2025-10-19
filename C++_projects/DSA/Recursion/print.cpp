#include<iostream>
using namespace std;
void print(int n)
{
	if (n == 0)
		return ;
	else
	{
		
		print(n - 1);
        cout << n << " ";
		
	}
	
}
int main()
{
    
    cout<<"number till 10 is : ";
    print(10);
}