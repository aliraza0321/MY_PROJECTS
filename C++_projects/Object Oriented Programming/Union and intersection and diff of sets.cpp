#include <iostream>
using namespace std;

class Set
{
   int* data; // Pointer to an array representing the set
   int size;  // Number of elements in the set
   int capacity; // Maximum possible number of elements that can be stored

public:
   // Default constructor
   Set() 
   {
       data = nullptr;
       size = 0;
       capacity = 0;
   }

   // Parameterized constructor
   Set(int* elements, int s)
   {
       size = s;
       capacity = 2 * s; // Capacity is double the size
       data = new int[capacity]; // Dynamically allocate memory

       // Copy elements into data
       for (int i = 0; i < size; i++) 
       {
           data[i] = elements[i];
       }

       // Fill the rest of the array with 0
       for (int i = size; i < capacity; i++)
       {
           data[i] = 0;
       }
   }

   // Copy constructor (deep copy)
   Set(const Set& obj) 
   {
       size = obj.size;
       capacity = obj.capacity;
       data = new int[capacity];

       // Copy the elements into the new object
       for (int i = 0; i < size; i++) 
       {
           data[i] = obj.data[i];
       }

       // Fill the rest of the array with 0
       for (int i = size; i < capacity; i++)
       {
           data[i] = 0;
       }
   }

   // Destructor to free allocated memory
   ~Set() {
       delete[] data;
   }

   // Insert a value into the set
   void insert(int value) 
   {
       if (size == capacity)
       {
           cout << "Insufficient memory" << endl;
           return;
       }

       // Check for duplicate
       for (int i = 0; i < size; i++)
       {
           if (data[i] == value)
           {
               cout << "Duplicate element" << endl;
               return;
           }
       }

       // Insert the value at the current size index
       data[size] = value;
       size++;
   }

   // Remove a value from the set
   void remove(int value) 
   {
       bool found = false;
       for (int i = 0; i < size; i++)
       {
           if (data[i] == value) 
           {
               found = true;
               // Shift elements to the left to remove the value
               for (int j = i; j < size - 1; j++) 
               {
                   data[j] = data[j + 1];
               }
               data[size - 1] = 0; // Set the last element to 0
               size--;
               break;
           }
       }

       if (!found) 
       {
           cout << "No such value exists" << endl;
       }
   }

   // Union of two sets
   void Union(const Set& s2) 
   {
       Set obj;
       obj.capacity = size + s2.size; // New capacity to store all unique elements
       obj.size = 0;
       obj.data = new int[obj.capacity];

       // Copy all elements from this set
       for (int i = 0; i < size; i++) 
       {
           obj.data[obj.size++] = data[i];
       }

       // Add elements from the second set if not already present
       for (int i = 0; i < s2.size; i++)
       {
           bool found = false;
           for (int j = 0; j < obj.size; j++) 
           {
               if (obj.data[j] == s2.data[i])
               {
                   found = true;
                   break;
               }
           }
           if (!found)
           {
               obj.data[obj.size++] = s2.data[i];
           }
       }

       // Print the union
       cout << "Union: {";
       for (int i = 0; i < obj.size; i++)
       {
           cout << obj.data[i] << " ";
       }
       cout << "}" << endl;

       // Free memory
       delete[] obj.data;
   }

   // Intersection of two sets
   void intersection(const Set& s2) 
   {
       Set obj;
       obj.capacity = size < s2.size ? size : s2.size; // Intersection can't exceed the smaller size
       obj.size = 0;
       obj.data = new int[obj.capacity];

       // Find common elements
       for (int i = 0; i < size; i++) 
       {
           for (int j = 0; j < s2.size; j++)
           {
               if (data[i] == s2.data[j])
               {
                   obj.data[obj.size++] = data[i];
                   break;
               }
           }
       }

       // Print the intersection
       cout << "Intersection: {";
       for (int i = 0; i < obj.size; i++) 
       {
           cout << obj.data[i] << " ";
       }
       cout << "}" << endl;

       // Free memory
       delete[] obj.data;
   }

   // Print the set
   void print() 
   {
       cout << "Set: {";
       for (int i = 0; i < capacity; i++) 
       {
           if (data[i] != 0) {
               cout << data[i] << " ";
           }
       }
       cout << "}" << endl;
   }

   // Overloaded assignment operator (deep copy)
   Set& operator=(const Set& obj)
   {
       if (this == &obj) 
       {
           return *this; // Self-assignment check
       }

       delete[] data; // Free existing memory

       size = obj.size;
       capacity = obj.capacity;
       data = new int[capacity];

       // Copy elements from obj to this object
       for (int i = 0; i < size; i++)
       {
           data[i] = obj.data[i];
       }

       // Fill the rest of the array with 0
       for (int i = size; i < capacity; i++) 
       {
           data[i] = 0;
       }

       return *this;
   }
};

int main() {
   int arr1[] = { 7, 9, 1, 5, 8 };
   int arr2[] = { 2, 7, 3, 9, 5 };

   Set s1(arr1, sizeof(arr1) / sizeof(int));
   Set s2(arr2, sizeof(arr2) / sizeof(int));
   Set s3(s1);
   Set s4 = s2;

   s1.insert(8); // Duplicate value
   s2.insert(3); // Duplicate value
   for (int i = 0; i < 5; i++)
   {
       s1.insert(i + 10);
   }
   s1.insert(50); // Insufficient memory
   s2.remove(10); // No such value exists
   s1.remove(10);

   s3.Union(s4); // {7, 9, 1, 5, 8, 2, 3}
   s3.intersection(s4); // {7, 9, 5}

   s1.print();
   s2.print();

   s2 = s1; // Deep copy

   s2.insert(120);
   s1.print(); // s1 should not be affected by changes in s2

   return 0;
}
