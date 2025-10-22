
#include<iostream>
using namespace std;
class Rectangle
{
	int length, width, area;
public:
	Rectangle()
	{
		cout << "Default Constructor is calling :\n";
		length = 1;
		width = 1;
	}
	Rectangle(int  l, int  w)
	{
		cout << "Rectangle parameterized constructor is calling \n";

		length = l;
		width = w;
	}
	void set_length(int l)
	{
		if (l < 0)
		{
			cout << "x\nLength should be greater than zero. ";
			return;
		}
		length = l;
	}
	void set_width(int w)
	{
		if (w <= 0)
		{
			cout << "\nWidth should be greater than zero. \n";
			return;
		}
		width = w;
	}
	int get_length()
	{
		return length;
	}
	int get_width()
	{
		return width;
	}
	void cal_area()
	{
		 area = length * width;
		 
	}
	bool is_square()
	{
		if (length == width)
		{
			return true;
		}
		return false;
	}
	void print()
	{
	
		cout << "\nLength : " << length << " Width : " << width << "Area : " <<area<<endl;

		for (int i = 1; i <= length; i++)
		{
			for (int j = 1; j <= width; j++)
			{
				cout << "*" << " ";
			}
			cout << endl;
		}
	}


};
class Cuboid
{
	int length, width, height, volume, surfaceArea;
public:
	Cuboid()
	{
		cout << "Default constructor is calling for cuboid\n";
		length = 1;
		width = 1;
		height = 1;
	}
	Cuboid(int h, int w, int l)
	{
		cout << "Parameterized constructor is calling ";
		height = h;
		width = w;
		length = l;
	}
	void set_length(int l)
	{
		while (l < 0)
		{
			cout << "\nLength should be greater than zero . \n";
			return;
		}

		length = l;
	}
	void set_width(int w)
	{
		if (w <= 0)
		{
			cout << "\n Width should be greater than zero . ";
			return;
		}
		width = w;
	}
	void set_height(int h)
	{

		if (h <= 0)
		{
			cout << "\nHeight should be greater than zero.";
			return;
		}
		height = h;
	}
	int get_length()
	{
		return length;
	}
	int get_width()
	{
		return width;
	}
	int get_height()
	{
		return height;
	}
	void cal_volume()
	{
		volume = height * width * length;
	
	}
	void calc_surface_Area()
	{
		surfaceArea = (2 * length * width + 2 * height * height + 2 * width * height);
		
	}
	bool cube()
	{
		if ((length == width)&&(length == height))
		{
			return true;
		}
		return false;
	}
	void print()
	{
		cout << "\nCuboid's length is : " << length << endl;
		cout << "Cuboid's width is : " << width << endl;
		cout << "Cuboid's height is : " << height << endl;
		cout << "Cuboid's volume is : " << volume << endl;
		cout << "Cuboid's surfaceArea is : " << surfaceArea << endl;

	}
};
int main()
{
	Rectangle R1;
	R1.cal_area();
	R1.print();
	Cuboid C1;
	C1.calc_surface_Area();
	C1.cal_volume();
	C1.print();
	Rectangle R2(4, 5);
	Cuboid C2(3, 5, 6);
	R2.cal_area();
	R2.print();
	C2.calc_surface_Area();
	C2.cal_volume();
	C2.print();
	R1.set_length(-6);
	R1.set_width(0);
	C1.set_height(-5);
	C1.set_width(0);
	C1.set_length(2);
	R1.set_length(5);
	R1.set_width(5);
	C1.set_height(10);
	C1.set_width(10);
	C1.set_length(10);
	R1.cal_area();
	R1.print();
	C1.calc_surface_Area();
	C1.cal_volume();
	C1.print();
	if (R1.is_square())
		cout << "\n Rectangle is square . " << endl;
	if (C1.cube())
		cout << "Yes Cuboid is cube . " << endl;

}
