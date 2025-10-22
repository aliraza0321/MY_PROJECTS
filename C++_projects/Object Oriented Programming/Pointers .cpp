#include<iostream>
using namespace std;
int main()
{
	int* p1;
	int x = 40, y = 60;
	p1 = &x;
	*p1 = 30;  //dereferencing of variable
	const int* p2;
	const int size = 50;
	p2 = &size;
	p2 = &y;
	int* const p3 = &x;
	*p3 = 70;
	const int* const p4=&y;
	int& a = x;
	a = 90;
	cout << a << " " << x;
	const int& b = x;
	x = 70;


}