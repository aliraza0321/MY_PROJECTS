#include<iostream>
#include<fstream>
using namespace std;
int main()
{ char op;
	do{
	cout<<"\n\n\n....You have two choices....\n";
	cout<<"1.Encrypt data\n ";
	cout<<"2.Decrypt data";
	int choice;
	cout<<"\nSelect one choice:";
	cin>>choice;
	while(choice!=1&&choice!=2)
	{
		cout<<"Enter valid choice:";
		cin>>choice;
	}
	if(choice==1)
	{
	
	char data[100];
	ofstream myfile;
	myfile.open("input.txt");
	myfile<<"Haseeb is an intelligent boy";
	myfile.close();
	ifstream infile;
	infile.open("input.txt");
	while(!infile.eof())
	{
		infile.getline(data,100);	
	}
	infile.close();
	cout<<"...Original data...\n";
	for(int i=0;data[i]!='\0';i++)
	{
		cout<<data[i];
	}cout<<endl;
	for(int i=0;data[i]!='\0';i++)
	{
		int j=data[i];
		j++;
		data[i]=j;
	}
	cout<<"..Encrypted text\n";
	for(int i=0;data[i]!='\0';i++)
	{
		cout<<data[i];
	}
	fstream outfile("Encrypt.txt");
	outfile.open("Encrypt.txt");
	for(int i=0;data[i]!='\0';i++)
	{
		outfile<<data[i];
	}
	outfile.close();
    }
    else if(choice==2)
    {   
	    char data[100];
    	ifstream infile("Encrypt.txt");
    	infile.open("Encrypt.txt");
    	while(!infile.eof())
    	{
    	infile.getline(data,100);
    }
    infile.close();
    cout<<"...Encrypted data...\n";
    for(int i=0;data[i]!='\0';i++)
    {
    	cout<<data[i];
	}
    cout<<"....Decrypted data...\n";
    fstream ofile;
    ofile.open("Decrypted data.txt");
    for(int i=0;data[i]!='\0';i++)
    {
    	int j=data[i];
    	j--;
    	data[i]=j;
    	ofile<<data[i];
    	cout<<data[i];
	}
	ofile.close();
	}
	cout<<"\nDo you want to continue Press y or Y for yes:";
	cin>>op;
}while(op=='y'||op=='Y');
}