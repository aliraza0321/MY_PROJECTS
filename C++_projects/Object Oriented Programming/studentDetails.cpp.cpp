#include<iostream>
using namespace std;
class Student
{
	char* name = new char[20];
	int age;
	int* grade = new int[10];
	int numGrade;
public:
	//initialize parameters of constructor with null values
	Student(char* n = nullptr, int a = 0, int* g = nullptr, int num=0)
	{
		name = n;
		age = a;
		grade = g;
		numGrade = num;
	}
	void inputDetails()
	{//taking input 
		int size;
		cout << "\nEnter size of name:";
		cin >> size;
		name = new char[size+1];
		cout << "Enter name of student:";
		for (int i = 0;i < size;i++)
		{
			cin >> name[i];

		}
		name[size] = '\0';
		cout << "Enter age of Student: ";
		cin >> age;
		cout << "Enter number of grades:";
		cin >> numGrade;
		cout << "Enter grades :";
		grade = new int[numGrade+1];
		for (int i = 0;i < numGrade;i++)
		{
			cin >> *(grade + i);
		}
		grade[numGrade] = -1;
	}
	~Student()
	{//called destructor when we come back from class and clean dynamic memory 
		delete[]name;
		delete[]grade;
		name = nullptr;
		grade = nullptr;
	}
	float calavg(int*& g, int& n)
	{//calculate average and return final result
		float sum = 0;
		for (int i = 0;grade[i] != -1;i++)
		{
			sum += grade[i];
		}
		float result = sum / n;
		return result;
	}
	void displayDetails()
	{
		cout << "Name is : ";
		for (int i = 0;name[i] != '\0';i++)
		{
			cout << name[i];
		}
		cout << "\nAge is : " << age;
		cout << "\nGrades: ";
		for (int i = 0;grade[i] != -1;i++)
		{
			cout << grade[i] << " ";
		}
		float avg = calavg(grade, numGrade);
		cout << "\nAverage of Grades is : " << avg;
	}


};
int main()
{
	//taking input from user of size of studens then create objects and perform operations 

	int size;
	cout << "Enter number of Students:";
	cin >> size;
	for (int i = 1;i <= size;i++)
	{
		cout << "\nEnter details for student "<<i;
		Student s;
		s.inputDetails();
		s.displayDetails();
	}


}