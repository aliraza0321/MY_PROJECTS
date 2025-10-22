#include<iostream>
using namespace std;
class student
{
	char* name;
	int age;
	int edu;
	float height;
	float weight;
public:
	student(char* n = nullptr, int a = 0, int e = 0, float h = 0, float w = 0)
	{
		name = new char[0];
		age = a;
		edu = e;
		height = h;
		weight = w;
	}
	void getinput()
	{
		char n[10];
		cout << "\nEnter name of student : ";
		cin.getline(n, 10);
		int temp = strlen(n);
		name = new char[temp+1];
		name = n;
		name[temp] = '\0';
		cout << "\nEnter age : ";
		cin >> age;
		cout << "\nEnter education in digits : ";
		cin >> edu;
		cout << "\nEnter height and weight: ";
		cin >> height >> weight;


	}
	void print()
	{
		cout << "\n\nName is :";
		for (int i = 0;name[i] != '\0';i++)
			cout << name[i];
		cout << "\Age is : "<< age;
		cout << "\nEducation is "<< edu;
		cout << "\nHeight is : "<< height;
		cout << "\nWeight is : "<< weight;
	}
	~student()
	{
		delete[]name;
		name = nullptr;
	}
};
int main()
{
	student s1;
	s1.getinput();
	s1.print();
}