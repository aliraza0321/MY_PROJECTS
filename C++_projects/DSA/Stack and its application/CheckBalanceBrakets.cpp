//function will be implemented in stack class

void balancebrak()
	{
		string str; 
		cout << "Enter parenthesis: ";
	    cin >> str;
		for (int i = 0; i<=str.length(); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				push(str[i]);
			}
			else if( (peek() == '(' && str[i] == ')') || ((peek() == '[' && str[i] == ']')) || (peek() == '{' && str[i] == '}'))
			{
				pop();
			}
			
		}
		if (isempty())
		{
			cout << "\nBalanced\n";
		}
		else
		{
			cout << "Unbalanced";
		}
	}
