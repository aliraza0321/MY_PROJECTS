#include <iostream>
using namespace std;

class BiggerInt
{

   int* big_int_;   // Pointer to dynamically allocated array to store large integers
   int int_length_; // Length of the array

public:
   // Default constructor
   BiggerInt() 
   {
       big_int_ = nullptr;
       int_length_ = 0;
   }

   // Overloaded constructor that takes an integer array and its size
   BiggerInt(const int* big_int, int size) 
   {
       int_length_ = size;
       big_int_ = new int[int_length_]; // Allocate memory for the array
       for (int i = 0; i < int_length_; i++) 
       {
           big_int_[i] = big_int[i]; // Perform deep copy
       }
   }

   // Copy constructor - performs deep copy
   BiggerInt(const BiggerInt& obj) 
   {
       int_length_ = obj.int_length_;
       big_int_ = new int[int_length_]; // Allocate memory for the array
       for (int i = 0; i < int_length_; i++) 
       {
           big_int_[i] = obj.big_int_[i]; // Deep copy the values
       }
   }

   // Destructor - frees dynamically allocated memory
   ~BiggerInt() 
   {
       delete[] big_int_;
   }

   // Assign values from another BiggerInt (deep copy)
   void assign(const BiggerInt& obj) 
   {
       if (big_int_ != nullptr) 
       {
           delete[] big_int_; // Release existing memory
       }

       int_length_ = obj.int_length_;
       big_int_ = new int[int_length_]; // Allocate new memory
       for (int i = 0; i < int_length_; i++) 
       {
           big_int_[i] = obj.big_int_[i]; // Perform deep copy
       }
   }

   // Assign values from an integer array (deep copy)
   void assign(const int* big_int, int size)
   {
       if (big_int_ != nullptr) {
           delete[] big_int_; // Release existing memory
       }

       int_length_ = size;
       big_int_ = new int[int_length_]; // Allocate new memory
       for (int i = 0; i < int_length_; i++)
       {
           big_int_[i] = big_int[i]; // Perform deep copy
       }
   }

   // Append another BiggerInt object (deep copy)
   void append(const BiggerInt& obj) 
   {
       int new_length = int_length_ + obj.int_length_;
       int* new_big_int = new int[new_length]; // Allocate new memory

       // Copy current big integer to new array
       for (int i = 0; i < int_length_; i++)
       {
           new_big_int[i] = big_int_[i];
       }

       // Append the new big integer array to the new array
       for (int i = 0; i < obj.int_length_; i++)
       {
           new_big_int[int_length_ + i] = obj.big_int_[i];
       }

       // Free old memory
       delete[] big_int_;
       big_int_ = new_big_int;
       int_length_ = new_length;
   }

   // Append values from an integer array (deep copy)
   void append(const int* big_int, int size)
   {
       int new_length = int_length_ + size;
       int* new_big_int = new int[new_length]; // Allocate new memory

       // Copy current big integer to new array
       for (int i = 0; i < int_length_; i++)
       {
           new_big_int[i] = big_int_[i];
       }

       // Append the new big integer array to the new array
       for (int i = 0; i < size; i++)
       {
           new_big_int[int_length_ + i] = big_int[i];
       }

       // Free old memory
       delete[] big_int_;
       big_int_ = new_big_int;
       int_length_ = new_length;
   }

   // Compare two BiggerInt objects
   int compareTo(const BiggerInt& obj) const
   {
       if (int_length_ < obj.int_length_)
       {
           return 1; // Current object is smaller
       }
       if (int_length_ > obj.int_length_) {
           return 2; // Current object is larger
       }

       // If sizes are equal, compare element by element
       for (int i = 0; i < int_length_; i++) 
       {
           if (big_int_[i] < obj.big_int_[i]) 
           {
               return 1; // Current object is smaller
           }
           if (big_int_[i] > obj.big_int_[i])
           {
               return 2; // Current object is larger
           }
       }

       return 0; // Objects are equal
   }

   // Compare the current object with an integer array
   int compareTo(const int* big_int, int size) const
   {
       if (int_length_ < size)
       {
           return 1; // Current object is smaller
       }
       if (int_length_ > size)
       {
           return 2; // Current object is larger
       }

       // If sizes are equal, compare element by element
       for (int i = 0; i < int_length_; i++)
       {
           if (big_int_[i] < big_int[i])
           {
               return 1; // Current object is smaller
           }
           if (big_int_[i] > big_int[i])
           {
               return 2; // Current object is larger
           }
       }

       return 0; // Objects are equal
   }

   // Display the big integer in space-separated format
   void display() 
       
   {
       if (big_int_ == nullptr || int_length_ == 0) 
       {
           cout << "No Value Assigned" << endl;
           return;
       }

       for (int i = 0; i < int_length_; i++) 
       {
           cout << big_int_[i] << " ";
       }
       cout << endl;
   }
};

int main() 
{
   // Creating objects using an integer array
   int arr1[] = { 9, 2, 5 };
   int arr2[] = { 3, 7, 1 };

   BiggerInt b1(arr1, 3);
   BiggerInt b2(arr2, 3);

   cout << "Object b1: ";
   b1.display(); // Display b1
   cout << "Object b2: ";
   b2.display(); // Display b2

   // Assigning values from another BiggerInt object
   BiggerInt b3;
   b3.assign(b1);
   cout << "Object b3 (assigned from b1): ";
   b3.display();

   // Appending another BiggerInt object
   b1.append(b2);
   cout << "Object b1 after append from b2: ";
   b1.display();

   // Comparing BiggerInt objects
   int result = b1.compareTo(b3);
   cout << "Comparison of b1 and b3: ";
   if (result == 0)
   {
       cout << "b1 is equal to b3." << endl;
   }
   else if (result == 1)
   {
       cout << "b1 is smaller than b3." << endl;
   }
   else
   {
       cout << "b1 is larger than b3." << endl;
   }

   return 0;
}
