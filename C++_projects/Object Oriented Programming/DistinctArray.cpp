//Ali Raza    24L-0857         BCS-2D
//HomeWork#1
#include<iostream>
using namespace std;
void allocateMemory(int*& p, int& size)
{
	cout << "Enter +ve size for array : ";
	cin >> size;
	while (size < 0)
	{
		cout << "Enter valid positive value: ";
		cin >> size;
	}
	p = new int[size];
//What if both parameters were b value?
//Answer : if we did receive both parameters by value then copy of parametes 
//create in this function and all operaions will perform on copies and when 
//function is finished then copies also destroyed and data in copies also lose
//therefore for saving data in main function parameters recevied by reference
}
void getData(int* const& p, int* const& q,int size)
{//receive size for terminate for loop because i is used to jump in array to 
//next index because pointers are constant that can't move in any other location
	 
	for (int i = 0;i < size;i++)
	{
		if (p+i <= q)
		{
			cout << "Enter positive dataa: ";
			cin >> *(p + i);
			while ((*(p + i)) < 0)
			{
				cout << "! Please Enter positive data: ";
				cin >> *(p + i);
			}
		}
	}
//Q; What if we receive parameters as by reference const pointer to const int?
//Ans : we are receiving pointers to get input from user and we take pointer by reference 
//so that all data should be saved in main function and we receive  const pointer so that we 
//cannot move to any other location but if we recive parametere by reference const p to const int 
//then we unable to change data and modify data of pointer or array 
//therefore we did not take by reference const pointer to const int
}

void printArray(const int* const& p, const int& s)
{
	cout << "\nYour array is : ";
	for (int i = 0;i < s;i++)
	{
		cout << *(p + i) << " ";
	}
//For saving memory we receive parameters by reference .Alias of parameters will be create and point same memory location.
//As we don't want our pointer will point any other memory location therefore we make our pointer constant .
//As we take our array from the user and we didn't want to modify values of array and we only used array for read only task therefor we make 
 //our pointer is const pointer to const integar.
//For saving memory and don't change the value of size we make it  reference const int and alias is created and s is used for only read only task 
}

void getDistinct(int*& p, int& s)
{
	int count = s;
	for (int i = 0;i < count;i++)
	{
		for (int j = i + 1;j < count;j++)
		{
			if (*(p+i) == *(p+j))
			{
				for (int k = j;k < count;k++)
				{
					*(p+k) = *(p + k + 1);
				}
				j--;
				count--;
			}
		}
	}
	int* temp = new int[count];
	for (int i = 0;i < count;i++)
	{
		*(temp + i) = *(p + i);
	}
	delete[]p;
	p = nullptr;
	p = temp; 
	s = count;
}
void releaseRes(int*&const p, int& s)
{
	delete[]p;    //data that stored on heap using this keyword will be cleared and p become dangling pointer 
	p = nullptr;   //Now p is not pointing any memory we can perform any operation on pointer p 

//if we receive pointer by reference const pointer then we can't change position of pointer and pointer can't access of any other variable
}
int main()
{
	int* ptr = NULL;
	int size = 0;
	allocateMemory(ptr, size);
	int* ptr1 = &ptr[size - 1];//ptr1 is storing the address of last index of array 
	getData(ptr, ptr1,size);//pass both pointers for getting input and size for holding for loop in function
	
	getDistinct(ptr, size);
	printArray(ptr, size);
	releaseRes(ptr, size);
	printArray(ptr, size);
	//after releasing resouces all memory  that was using now all is cleaned dynamic array that is created on heap also clean and pointer that 
	// point that particular memory now that is also free to point any other memory and store any address of variables or for any other dynamic array 
}