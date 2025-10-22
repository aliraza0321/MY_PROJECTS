#include <iostream>
using namespace std;
class Account
{
protected:
	int accountNumber;
	float balance;
public:
	Account(int accNo, float bal) : accountNumber(accNo),
		balance(bal) 
	{

	}
	virtual void debit(float amount) = 0;
	virtual void credit(float amount) = 0;
	virtual void print()  = 0;
};
class CurrentAccount : public Account 
{
protected:
	float minimumBalance;
	float serviceCharge;
public:
	CurrentAccount(int accNo, float bal, float minBal, float
		charge)
		: Account(accNo, bal), minimumBalance(minBal),
		serviceCharge(charge) {
	}
	void debit(float a)override
	{
		cout << "Debit iis " << a << endl;
	}
	void credit(float a)override
	{
		cout << "Credit is " << a << endl;
	}
	void print()override
	{
		cout << "display data of this class";
	}
	// TODO: Override debit, credit, and print
};
class SavingAccount : public Account
{
protected:
	float interestRate;
public:
	SavingAccount(int accNo=0, float bal=0, float rate=0)
		: Account(accNo, bal), interestRate(rate)
	{
	}
	// TODO: Override debit, credit, and print
	void debit(float a)override
	{
		cout << "Debit iis " << a << endl;
	}
	void credit(float a)override
	{
		cout << "Credit is " << a << endl;
	}
	void print()override
	{
		cout << "display data of this class"
	}
};
int main()
{

	// TODO: Use base class pointer to test polymorphic behavior
	Account *a1=new SavingAccount;
	a1->credit(50000);
	return 0;
}