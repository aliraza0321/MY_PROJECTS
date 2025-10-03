//queue is implemented using stack and its functions 
#include<iostream>
using namespace std;
template<class T>
class stack
{
	int top;
	int Maxsize;
	T* arr;
	int size;
public:
	stack(int s = 0)
	{
		if (s <= 0)
		{
			Maxsize = 10;
		}
		else
			Maxsize = s;
		top = -1;
		arr = new T[Maxsize];
		size = 0;
	}
	void enqueue(T num)
	{
		if (!isfull())
		{
			top++;
			arr[top] = num;
			size++;
		}
	}
	void pop() {
		if (!isempty())
		{
			top--;
			size--;
		}
	}
	bool isempty()
	{
		return size == 0;
	}
	bool isfull()
	{
		return Maxsize == size;
	}
	 int  peek()
	{
		return arr[top];
	}
	void display()
	{
		stack<T> s;
		
		T num;
		cout << "Data is : ";
		while (!isempty())
		{
			num = peek();
			s.enqueue(num);
			pop();
			//cout << num << " ";
		}
		while (!(s.isempty()))
		{
			num = s.peek();
			enqueue(num);
			s.pop();
			cout << num<<" => ";
		}
	}
	void dequeue()
	{
		stack<T> s;
		T num;
		while (!(isempty()))
		{
			num = peek();
			s.enqueue(num);
			pop();
			
		}
		cout << "\nelement is removed: " << s.peek()<<endl;
		s.pop();
		while (!(s.isempty()))
		{
			num = s.peek();
			enqueue(num);
			s.pop();
		}

	}
};

string removedig(string num, int k)
{
	stack<char> st; 

	// Traverse number
	for (int i = 0; i < num.size(); i++) 
	{
		char digit = num[i];
		while (!st.isempty() && k > 0 && st.peek() > digit) 
		{
			st.pop();
			k--;
		}
		st.enqueue(digit);
	}
	while (k > 0 && !st.isempty())
	{
		st.pop();
		k--;
	}

	// use another stack for reverse string  
	stack<char> rev;
	while (!st.isempty())
	{
		rev.enqueue(st.peek());
		st.pop();
	}

	// Remove leading zeros
	while (!rev.isempty() && rev.peek() == '0') 
	{
		rev.pop();
	}
	if (rev.isempty()) 
		return "0";

	// Build result from stack
	string result = "";
	while (!rev.isempty())
	{
		result.push_back(rev.peek());
		rev.pop();
	}
	return result;
}


int main()
{//Task 2
	stack<int> s1;
	s1.enqueue(1);
	s1.enqueue(2);
	s1.enqueue(3);
	s1.enqueue(4);
	s1.enqueue(5);
	s1.enqueue(6);
	s1.display();
	s1.dequeue();
	s1.display();

	//Task 1
	cout <<endl<<removedig("1432219", 3) << endl;
	cout << removedig("10200", 1) << endl;   
	cout << removedig("10", 2) << endl;
}
