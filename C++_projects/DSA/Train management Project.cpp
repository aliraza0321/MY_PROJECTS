#include<iostream>
using namespace std;

class SLL {
	class Compartment {
	public:
		int id;
		Compartment* next;
		string cargo;
		Compartment(int i = -1, string car = " ") :id(i), cargo(car), next(nullptr)
		{
		}
	};
	Compartment* head;
public:

	SLL() {
		head = nullptr;
	}
	void attachStart()
	{
		int id;
		string c;
		cout << "Enter Compartment ID: ";
		cin >> id;
		cout << "Enter cargo type (passengers ,coal,mail,toys): ";
		cin >> c;
		Compartment* newnode = new Compartment(id, c);
		Compartment* temp = head;
		if (head == nullptr)
			head = newnode;
		else
		{
			newnode->next = temp;
			head = newnode;
		}
		cout << "Compartment " << newnode->id << " (" << newnode->cargo << ") attached at start";

	}
	void attachEnd()
	{
		int id;
		string c;
		cout << "Enter Compartment ID: ";
		cin >> id;
		cout << "Enter cargo type (passengers ,coal,mail,toys): ";
		cin >> c;
		Compartment* newnode = new Compartment(id, c);
		Compartment* temp = head;
		if (head == nullptr)
			head = newnode;
		else {
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}
		cout << "Compartment " << newnode->id << " (" << newnode->cargo << ") attached at End";


	}
	void display()
	{
		cout << "\n\nTrain Composition:\n";
		Compartment* temp = head;
		while (temp != nullptr)
		{
			cout << temp->id << " (" << temp->cargo << ") -> ";
			temp = temp->next;
		}
	}
	void insert()
	{
		int id;
		string c;
		int target;
		cout << "Enter Target compartment id: ";
		cin >> target;
		cout << "Enter new compartment id : ";
		cin >> id;
		cout << "Enter cargo type (passengers,coal,mail,toys ) : ";
		cin >> c;
		Compartment* newnode = new Compartment(id, c);
		Compartment* temp = head;
		for (int i = 1; i < target; i++)
			temp = temp->next;
		if (temp == nullptr)
		{
			cout << "Target compartment " << target << " not found.\n";
			return;
		}
		newnode->next = temp->next;
		temp->next = newnode;
		cout << "Comparment " << id << " attached after " << target << endl;
	}
	void detach()
	{
		int id;
		cout << "Enter id for detach :";
		cin >> id;
		Compartment* temp = head;
		if (head->id == id)
		{
			delete head;
			head = nullptr;
		}
		else {
			while (temp->id != id)
			{
				temp = temp->next;
			}
			Compartment* pre = temp;
			temp->id = temp->next->id;
			temp->cargo = temp->next->cargo;
			temp = temp->next;
			pre->next = temp->next;
		}
		cout << "Compartment " << id << " detached.";
	}
	void search()
	{
		int id;
		cout << "Enter compartment id for searching : ";
		cin >> id;
		if (head->id == id)
		{
			cout << "Compartment " << id << "exists at start of train\n";
			return;
		}
		else
		{
			Compartment* temp = head;
			while (temp->id != id)
			{
				temp = temp->next;
				if (temp == nullptr)
				{
					cout << "Not found this compartment in this train \n";
					return;
				}
			}
			cout << "comparment " << id << " exists in train\n";
		}
	}
	void count()
	{
		int count = 0;
		Compartment* temp = head;
		display();
		while (temp != nullptr)
		{
			temp = temp->next;
			count++;
		}
		cout << "\nTotal Compartments : " << count << endl;

	}
	void swap()
	{
		int first, second;
		cout << "Enter first compartment : ";
		cin >> first;
		cout << "Enter second compartment:";
		cin >> second;
		Compartment* node1, * node2;
		Compartment* temp = head;
		if (head->id == first)
			node1 = head;
		else
		{
			while (temp->id != first)
			{
				temp = temp->next;
			}
			node1 = temp;
		}
		if (head->id == second)
			node2 = head;
		else
		{
			temp = head->next;
			while (temp->id != first)
			{
				temp = temp->next;
			}
			node2 = temp;
		}
		Compartment* local = new Compartment;
		local->id = node1->id;
		node1->id = node2->id;
		node2->id = local->id;

		local->cargo = node1->cargo;
		node1->cargo = node2->id;
		node2->cargo = local->cargo;
		cout << "compartment " << first << " and " << second << " swapped.\n";


	}
	void middle()
	{
		Compartment* pre, * curr, * temp;
		curr = head;
		temp = head;
		pre = head;
		while (temp->next->next != nullptr)
		{
			pre = temp->next;
			curr = temp->next->next;
			temp = temp->next;
		}
		cout << pre->id << " is at middle \n";
	}
	void reverse()
	{
		Compartment* before, * cur, * after;
		before = nullptr;
		cur = head;
		after = head;
		while (after != nullptr)
		{
			after = cur->next;
			cur->next = before;
			before = cur;
			cur = after;
		}
		head = before;
		cout << "\nReverse is done\n";
	}
	~SLL()
	{
		Compartment* temp1, * temp2;
		temp1 = head;
		while (temp1->next != nullptr)
		{
			temp2 = temp1->next;
			delete temp1;
			temp1 = temp2;
		}
	}
};
int menu()
{
	int choice;
	cout << "\n\n===Thomas & Friends: Train Compartment Manager ===\n";
	cout << "1. Attach Compartment at Start (VIP)\n";
	cout << "2. Attach Comparment at End (Normal)\n";
	cout << "3. Attach Compartment after specific compartment\n";
	cout << "4. Detach comparment\n";
	cout << "5. Search comparment\n";
	cout << "6. Display comparments\n";
	cout << "7. count comparment\n";
	cout << "8. Swap two comparments\n";
	cout << "9.Reverse compartments\n";
	cout << "10.Find Middle of the Train\n";
	cout << "0. Exit\n";
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}
int main()
{
	SLL* newcom = new SLL;
	//newcom->attachStart();
	int choice;
	do {
		choice = menu();
		if (choice == 1)
		{
			newcom->attachStart();
		}
		else if (choice == 2)
		{
			newcom->attachEnd();
		}
		else if (choice == 3)
		{
			newcom->insert();
		}
		else if (choice == 6)
		{
			newcom->display();
		}
		else if (choice == 4)
		{
			newcom->detach();
		}
		else if (choice == 5)
		{
			newcom->search();
		}
		else if (choice == 7)
		{
			newcom->count();
		}
		else if (choice == 8)
		{
			newcom->swap();
		}
		else if (choice == 9)
		{
			newcom->reverse();
		}
		else if (choice == 10)
		{
			newcom->middle();
		}
		else if (choice == 0)
		{
			return 0;
		}
		else
			cout << "You enter wrong choice try again!";
	} while (choice != 0);


}