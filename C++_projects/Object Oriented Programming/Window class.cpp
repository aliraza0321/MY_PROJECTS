#include<iostream>
using namespace std;
class Window
{
	int width, height;
public:
	Window()
	{
		width = 0;
		height = 0;
	}
	Window(int w, int h)
	{
		width = h;
		height = h;
	}
	void setDimensions(int w, int h)
	{
		width = w;
		height = h;
	}
	void printDimensions() const
	{
		cout << "Width is " << width << endl;
		cout << "Height is " << height << endl;
	}
};
// Light class - heap object
class Light
{
	string type;
public:
	Light()
	{
		type = '\0';
	}
	Light(string t)
	{
		type = t;
	}
	void setType(string t)
	{
		type = t;
	}
	void printType() const
	{
		cout << "Type is " << type << endl;
	}
};
// Room class - composed of Window (stack) and Light (heap)
class Room
{
	Window window; // composition on stack
	Light* light; // composition on heap
public:
	Room()
	{
		light = nullptr;
	}
	Room(int w, int h, string lightType)
	{
		window.setDimensions(w, h);
		light = new Light;
		light->setType(lightType);
	}
	~Room()
	{
		delete[]light;
	}
	void setRoomDetails(int w, int h, string lightType)
	{
		if (light)
			delete[]light;
		window.setDimensions(w, h);
		light = new Light;
		light->setType(lightType);
	}
	void printRoomDetails() const
	{
		window.printDimensions();
		light->printType();
	}
};
int main() {
	Room r1(50, 100,"LED");
	r1.printRoomDetails();
	r1.setRoomDetails(60, 120,"CFL");
	r1.printRoomDetails();
	return 0;

}