#include<iostream>
using namespace std;
class vehicle
{
	string brand;
	int speed;
public:
	vehicle()
	{ 
		speed = 0;
		brand = '\0';
	}
	vehicle(const char* p, int s)
	{
		brand = p;
		speed = s;
	}
	void start()
	{
		cout << "Vehicle is staring " << endl;
	}
	~vehicle()
	{

	}

};
class Car:public vehicle
{
	int door;
public:
	Car()
	{
		door = 0;
	}
	Car(const char* p, int s, int d) :vehicle(p, s)
	{
		door = d;
	}
	void  playMusic()
	{
		cout << "Music is playing in car" << endl;
	}
};
class Truck :public vehicle
{
	float load;
public:
	Truck()
	{
		load = 0;
	}
	Truck(const char* p, int s, float l) :vehicle(p, s)
	{
		load = l;
	}
	void loadCargo()
	{
		cout << "Cargo is loading on truck" << endl;
	}
};
class Bike :public vehicle
{
	bool start;
public:
	Bike()
	{
		start = false;
}
	Bike(const char* p, int s, bool start) :vehicle(p, s)
	{
		this->start = start;
	}
	void doWheelie()
	{
		cout << "Dowheelie is calling " << endl;
	}
	void start()
	{
		vehicle::start();
	}
};



int main() {
	Car myCar("Toyota", 120, 4);
	Truck myTruck("Volvo", 90, 12.5);
	Bike myBike("Yamaha", 100, true);

	myCar.start();
	myCar.playMusic();

	myTruck.start();
	myTruck.loadCargo();

	myBike.start();
	myBike.doWheelie();

}