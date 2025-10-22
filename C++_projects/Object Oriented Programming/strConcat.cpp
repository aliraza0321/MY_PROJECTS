#include<iostream>
using namespace std;
void strConcat(char*& const f, char*& l, char*& p)
{
	counting length of both arrays after that add both and add 2 extra one for space and one for null  character
	 create dynamic array of size  and firsly store last name in array and after last name store space 
	and then store first name into array 
	in last store null character p is by reference so it is permmanent in main function
	int size;
	int count1 = 0;
	int count2 = 0;
	for (int i = 0;*(f + i) != '\0';i++)
	{
		count1++;
	}
	for (int i = 0;*(l + i) != '\0';i++)
	{
		count2++;
	}
	size = count1 + count2;
	p = new char[size + 2];
	int s = 0;
	for (int i = 0;*(l + i) != '\0';i++)
	{
		*(p + s) = *(l + i);
		s++;
	}
	*(p + s) = ' ';
	s++;
	for (int i = 0;*(f + i) != '\0';i++)
	{
		*(p + s) = *(f + i);
		s++;
	}
	*(p + size + 1) = '\0';
}
void print( char*& const n)
{//print name after concatenate
	for (int i = 0;*(n + i) != '\0';i++)
	{
		cout << *(n + i);
	}
}
void deallocate(char*& n)
{//clean memory on heap and free dangling pointer 
	delete[]n;
	n = nullptr;
}
int main()
{
	char firstName[] = "Cristiano";
	char lastName[] = "Ronaldo";
	char* fName = firstName;
	char* lName = lastName;
	char* name = nullptr;
	strConcat(fName, lName, name);
	print(name);
	deallocate(name);
}