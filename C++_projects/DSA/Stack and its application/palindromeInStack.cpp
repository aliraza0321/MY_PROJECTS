void palindrome()
	{
		string str;
		cout << "Enter string: ";
		cin >> str;
		int last = str.length()-1;
		int start = 0;
		while (start<=last)
		{
			if (str[start] != str[last])
			{
				cout << "This is not palindrom\n";
				return;
			}
			start++;
			last--;
			
		}
		cout << "\nThis is  palindrome\n";
	}
