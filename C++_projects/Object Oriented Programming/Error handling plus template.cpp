#include<iostream>
using namespace std;
template<class T>
class safeArray
{
	T arr[5];
public:
	void set(int index, T value)
	{
		if (index < 0 || index >= 5)
		{
			throw index;
		}
		arr[index] = value;
	}
	T get(int index)
	{
		if (index < 0 || index >= 5)
		{
			throw index;
		}
		return arr[index];
	}
};
int main()
{
	safeArray<int> obj;
	try {
		obj.set(2, 100);
		cout << "VAlue at index :2 " << obj.get(2) << endl;
		obj.set(10, 50);
	}
	catch (int idx)
	{
		cout << "Index " << idx << "is out of bounds!" << endl;
	}
}