
#include <iostream>
#include <string>
using namespace std;
class Person {

	string name;
public:
	Person(string n) : name(n) 
	{

	}
	void display() 
	{
		cout << "Name: " << name << endl;

	}
};
class Employee : virtual public Person
{
public:
	Employee(string n) : Person(n) {
	}

};
class Student : virtual public Person
{
public:
	Student(string n) : Person(n) {}
};
class Intern : public Employee, public Student 
{
public:
	Intern(string n) : Person(n), Employee(n), Student(n) {}
	// TODO: Demonstrate access to single instance of Person
};
int main() {
	Intern i("Jawad");
	// TODO: Call display and prove only one Person instance
	i.display();
}