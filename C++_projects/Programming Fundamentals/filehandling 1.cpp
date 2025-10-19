#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char data[100];
	cout<<"Enter whole information for saving in file: ";
	cin.getline(data,100);
	ofstream myfile;
	myfile.open("Mydata.txt",ios::app);
	myfile<<data<<endl;
	myfile.close();
	char text[50];
	ifstream infile;
	infile.open("Mydata.txt");
	while(!infile.eof())
	{
		infile>>text;
		cout<<text;
	}
	infile.close();
}