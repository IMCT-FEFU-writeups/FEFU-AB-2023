#include <iostream>
#include <string>
#include <stack>

using namespace std;

int backet_count(string str) {
	stack<char> backet;
	int max_count = 0;
	if (str == "") {
		return 0;
	}
	for (int i = 0; i < str.size(); ++i) 
	{
		if (backet.empty() && (str[i] == ']' || str[i] == '}' || str[i] == ')')) 
		{
			return -1;
		}
		if (str[i] == '[' || str[i] == '{' || str[i] == '(') 
		{
			backet.push(str[i]);
		}
		else if (str[i] == ']' && backet.top() == '[') 
		{
			backet.pop();
		}
		else if (str[i] == '}' && backet.top() == '{') 
		{
			backet.pop();
		}
		else if (str[i] == ')' && backet.top() == '(') 
		{
			backet.pop();
		}
		if (backet.size() > max_count) 
		{
			max_count = backet.size();
		}
	}
	if (!backet.empty()) 
	{
		return -1;
	}
	else 
	{
		return max_count;
	}
}

int main() 
{
	string str;
	getline(cin, str);
	cout << backet_count(str) << endl;
}
