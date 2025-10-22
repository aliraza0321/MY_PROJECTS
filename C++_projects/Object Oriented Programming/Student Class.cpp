#include<iostream>
#include<cstring>
using namespace std;
class Student
{
	string name;
	string rollNum;
	int sem;
public:
	Student(string n = " ", string r = " ", int s=0)
	{
		name = n;
		rollNum = r;
		sem = s;

	}
	virtual void display()
	{
		cout <<"Name is "<< name << endl;
		cout << "Roll no "<<rollNum << endl;
		cout << "Semester "<< sem << endl;
	}
	virtual float calculateFee()
	{
		return 0;
	}
	void study()
	{
		cout << "Studing for exams..." << endl;
	}
};
class Undergraduate:public Student
{
	bool isHos;
public:
	Undergraduate(string n = " ", string r = " ", int s=0, bool h = 0) :Student(n, r, s)
	{
		isHos = h;
	}

	void display()
	{
		cout << "hostal " << isHos << endl;
		Student::display();
	}
	float calculateFee()
	{
		return 50000;
	}
};
class Graduate:public Student
{
	string thesis;
public:
	Graduate(string n = " ", string r = " ", int s=0, string t = " ") :Student(n, r, s)
	{
		thesis = t;
	}
	void display()
	{
		cout << "Thesis is  " << thesis << endl;
		Student::display();
	}
	float calculateFee()
	{
		return 75000;
	}


};
int main()
{
	Undergraduate s1("Ali Raza", "24L-0857", 2, false);
	s1.display();
	Graduate s2("Ali Raza", "24L-0857", 2, "The world has become global village due to technology");
	s2.display();

}