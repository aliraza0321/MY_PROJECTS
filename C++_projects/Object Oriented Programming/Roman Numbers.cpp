#include <iostream>
using namespace std;

class RomanNumber
{
   int value;
   string roman;

public:
   // Converts a Roman numeral string to an integer
   int getInt(string roman)
   {
       int result = 0, prevValue = 0;
       for (int i = roman.length() - 1; i >= 0; i--)
       {
           int currValue;
           if (roman[i] == 'I')
               currValue = 1;
           else if (roman[i] == 'V')
               currValue = 5;
           else if (roman[i] == 'X')
               currValue = 10;
           else if (roman[i] == 'L')
               currValue = 50;
           else if (roman[i] == 'C')
               currValue = 100;
           else if (roman[i] == 'D')
               currValue = 500;
           else if (roman[i] == 'M')
               currValue = 1000;
           else
               cout<<"Invalid Roman numeral character.";

           if (currValue < prevValue)
               result -= currValue;
           else
               result += currValue;
           prevValue = currValue;
       }
       return result;
   }

   // Converts an integer to a Roman numeral string
   string getRoman(int num)
   {
       int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
       const char* numerals[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
       string result = "";
       for (int i = 0; i < 13; i++)
       {
           while (num >= values[i])
           {
               result += numerals[i];
               num -= values[i];
           }
       }
       return result;
   }
   // Default constructor
   RomanNumber() : value(0), roman("") 
   {}
   // Constructor that initializes from a Roman numeral string
   RomanNumber(string r)
   {
       value = getInt(r);
       roman = r;
   }
   // Constructor that initializes from an integer value
   RomanNumber(int v)
   {
       value = v;
       roman = getRoman(v);
   }
   RomanNumber(const RomanNumber& obj)
   {
       this->value = obj.value;
       this->roman = getRoman(this->value);
   }
   // Overloaded addition operator
   RomanNumber operator+(const RomanNumber& obj)
   {
       RomanNumber res;
       res.value = this ->value+obj.value;
       res.roman = getRoman(res.value);
       return res;
   }

   // Overloaded subtraction operator
   RomanNumber operator-(const RomanNumber& obj)
   {
       if (value < obj.value)
       {
           cout << "First number should be greater from second \n";
           return *this;
       }
       RomanNumber res;
       res.value = this->value - obj.value;
       res.roman = getRoman(res.value);
       return res;
   }

   // Overloaded multiplication operator
   RomanNumber operator*(const RomanNumber& obj)
   {
       RomanNumber res;
       res.value = this->value * obj.value;
       res.roman = getRoman(res.value);
       return res;
   }

   // Overloaded division operator
   RomanNumber operator/(const RomanNumber& obj)
   {
       if (obj.value == 0)
       {

           cout << "Cannot divide by zero.";
           return *this;
       }
       if (value<obj.value)
       {
           cout << "Numenator must be greater than from denomenator\n";
           return *this;
       }
       RomanNumber res;
       res.value = this->value / obj.value;
       res.roman = getRoman(res.value);
       return res;
   }

   // Overloaded equality operator
   bool operator==(const RomanNumber& obj)
   {
       if (value == obj.value)
           return true;
       return false;
   }

   // Overloaded inequality operator
   bool operator!=(const RomanNumber& obj)
   { 
       if (value != obj.value)
           return true;
       return false;
   }

   // Overloaded greater than operator
   bool operator>(const RomanNumber& obj)
   { 
       if (value >obj.value)
           return true;
   return false;
   }

   // Overloaded less than operator
   bool operator<(const RomanNumber& obj) 
   {
       if (value <obj.value)
           return true;
       return false;
   }

   // Overloaded prefix increment operator
   RomanNumber& operator++()
   {
       value++;
       roman = getRoman(value);
       return *this;
   }

   // Overloaded postfix increment operator
   RomanNumber operator++(int)
   {
       RomanNumber temp = *this;
       ++(*this);
       return temp;
   }

   // Overloaded prefix decrement operator
   RomanNumber& operator--()
   {
       if (value - 1 <= 0)
       {
           cout << "Roman number has only positive numbers ";
           return *this;
       }
       value--;
       roman = getRoman(value);
       return *this;
   }

   // Overloaded postfix decrement operator
   RomanNumber operator--(int)
   {
       RomanNumber temp = *this;
       --(*this);
       return temp;
   }

   // Overloaded stream insertion operator
   friend ostream& operator<<(ostream& output, const RomanNumber& obj);
};
ostream& operator<<(ostream& output, const RomanNumber& obj)
{
   output << obj.roman;
   return output;
}

int main()
{
   RomanNumber r1("I");
   RomanNumber r2("III");
   RomanNumber r3 = r1 + r2;
   cout << "Addition: " << r3<< endl;
   r3 = r1 - r2;
   cout << "Subtraction: " << r3 << endl;
   r3 = r1 * r2;
   cout << "Multiplication: " << r3 << endl;
   r3 = r1 /r2;
   cout << "Division: " << r3 << endl;
   RomanNumber r4("I");
   cout << "Before increment: " << r4 << endl;
   cout << "After increment: " << ++r4 << endl;

}
