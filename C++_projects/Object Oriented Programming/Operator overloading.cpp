#include<iostream>
using namespace std;
class  number
{
	int a;
	int b;
public:
	number(int x=0,int y=0):a(x),b(y)
	{ }
	number(const number& obj)
	{
		this->a = obj.a;
		this->b = obj.b;
	}
	number& operator++(int)
	{
		number* temp = new number;
		*temp = *this;
		a++;
		b++;
		return *temp;
	}
	number& operator++()
	{
		a++;
		b++;
		return *this;
	}
	void print()
	{
		cout << a << " " << b<<endl;
	}
	number operator+(number& obj)
	{
		number res;
		res.a =( this->a + obj.a);
		res.b =( this->b + obj.b);
		return res;
	}
	number operator=(number& obj)
	{
		a = obj.a;
		b = obj.b;
		return *this;
	}
	friend ostream& operator<<(ostream& print, number& obj);
	//friend number& operator++(number& obj, int);

};
ostream& operator<<(ostream& print, number& obj)
{
	print << obj.a << " " << obj.b<<endl;
	return print;
}
//number& operator++(number& obj, int)
//{
//	(obj.a)++;
//	(obj.b)++;
//	return obj;
//
//}


int main()
{
	number n1(5, 5);
	number n2(3, 6);
	number n3= n1++ + n2++;
	cout << n3;
	//n3.print();
	n1.print();
	n2.print();

}