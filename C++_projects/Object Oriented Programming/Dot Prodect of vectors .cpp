#include <iostream>
#include <cmath> // for calculation

using namespace std;

class VectorType
{
   double* x;
   double* y;
   double* z;

public:
   // Default Constructor
   VectorType()
   {
       x = new double(0);
       y = new double(0);
       z = new double(0);
   }
    // Parameterized Constructor
   VectorType(double a, double b, double c)
   {
       x = new double(a);
       y = new double(b);
       z = new double(c);
   }
   // Copy Constructor
   VectorType(const VectorType& obj)
   {
       x = new double(*(obj.x));
       y = new double(*(obj.y));
       z = new double(*(obj.z));
   }
   // Destructor 
   ~VectorType()
   {
       delete x;
       delete y;
       delete z;
       x = nullptr;
       y = nullptr;
       z = nullptr;
   }
   // Assignment Operator
   VectorType& operator=(const VectorType& obj)
   {
       if (this != &obj) // Avoid self-assignment
       {
           *(this->x) = *(obj.x);
           *(this->y) = *(obj.y);
           *(this->z) = *(obj.z);
       }
       return *this;
   }

   // Subtraction Operator (Fixed)
   VectorType operator-(const VectorType& V)
   {
       VectorType obj;
       *(obj.x) = (*(x)-*(V.x));
       *(obj.y) = (*(y)-*(V.y));
       *(obj.z)= (*(z)-*(V.z));
       return obj;
   }
   // Addition Operator (Fixed)
   VectorType operator+(const VectorType& V)
   {
       VectorType obj;
       *(obj.x) = (*(x)+*(V.x));
       *(obj.y) = (*(y)+*(V.y));
       *(obj.z) = (*(z)+*(V.z));
       return obj;
   }

   // Print Function
   void print() const
   {
       cout << "\nVector is (" << *(x) << "," << *(y) << "," << *(z) << ")\n";
   }

   // Dot Product (Marked as `const`)
   double getDot(const VectorType& V) const
   {
       double dot;
       dot = (*(x) * *(V.x)) + (*(y) * *(V.y)) + (*(z) * *(V.z));
       return dot;
   }

   // Length of Vector (Marked as `const`)
   double getlength() const
   {
       double len;
       len= sqrt(*(x) * *(x)+*(y) * *(y)+*(z) * *(z));
       return len;
   }

   // Angle Between Vectors (Fixed & Marked as `const`)
   double getangle(const VectorType& V) const
   {
       double num = getDot(V);
       double den = this->getlength() * V.getlength();

       if (den == 0.0) 
       { // Prevent division by zero
          cout<< "Error: Division by zero in angle calculation.\n";
           return 0.0;
       }
       double angle = acos(num / den);
       return angle;
   }
   VectorType& operator++()
   {
       (*x)++;
       (*y)++;
       (*z)++;
       return *this;

   }
   VectorType& operator++(int)
   {
       VectorType* temp = new VectorType;
       *temp = *this;
       (*x)++;
       (*y)++;
       (*z)++;
       return *temp;

   }
   VectorType& operator--()
   {
       (*x)--;
       (*y)--;
       (*z)--;
       return *this;

   }
   VectorType& operator--(int)
   {
       VectorType* temp = new VectorType;
       *temp = *this;
       (*x)--;
       (*y)--;
       (*z)--;
       return *temp;

   }
   friend bool operator==(VectorType& obj1, VectorType& obj2);
   friend bool operator!=(VectorType& obj1, VectorType& obj2);
   friend istream& operator>>(istream& input, VectorType& obj);
   friend ostream& operator<<(ostream& output, VectorType& obj);

};
bool operator==(VectorType& obj1, VectorType& obj2)
{
   if ((obj1.getlength()) == (obj2.getlength()))
   {
       return true;
   }
   return false;
}
bool operator!=(VectorType& obj1, VectorType& obj2)
{
   if ((obj1.getlength()) != (obj2.getlength()))
   {
       return true;
   }
   return false;
}
istream& operator>>(istream& input, VectorType& obj)
{
   cout << "Enter values of vector :";
   input >> *(obj.x) >> *(obj.y) >> *(obj.z);
   return input;
}
ostream& operator<<(ostream& output, VectorType& obj)
{
   
   output<< *(obj.x) << *(obj.y) << *(obj.z);
   return output;
}
int main() 
{
   VectorType V1(4.0, 3.0, 2.0);
   VectorType V2(3.0, 2.0, 6.0);
   VectorType V3(2.0, 1.0, 7.0);
   cout << "Dot product is " << V1.getDot(V2);
   cout << "\nLength of vector is " << V1.getlength();
   V2.print();
   VectorType V4 = (V1 + V2) + V3;
  V4.print();
   VectorType V5 = V1 - V2;
   V5.print();
  cout << "\nAngle between V1 and V2: " << V1.getangle(V2) << " Radians  or "  <<(V1.getangle(V2))*180/3.14<<" in Degrees\n";
   VectorType V6;
   V6 = V4;//calling assignment operator overloading 
   V6.print();
   VectorType V7 = ++V1 + V2++ + V3;
   V7.print();
   V1.print();
   V2.print();

  
}
