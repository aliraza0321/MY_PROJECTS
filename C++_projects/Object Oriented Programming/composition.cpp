#include<iostream>
using namespace std;
//assosication 
//composition and aggrigation
//Assosiation means communication between two independent class 
//weak association  aggrigation
//strong association  
//  Composition
class A
{
public:
	void display()
	{

	}
};
class B
{//the obj of A will create when we create obj of B in main function 
//it will delete when we delete obj of B
	A *obj;
public:
	B(A* p)
	{
		obj = p;
	}
	void display()
	{
		
	}
};
class student
{
	int size;
	char* ptr;
	//const int count;
	//static variable
	static int rate;
public:
	student(int s=0,  char* p=0,int c=0)
	{
		rate++;
		size = s;
		ptr = new char[size];
		for (int i = 0;i < size;i++)
		{
			ptr[i] = p[i];
		}
	}
	student(student& obj)
	{

	}
	student(student&& obj)
	{
		size = this->size;
		ptr = this->ptr;//shallow 
		ptr = nullptr;
		size = 0;

	}
	void operator=(student&& obj)
	{
		size = this->size;
		ptr = this->ptr;//shallow 
		ptr = nullptr;
		size = 0;
	}
	void print() const
	{
		//We cannot perform any operation on data members of class
		//And we cannot call any non const functions from this function
	}
	~student()
	{
		rate--;
	}
	//static function
	static void display()//independent on creation of obj
	{//we can only access static variables 
	//we can only call static function from this function
		cout << "Hello ";
	}
	//inline functions
     inline void product()
	{
		//
	}
	 bool operator!=(student& obj)
	 {
		 if (size != this->size)
		 {
			 return true;
		 }
	 }
};
int student::rate = 0;
//inheritance

int mian()
{
	A a1;
	B b1(&a1);//association and aggigation 
	//in case of composition only one obj will create then other obj also create automatically in that particulr class

	int a = 9;
	int b = 4;
	a == b;

	student::display();
	char name[] = "Ali";
	student s1(3, name);
	//name[] = "Hassan";
	//When we create any new obj and assign existing obj  
	//deep copy and shallow copy
	//copy ctr of compiler or 
	student s2;
	//s2 = move(s1);
	cout << (s1 != s2);
	

	s1.product();//address line 57   file size will increase  if we have minimum line of code in our inline function
	int a = 9;
	int b = 4;
	a = b;
	b = 3;
	a = 3;
}