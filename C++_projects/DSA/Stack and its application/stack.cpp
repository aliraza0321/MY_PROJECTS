#include<iostream>
using namespace std;
template<class T>
class stack
{
	int Maxsize;
	int top;
	int size;
	T* array;
public:
	stack(int s = 0)
	{
		if (s <= 0)
		{
			Maxsize = 20;
		}
		else
		{
			Maxsize = s;
		}
		array = new T[Maxsize];
		top = -1;
		size = 0;
	}
	bool isfull()
	{
		return size == Maxsize;
	}
	bool isempty()
	{
		return size == 0;
	}
	void push(T data)
	{
		if (!isfull())
		{
			top++;
			array[top] = data;
			size++;
		}
	}
	void pop()
	{
		if (!isempty())
		{
			top--;
			size--;
		}
	}
	T peek()
	{
		return array[top];
	}
	void display()
	{
		cout << "Original stack is : ";
		for (int i = top; i > 0; i--)
		{
			cout << array[i] << " => ";
		}
		cout << array[0];
		cout << endl;
	}
	void displayRev()
	{
		cout << "Reverse stack is : ";
		for (int i = 0; i < top; i++)
		{
			cout << array[i] << " => ";
		}
		cout << array[top];
		cout << endl;
	}
	void balancebrak()
	{
		string str; 
		cout << "Enter parenthesis: ";
	    cin >> str;
		for (int i = 0; i<=str.length(); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				push(str[i]);
			}
			else if( (peek() == '(' && str[i] == ')') || ((peek() == '[' && str[i] == ']')) || (peek() == '{' && str[i] == '}'))
			{
				pop();
			}
			
		}
		if (isempty())
		{
			cout << "\nBalanced\n";
		}
		else
		{
			cout << "Unbalanced";
		}
	}
	void palindrome()
	{
		string str;
		cout << "Enter string: ";
		cin >> str;
		int last = str.length()-1;
		int start = 0;
		while (start<=last)
		{
			if (str[start] != str[last])
			{
				cout << "This is not palindrom\n";
				return;
			}
			start++;
			last--;
			
		}
		cout << "\nThis is  palindrome\n";
	}
	
};
void celebrity()
{
	stack<int>s;
	int count = 0;
	int matrix[2][2] = { {1,0},
						{0,1}};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (matrix[i][j] == 1) {
				s.push(j);
				count++;
			}
			else if(matrix[j][i]!=1){
				if (s.peek() == j)
				{
					cout << "celebrity is " << j<<" person\n";
				}
			}
		}
	}
}
	void  stockProblem()
	{
		stack<int> s;

		int day;
		cout << "enter your days : ";
		cin >> day;
		int mat[] = { 0 };
		cout << "enter prices : ";
		for (int i = 0; i < day; i++)
		{
			cin >> mat[i];
		}
		int span = 1;
		int temp = mat[0];
		s.push(span);
		for (int i = 1; i < day; i++)
		{
			if (temp < mat[i])
			{
				
				span++;
				s.push(span);

			}
			else if (temp > mat[i])
			{
				span = 1;
				s.push(span);
			}
			temp = mat[i];

		}
		cout << "Stock Spans: ";
		s.displayRev();
	}
int menu()
{
	int choice;
	cout << "\n\n===== STACK MENU====\n";
	cout << "1. Push\n";
	cout << "2. Pop\n";
	cout << "3.Peek\n";
	cout << "4.Display stack\n";
	cout << "5.Display Reverse\n";
	cout << "6.Check balance parenthesis\n";
	cout << "7.Stock span problem\n";
	cout << "8.celebrity problem\n";
	cout << "9.Check Palindrome\n";
	cout << "0.Exit\n";
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}
int main()
{
	stack<int> s1;
	stack<char>s2(10);
	int choice;
	do {
		choice = menu();
		if (choice == 1)
		{
			int data;
			cout << "Enter your data :";
			cin >> data;
			s1.push(data);
		}
		else if (choice == 2)
		{
			s1.pop();
		}
		else if (choice == 3)
		{
			int num = s1.peek();
			cout << "\nYour top element is : " << num<<endl;
			//s1.peek();
		}
		else if (choice == 4)
		{
			s1.display();
		}
		else if (choice == 5)
		{
			s1.displayRev();
		}
		else if (choice == 6)
		{
			s1.balancebrak();
		}
		else if (choice == 9)
		{
			s1.palindrome();
		}
		else if (choice == 8)
		{
			celebrity();
		}
		else if (choice == 7)
		{
			stockProblem();
		}



	} while (choice != 0);
}
