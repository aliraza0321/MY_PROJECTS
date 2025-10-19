#include<iostream>
using namespace std;
void generateParentheses(int open, int close, string current = "") 
{
	if (open == 0 && close == 0) 
	{
		cout << current << endl;
		return;
	}
	if (open > 0)
		generateParentheses(open - 1, close, current + "(");
	if (close > open)
		generateParentheses(open, close - 1, current + ")");
}
int main()
{
    int n;
	cout << "Enter number of pairs: ";
	cin >> n;
	cout << "Valid parentheses combinations:\n";
	generateParentheses(n, n);
}