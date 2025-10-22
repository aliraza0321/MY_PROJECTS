#include<iostream>
using namespace std;

// Engine class
class Engine {
	string model;
public:
	Engine(string model)
	{
		this->model = model;
	}
	void printDetails() const
	{
		cout << "Model is " << model<<endl;
	}
};
// Wheel class
class Wheel {
	int size;
public:
	Wheel(int size)
	{
		this->size = size;
	}
	void printDetails() const
	{ 
		cout << "Size is " << size;
	}
};
// Car class - aggregates Engine and Wheel
class Car {
	string name;
	Engine&engine;
	Wheel& wheel;
public:
	Car(string n, Engine& e, Wheel& w):engine(e),wheel(w)
	{
		name = n;
	}

	void printDetails() const
	{
		cout << "Name is " << name << endl;
		engine.printDetails();
		wheel.printDetails();
	}

};
int main() {
	Engine e1("V8");
	Wheel w1(17);
	Car car1("Mustang", e1, w1);
	car1.printDetails();

	Engine e2("Hybrid");
	Wheel w2(15);
	Car car2("Prius ", e2, w2);
	car2.printDetails();
	return 0;
}