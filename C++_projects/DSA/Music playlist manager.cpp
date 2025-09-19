#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
	string song;
	Node* next;
	Node* pre;
	Node(string s) :song(s), next(nullptr), pre(nullptr) {}
};
class Playlist
{
	Node* head;
	Node* curSong;

public:
	Playlist()
	{
		head = nullptr;
		curSong = head;
	}
	Node* createNode()
	{
		string name;
		cout << "Enter you song name: ";
		cin >> name;
		//getline(cin, name); this function not run properly in this code but in other code i dry run and run by taking line input then it runs properly but here not run therefore i am using cin
		//cout << "You entered " << name;
		Node* newsong = new Node(name);
		return newsong;
	}
	void addHead()
	{
		Node* newsong = createNode();
		if (head == nullptr)
		{
			head = curSong = newsong;
		}
		else
		{

			newsong->next = head;
			head->pre = newsong;
			head = newsong;
			curSong = head;
		}
		cout << endl;
		cout << newsong->song << " added at beginning\n";
	}
	void addEnd()
	{
		Node* newsong = createNode();
		if (head == nullptr)
		{
			head = curSong = newsong;
		}
		else
		{
			Node* temp = head;

			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			newsong->pre = temp;
			temp->next = newsong;

		}
		cout << newsong->song << " added at end\n";
	}
	void addPos(int index)
	{
		Node* newsong = createNode();
		if (index < 0)
		{
			cout << "You enter wrong index\n";
		}
		else
		{
			Node* temp = head;
			for (int i = 1; i < index - 1; i++)
			{
				temp = temp->next;
			}
			if (temp == nullptr)
			{
				cout << "You enter wrong index\n";

			}
			else
			{
				newsong->next = temp->next;
				newsong->pre = temp;
				temp->next->pre = newsong;
				temp->next = newsong;

				cout << newsong->song << "  inserted at " << index << " position\n";
			}
		}
	}
	void removeHead()
	{
		Node* temp = head;
		if (temp == nullptr)
		{
			cout << "Already empty list\n";
		}
		else
		{
			head = curSong = temp->next;
			head->pre = nullptr;
			temp->next = nullptr;
			cout << temp->song << " is deleted from head \n";
			delete temp;
		}
	}
	void removeEnd()
	{
		if (head == nullptr)
		{
			cout << "already empty list\n";
		}
		else
		{
			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			Node* cur = temp->pre;
			cur->next = nullptr;
			temp->pre = nullptr;
			cout << temp->song << " is deleted at end \n";
			delete temp;
		}
	}
	void removePos(int index)
	{
		Node* newsong = createNode();
		if (index < 0)
		{
			cout << "You enter wrong index\n";
		}
		else
		{
			Node* temp = head;
			for (int i = 1; i < index - 1; i++)
			{
				temp = temp->next;
			}
			if (temp == nullptr)
			{
				cout << "You enter wrong index\n";

			}
			else
			{
				Node* cur = temp->next;
				temp->next = cur->next;
				cur->next->pre = temp;
				cur->next = nullptr;
				cur->pre = nullptr;
				cout << cur->song << " is deleted from " << index << " index\n";
				delete cur;
			}
		}
	}
	void search(string s)
	{
		if (head == nullptr)
		{
			cout << "Sorry list is empty now \n";
		}
		else
		{
			int pos = 1;
			Node* temp = head;
			while (temp->song != s)
			{
				temp = temp->next;
				pos++;
			}
			if (temp != nullptr)
			{
				cout << s << " this song found at positon " << pos << endl;
			}
		}
	}
	void displayFor()
	{
		cout << "\n\nPlaylist Forward: ";
		Node* temp = head;
		while (temp->next != nullptr)
		{
			cout << temp->song << " -> ";
			temp = temp->next;
		}
		cout << temp->song << endl << endl;
	}
	void displayBac()
	{
		cout << "\n Playlist Backward: ";
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		while (temp->pre != nullptr)
		{
			cout << temp->song << " -> ";
			temp = temp->pre;
		}
		cout << temp->song;
	}
	void playnext()
	{

		if (curSong->next == nullptr)
		{
			cout << "We dont have next song\n";
		}
		else
		{
			curSong = curSong->next;
			cout << curSong->song << " is playing now \n";

		}
	}
	void playPre()//moves previous until reach first song
	{

		if (curSong->pre == nullptr)
		{
			cout << "You dont have any song in previous\n ";


		}
		else
		{
			curSong = curSong->pre;
			cout << curSong->song << " is playing \n";
		}
	}
	void removeDup()
	{
		if (head == nullptr)
		{
			cout << "empty list now\n";

		}
		else
		{
			displayFor();
			Node* temp1, * temp2;
			temp1 = head;
			//temp2 = head->next;
			while (temp1 != nullptr)
			{
				temp2 = temp1->next;
				while (temp2!= nullptr)
				{
					if (temp1->song == temp2->song)
					{
						Node* temp = temp2->next;

						if (temp2->pre) 
							temp2->pre->next = temp2->next;
						if (temp2->next)
							temp2->next->pre = temp2->pre;

						
						delete temp2;
						temp2 = temp;
					}
					else
					{

						temp2 = temp2->next;
						
					}
				}
				temp1 = temp1->next;
			}
		}

		cout << "Removed duplicates songs";
		displayFor();
	}
	void sortPlaylist() {
		if (!head || !head->next)
		{
			cout << "Playlist is empty or has only one song, nothing to sort.\n";
			return;
		}

		bool swapped;
		Node* temp1;
		Node* lptr = nullptr;

		do 
		{
			swapped = false;
			temp1 = head;

			while (temp1->next != lptr)
			{
				if (temp1->song > temp1->next->song) 
				{
					// Swap songs (not nodes)
					string temp = temp1->song;
					temp1->song = temp1->next->song;
					temp1->next->song = temp;
					swapped = true;
				}
				temp1 = temp1->next;
			}
			lptr = temp1;
		} while (swapped);

		cout << "Playlist sorted successfully!\n";
		displayFor();
	}
	void mergePlaylist(Playlist& other) {
		if (other.head == nullptr) {
			cout << "Other playlist is empty, nothing to merge.\n";
			return;
		}

		if (head == nullptr) {
			head = other.head;
			curSong = head;
			other.head = nullptr;
			sortPlaylist();  // sort after merging
			return;
		}

		// Attach other playlist at the end
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = other.head;
		other.head->pre = temp;

		other.head = nullptr;

		// Sort merged list
		sortPlaylist();

		cout << "Playlists merged & sorted successfully!\n";
	}
	~Playlist()
	{
		Node* temp1, * temp2;
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
	cout << "\n\n==== = Music Playlist Manager =====" << endl;
	cout << "1.Add song at beginning\n";
	cout << "2.Add song at End\n";
	cout << "3.Add song at position\n";
	cout << "4.Remove song from beginning\n";
	cout << "5.Remove song from end\n";
	cout << "6.Remove song from position\n";
	cout << "7.search song \n";
	cout << "8.Display playlist forward\n";
	cout << "9.display playlist backward\n";
	cout << "10.Play next song \n";
	cout << "11.play previous song \n";
	cout << "12.Remove duplicates song\n";
	cout << "13.exit\n";
	cout << "14. Sort playlist\n";
	cout << "15.Merge two lists first add two lists then call it\n";
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;

}
int main()
{
	Playlist p1;
	int choice;
	cout << "\nYour first song list right now\n\n";
	cout << "Kindly perform operations on your playlist that is empty now\n\n";
	do {
		choice = menu();
		if (choice == 1)
		{
			p1.addHead();
		}
		else if (choice == 2)
		{
			p1.addEnd();
		}
		else if (choice == 3)
		{
			int choice;
			cout << "\nAt which position you want to add song: ";
			cin >> choice;
			p1.addPos(choice);
		}
		else if (choice == 4)
		{
			p1.removeHead();
		}
		else if (choice == 5)
		{
			p1.removeEnd();
		}
		else if (choice == 6)
		{
			int choice;
			cout << "\nAt which position you want to add song: ";
			cin >> choice;
			p1.removePos(choice);
		}
		else if (choice == 7)
		{
			string name;
			cout << "Enter song name you want to search \n";
			cin >> name;
			p1.search(name);
		}
		else if (choice == 8)
		{
			p1.displayFor();
		}
		else if (choice == 9)
		{
			p1.displayBac();
		}
		else if (choice == 10)
		{
			p1.playnext();
		}
		else if (choice == 11)
		{
			p1.playPre();
		}
		else if (choice == 12)
		{
			p1.removeDup();
		}
		else if (choice == 14)
		{
			p1.sortPlaylist();
		}
	} while (choice != 13);

	cout << "\n\nYour second song list right now \n\n";
	cout << "Kindly perform operations on your playlist that is empty now   ,If you are not interested in second list exit now\n\n";
	Playlist p2;
	do {
		choice = menu();
		if (choice == 1)
		{
			p2.addHead();
		}
		else if (choice == 2)
		{
			p2.addEnd();
		}
		else if (choice == 3)
		{
			int choice;
			cout << "\nAt which position you want to add song: ";
			cin >> choice;
			p2.addPos(choice);
		}
		else if (choice == 4)
		{
			p2.removeHead();
		}
		else if (choice == 5)
		{
			p2.removeEnd();
		}
		else if (choice == 6)
		{
			int choice;
			cout << "\nAt which position you want to add song: ";
			cin >> choice;
			p2.removePos(choice);
		}
		else if (choice == 7)
		{
			string name;
			cout << "Enter song name you want to search \n";
			cin >> name;
			p2.search(name);
		}
		else if (choice == 8)
		{
			p2.displayFor();
		}
		else if (choice == 9)
		{
			p2.displayBac();
		}
		else if (choice == 10)
		{
			p2.playnext();
		}
		else if (choice == 11)
		{
			p2.playPre();
		}
		else if (choice == 12)
		{
			p2.removeDup();
		}
		else if (choice == 14)
		{
			p2.sortPlaylist();
		}
		else if (choice == 15)
		{
			p2.mergePlaylist(p1);
		}
	} while (choice != 13);

}