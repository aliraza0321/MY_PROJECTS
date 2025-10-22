#include<iostream>
using namespace std;
class product
{
	string name;
	float price;
public:
	product()
	{
		name = '\0';
		price = 0;
	}
	product(const char*n, float p)
	{
		name = n;
		price = p;
	}
	void displayProduct()
	{
		cout << "Name is " << name << endl;
		cout << "Price is " << price;
	}
	~product()
	{

	}
};
class electronics:public product
{
	int period;
public:
	electronics()
	{
		period = 0;
	}
	electronics(const char*n, float p, int period) :product(n, p)
	{
		this->period = period;
	}
	void showWarranty()
	{
		cout << "\nWarranty is " << period << endl;
	}
};
class WashingMachine :public electronics
{
	float load;
public:

	WashingMachine()
	{
		load = 0;
	}
	WashingMachine(const char* n, float p, int period, float l) :electronics(n, p, period)
	{
		load = l;
	}
	void startWashCycle()
	{
		cout << "Washing is staring" << endl;
	}
};
class MicrowaveOven:public electronics
{
	float temp;
public:
	MicrowaveOven()
	{
		temp = 0;
	}
	MicrowaveOven(const char* n, float p, int period, float t) :electronics(n, p, period)
	{
		temp = t;
	}
	void startBakeMode()
	{
		cout << "Start mode is on" << endl;
	}
	void setBakeTime(int n)
	{
		cout << "Bake time is " << n;
	}
};


int main() {
	WashingMachine wm("TurboWash", 599.99, 2, 7.5);
	MicrowaveOven oven("Samsung BakePro ", 349.99, 1, 220);

	wm.displayProduct();
	wm.showWarranty();
	wm.startWashCycle();

	cout << endl;

	oven.displayProduct();
	oven.showWarranty();
	oven.startBakeMode();
	oven.setBakeTime(30);

	return 0;
}