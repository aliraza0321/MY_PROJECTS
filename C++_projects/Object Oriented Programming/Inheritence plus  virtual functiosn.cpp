#include <iostream>
using namespace std;
class Appliance {
public:
	virtual void powerConsumption()  = 0; // pure virtual
	
};
class WashingMachine : public Appliance {
public:
	// TODO: Implement powerConsumption() for WashingMachine
	void powerConsumption()override
	{
		cout << "Washing Machine consumes some powre" << endl;
	}
};
class Refrigerator : public Appliance {
public:
	// TODO: Implement powerConsumption() for Refrigerator
	void powerConsumption()override
	{
		cout << "Refrigerator consumes some powre" << endl;
	}
};
class Microwave : public Appliance {

public:
	// TODO: Implement powerConsumption() for Microwave
	void powerConsumption()override
	{
		cout << "microwave consumes some powre" << endl;
	}
};
int main() {
	// TODO: Create objects and call powerConsumption() using
	Appliance *a1=new Microwave;
	a1->powerConsumption();
		return 0;
}