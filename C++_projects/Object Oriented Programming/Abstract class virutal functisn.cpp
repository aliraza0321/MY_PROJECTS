#include<iostream>
using namespace std;
class Chat 
{
public:
	virtual void displayMessages() = 0;
};
class TextMsg:public Chat
{
	char *ptr;
public:
	TextMsg()
	{
		ptr = nullptr;
	}
	TextMsg(const char*t)
	{
		ptr = new char(sizeof(t));
		strcpy(ptr, t);
	}
	void sendMessage(const char*t)
	{
		ptr = new char(sizeof(t));
		strcpy(ptr, t);

	}
	void displayMessages()
	{
		cout << "Your text message is : ";
		for (int i = 0;ptr[i] != '\0';i++)
		{
			cout << ptr[i];
		}
		cout << endl;
	}
	void deleteLastMsg()
	{
		delete[]ptr;
		ptr = nullptr;
	}
	~TextMsg()
	{
		delete[]ptr;
		ptr = nullptr;
	}
};
class VideoMsg:public Chat
{
	char* ptr1;
	string format;
	float size;
public:
	VideoMsg(char* p1 = 0, string f=" ", float s=0)
	{
		ptr1 = new char(sizeof(p1));
		strcpy(ptr1, p1);
		format = f;
		size = s;
	}
	void sendMessage(const char* p1, string f = " ", float s = 0)
	{
		ptr1 = new char(sizeof(p1));
		strcpy(ptr1, p1);
		format = f;
		size = s;
	}
	void displayMessages()
	{
		cout << "Your file name   is : ";
		for (int i = 0;ptr1[i] != '\0';i++)
		{
			cout << ptr1[i];
		}
		cout << endl;
		cout << "Your format is : " << format << endl;
		cout << "Size of video is : " << size << endl;
	}

};










int main()
{
	TextMsg* text = new TextMsg;
	VideoMsg* video = new VideoMsg;
	Chat* chats[2];
	chats[0] = text;
	chats[1] = video;
	for (int i = 0; i < 10; i++)
		text->sendMessage("Hello, how are you?");
	text->deleteLastMsg();
	text->sendMessage("Don't forget the deadline!");
	video->sendMessage("demo.mp4", "mp4", 10.4); //filename, format, size
	video->sendMessage("meeting.avi", "avi", 209.7);
	cout << "--- Displaying Messages ---\n";
	for (int i = 0; i < 2; ++i) {
		chats[i]->displayMessages(); //it must print all the stored messages.
		cout << endl;
	}
	delete text;
	delete video;
}