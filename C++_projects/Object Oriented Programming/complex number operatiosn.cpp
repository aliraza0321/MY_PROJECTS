#include<iostream>
using namespace std;
class complex
{
	float* real;
	float* imag;
public:
	complex()
	{
		real = new float(0);
		imag = new float(0);
	}
	complex(float* r, float* i)
	{
		real = new float;
		imag = new float;
		*real = *r;
		*imag = *i;
	}
	complex(const complex& obj)
	{
		if (real)
			delete real;
		if (imag)
			delete imag;
		real = new float;
		imag = new float;
		*real = *(obj.real);
		*imag = *(obj.imag);
	}
	complex operator+(complex& obj)
	{
		complex res;
		*(res.real) = *(real)+ *(obj.real);
		*(res.imag) = *(real)+ *(obj.imag);
		return res;
	}
	complex operator-(complex& obj)
	{
		complex res;
		*(res.real) = *(real)-*(obj.real);
		*(res.imag) = *(real)-*(obj.imag);
		return res;
	}
	~complex()
	{
		delete real;
	    delete imag;
		real = 0;
		imag = 0;
	}
	bool operator==(complex& obj)
	{
		if ((*real == *(obj.real)) && *imag == *(obj.imag))
			return true;
		else
			return false;
	}
	friend istream& operator>>(istream& input, complex& obj);
	friend ostream& operator<<(ostream& output, complex& obj);

};
istream& operator>>(istream& input, complex& obj)
{
	float i, r;
	cin >> r >> i;
	*(obj.real)= r;
	*(obj.imag)= i;
	return input;
}
ostream& operator<<(ostream& output, complex& obj)
{
	output << *(obj.real) << " + " << *(obj.imag)<<"i";
	return output;
}
int main()
{
	complex c1;
	complex c2;
	cout << "Enter first complex numbers ";
	cin >> c1 ;
	cout << "Enter second complex number";
	cin >> c2;
	cout << "Result is ";
	complex c3 = c1 + c2;
	cout <<c3<<endl;
	bool flag;
	if (c1 == c2)
	{
		flag = true;
	}
	else
		flag = false;
	if (flag)
		cout << "Both are equal numbers";
	else
		cout << "Both are not equal";
}