#include<iostream>
using namespace std;
class SmartDevice
{
	string id;
	string name;
	bool isConnected;
	string location;
public:
	SmartDevice(string i = " ", string n = " ", string l = " ")
	{
		id = i;
		name = n;
		location = l;
	}
	string getDeviceid()
	{
		return id;
	}
	string getDeviceName()
	{
		return name;
	}
	string getLocation()
	{
		return location;
	}
	bool getStatus()
	{
		return isConnected;
	}
	void toggleConnection()
	{

	}
	virtual void executeAction() = 0;
	virtual void displayStatus() = 0;

};
class Smartlight :public SmartDevice
{
	int brightness;
	string color;
	bool isOn;
public:
	Smartlight(string i = " ", string n = " ", string l = " ", string c = " "):SmartDevice(i,n,l)
	{
		color = c;
	}
	void setBrightness(int l)
	{
		brightness = l;
	}
	void setColor(string c = " ")
	{
		color = c;
	}
	void turnON()
	{
		isOn = true;
	}
	void turnOff()
	{
		isOn = false;
	}
	bool getStatus()const
	{
		return isOn;
	}
	void executeAction()override
	{

	}
	void displayStatus()override
	{

	 }

};
class SmartThermostate :public SmartDevice
{
	float currTemp;
	float targTem;
	string mode;
public:
	SmartThermostate(string i = " ", string n = " ", string l = " ", float t = 0) :SmartDevice(i, n, l)
	{
		currTemp = t;
	}
	void setTargetTemp(float t)
	{
		targTem = t;
	}
	float getCurrTemp()const
	{
		return currTemp;
	}
	void setMode(string m = " ")
	{
		mode = m;
	}
	string getmode()const
	{
		return mode;
	}
	void executeAction()override
	{

	}
	void displayStatus()override
	{

	}
};
class SmartSecurity : public SmartDevice
{
	bool isArmed;
	int senLev;
	bool motDec;
public:
	SmartSecurity(string i = " ", string n = " ", string l = " ", int s) :SmartDevice(i, n, l)
	{
		senLev = s;
	}
	void arm()
	{
		isArmed = true;
	}
	void disArm()
	{
		isArmed = false;
	}
	bool getArmSta()const
	{
		return isArmed;
	}
	void setSensi(int l)
	{
		senLev = l;
	}
	void detectMo(bool d)
	{
		motDec = d;
	}
	void executeAction()override
	{

	}
	void displayStatus()override
	{

	}
};
class User
{
	string id;
	string Username;
	string accLevel;
public:
	User(string i = " ", string u = " ", string l = " ")
	{
		id = i;
		Username = u;
		accLevel = l;
	}
	string getId()const
	{
		return id;
	}
	string getName()const
	{
		return Username;
	}
	string getLev()const
	{
		return accLevel;

	}
	bool canControlDevice(const SmartDevice& device)const
	{

	}
};


