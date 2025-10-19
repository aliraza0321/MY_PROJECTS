#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char text[100];
	char data[100];
	cout<<"Enter whole sentence:";
	cin.getline(text,100);
	ofstream myfile;
	myfile.open("Text.txt",ios::ate|ios::app);
	myfile<<endl<<text;
	myfile.close();
	ifstream read;
	read.open("Text.txt");
    read.get(data,100);
    cout<<"Data is : "<<data;
    read.close();
	
	
	
}