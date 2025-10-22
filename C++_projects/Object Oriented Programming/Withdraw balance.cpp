#include<iostream>
#include<string>
using namespace std;
// Function to perform withdrawal
void withdraw(double balance, double amount) 
{
	if (amount > balance)
	{
		throw"Insuffient balance ";
	}
	else if(amount < 0)
	{
		throw "Negative amount is entered";

	}
	else
	{
		cout << "Withdrawal successful.New Balance : " << (balance - amount) << endl;

	}
	// TODO: Throw exception if amount > balance
	// TODO: Throw exception if amount is negative
	// Perform the withdrawal
}
int main() 
{
	double balance, amount;
	cout << "Enter current balance : ";
	cin>>balance;
	cout << "Enter amount to withdraw :";
	cin>>amount;
	try {
		withdraw(balance, amount);
	}
	// TODO: Catch int exception for negative amount
	// TODO: Catch string exception for insufficient funds
	// TODO: Display meaningful error messages
	catch (const char* p)
	{
		cout << p << endl;
	}
}