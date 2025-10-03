//queue is implemented using stack and its functions 
#include<iostream>
using namespace std;
class stack
{
	int top;
	int Maxsize;
	int* arr;
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
		arr = new int[Maxsize];
		size = 0;
	}
	void enqueue(int num)
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
		stack s;
		int num;
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
		stack s;
		int num;
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
int main()
{
	stack s1;
	s1.enqueue(1);
	s1.enqueue(2);
	s1.enqueue(3);
	s1.enqueue(4);
	s1.enqueue(5);
	s1.enqueue(6);
	s1.display();
	s1.dequeue();
	s1.display();
}
