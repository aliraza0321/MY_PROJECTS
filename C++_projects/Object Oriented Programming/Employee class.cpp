#include<iostream>
using namespace std;
class Employee
{
	string empName;
	int empID;
public:
	Employee(string name = "", int id = 0)
	{
		empName = name;
		empID = id;
	}
	virtual void calculatePay()
	{
		 virtual function  virtual ~Employee()
		cout << "Calculate pay" << endl;
	}
	virtual ~Employee()
	{
		cout << "dtr of employee is calling" << endl;
	}
};
	class FullTimeEmployee : public Employee
	{
		float monthlySalary;
	public:
		FullTimeEmployee(string name = " ", int id = 0, float salary = 0.0) :Employee(name, id)
		{
			monthlySalary = salary;
		}
		void calculatePay()
		{
			cout << "Monthly salary  calculated" << endl;
		}
		~FullTimeEmployee()
		{
			cout << "dtr of second class is calling" << endl;
		}
	};
	class PartTimeEmployee : public Employee {
		float hourlyRate;
		int hoursWorked;
	public:
		PartTimeEmployee(string name=" ", int id=0, float rate=0.0, int hours=0) :Employee(name, id)
		{
			hourlyRate = rate;
			hoursWorked = hours;
		}
		void calculatePay()
		{
			cout << "Part time salary is calculated";
		}
		~PartTimeEmployee()
		{
			cout << "dtr  of part time  class is calaling" << endl;
		}
	};
	int main()
	{
		Employee* e1 = new PartTimeEmployee;
		delete e1;
		Employee* e2 = new FullTimeEmployee;
		delete e2;
	}
