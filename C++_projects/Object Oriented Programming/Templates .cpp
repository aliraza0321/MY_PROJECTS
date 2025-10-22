#include<iostream>
using namespace std;
template <typename T>
T findMax(T a,T b,T c)
{
	T max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;


}
int main()
{
	cout << "Max of 4,9,2 is :" << findMax(4, 9, 2) << endl;
	cout << "Max of 'a','z','m' is : " << findMax('a', 'z', 'm') << endl;
	cout << "Max of 4.5,1.2 ,3.9 is :" << findMax(4.5, 1.2, 3.9);
}