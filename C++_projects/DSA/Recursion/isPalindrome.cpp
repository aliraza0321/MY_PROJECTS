#include<iostream>
using namespace std;
bool isPalindrome( string str, int start, int end) 
{
	if (start >= end)
		return true; // base case
	if (str[start] != str[end])
		return false; // not a palindrome
	return isPalindrome(str, start + 1, end - 1); 
}
int main()
{
    string num;
			cout << "Enter any string for checking palindrome:";
			cin >> num;
			int first = 0;
			int last = num.length()-1;
			cout<<isPalindrome(num,first,last);
}