#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int grade(char op)		// 操作符优先级
{
	switch(op)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '^':
		return 4;
	case '(':
		return 5;
	case ')':
		return 1;
	case '$':
		return 0;
	}
}

void transform(string &s)
{

}

int main(void)
{
	int t;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		getline(cin, s);
		transform(s);
	}

	return 0;
}