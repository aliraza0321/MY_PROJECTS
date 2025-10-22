#include<iostream>
using namespace std;
class String
{
	int size;
	char* str;
public:
	String()
	{
		size = 0;
		str = nullptr;
	}
	String(const char* arr)
	{
		size = 0;
		for (int i = 0;arr[i] != '\0';i++)
			size++;
		str = new char[size + 1];
		for (int i = 0;i < size;i++)
		{
			str[i] = arr[i];
		}
		str[size] = '\0';
	}
	String(const String& obj)
	{
		size = obj.size;
		str = new char[size + 1];
		for (int i = 0;i < size;i++)
		{
			str[i] = obj.str[i];
		}
		str[size] = '\0';
	}
	int getlength()
	{
		size = 0;
		for (int i = 0;str[i] != '\0';i++)
			size++;
		return size;
	}
	
	void toUpper()
	{
		for (int i = 0;i < size;i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] -32;
			}
		}
	}
	void toLower()
	{
		for (int i = 0;i < size;i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i] + 32;
			}
		}
	}
	char getDigit(int& index)
	{
		if (index < 0 || index >= size)
		{
			cout << "\nIndex does not exist.\n";
			return '\0';
		}
		return str[index];
	}
	char*& extract(const int& s, const int& l)   //s for starting index and l for last index
	{
		int count = 0;
		if (s < 0 || l >= size)
		{
			cout << "\nInvalid index ! cannot extract\n";
		}
		for (int i = s;i < l;i++)
		{
			count++;
		}
		char*temp = new char[count + 1];     //create a array on heap for storing extracted array
		int n = 0;
		for (int i = s;i < l;i++)
		{
			temp[n] = str[i];
			n++;
		}
		temp[count] = '\0';
		return temp;    //return pointer by reference that is created on heap 
	}
	int getIndex(const char* arr)
	{
		if (arr == nullptr || str == nullptr)
			return -1; // Handle null cases

		int subLength = 0;
		while (arr[subLength] != '\0') // get length of array
			subLength++;

		if (subLength == 0 || subLength > size)
			return -1; // check invalid length of array 

		for (int i = 0; i <=( size - subLength); i++)   //loop will run size-sublength times 
		{
			int j = 0;
			while (j < subLength && str[i + j] == arr[j]) // Compare substring
				j++;

			if (j == subLength) // If full substring matched
				return i;

		}

		return -1;// Return -1 if not found
	}
	bool compare(const char*& arr)
	{
		int temp = 0;
		for (int i = 0;arr[i] != '\0';i++)   //get length of new array 
		{
			temp++;
		}
		if (temp != size)
		{
			cout << "Size does not match of both \n";
			return false;
		}
		for (int i = 0;i < size;i++)
		{
			if (arr[i] != str[i])   //will match each digit if not equal then return false other wise true
			{
				cout << "Did not match elements \n";
				return false;
			}
		}
		return true;

	}
	char*& concat(String &obj)
	{
		int temp = 0;
		for (int i = 0;obj.str[i] != '\0';i++)
		{
			temp++;
		}
		char* res = new char[temp + size+2];  //for combining two array includeing space  between them and storing null character at last of array
		int x = 0;
		for (int i = 0;i < size;i++)    //first store first array then store space
		{
			res[x] = this->str[i];
			x++;
		}
		res[x] = ' ';
		x++;
		for (int i = 0;i <temp;i++)  //storing second array 
		{
			res[x] = obj.str[i];
			x++;
		}
		res[temp + size+1] = '\0';
		return res;  //return res that is pointer created on heap it will return by reference
	}
	String operator+(const String& obj)
	{
		String res;
		res.size = (this->size) + obj.size;
		res.str = new char[res.size+1];
		int x = 0;
		for (int i = 0;i < size;i++)
		{
			res.str[x] = str[i];
			x++;
		}
		res.str[x++] = ' ';
		for (int i = 0;i < obj.size;i++)
		{
			res.str[x] = obj.str[i];
			x++;
		}
		res.str[obj.size + size+1] = '\0';
		return res;
	}
	String& operator=(const String& arr)
	{
		if (this != &arr)
		{
			delete[] str;
			size = arr.size;
			str = new char[size + 1];
			for (int i = 0; i < size; i++)
				str[i] = arr.str[i];
			str[size] = '\0';
		}
		return *this;
	}
	bool operator==(const String& obj)
	{
		int temp = 0;
		for (int i = 0;obj.str[i] != '\0';i++)
		{
			temp++;
		}
		if (temp != size)
		{
			cout << "Size does not match of both \n";
			return false;
		}
		for (int i = 0;i < size;i++)
		{
			if (obj.str[i] != str[i])
			{
				cout << "Did not match elements \n";
				return false;
			}
		}
		return true;
	}
	bool operator!=(const String& obj)
	{
		int temp = 0;
		for (int i = 0;obj.str[i] != '\0';i++)
		{
			temp++;
		}
		if (temp != size)
		{
			cout << "Yes .Size does not match of both \n";
			return true;
		}
		for (int i = 0;i < size;i++)
		{
			if (obj.str[i] != str[i])
			{
				cout << ".Yes.Did not match elements \n";
				return true;
			}
		}
		return false;
	}
	bool operator<(const String& obj)
	{
		if (size < obj.size)
		{
			return true;
		}
		return false;
	}
	bool operator>(const String& obj)
	{
		if (size > obj.size)
		{
			return true;
		}
		return false;
	}
	char& operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			cout << "Invalid index"<<endl;
		}
		return str[index];
	}
	void print() const
	{
		for (int i = 0;str[i] != '\0';i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	friend istream& operator>>(istream& input, String& obj);
	friend ostream& operator<<(ostream& print, String& obj);

};
istream& operator>>(istream& input, String& obj)
{
	string temp;
	cout << "Enter string: ";
	input >> temp;
	int count= 0;
	for (int i = 0;temp[i] != '\0';i++)
	{
		count ++ ;
	}
	obj.str = new char[count + 1];
 	for (int i = 0;temp[i] != '\0';i++)
	{
		obj.str[i] = temp[i];
	}
	obj.str[count] = '\0';
	return input;
}
ostream& operator<<(ostream& print, String& obj)
{
	for (int i = 0;obj.str[i] != '\0';i++)
	{
		print << obj.str[i];
	}
	return print;
}
int main()
	{
		//char data1[] = "Hello
		String s1("Hello");
		String s2("World");
		String s3=s2+s1;
		s3 = s1.concat(s2);
		cout << "Concatenation: " << s3 << endl;
		cout << "Length: " << s3.getlength() << endl;
		s3.toUpper();
		cout << "Uppercase: " <<s3<< endl;
		char* sub = s3.extract(3, 8);
		cout << "Substring (3, 8): " << sub << endl;
		delete[] sub;
		sub = nullptr;
		s3.print();
		cout << "Index of 'WORLD': " << s3.getIndex("WORLD") << endl;
		cout << s3;
		
	}
