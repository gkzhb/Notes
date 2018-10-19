// SPOJ, Transform the Expression,
// 建立 ops 栈, 压入'$'避免分类讨论
// 遍历字符串, 若为字母直接输出
// 否则判断当前操作符与栈顶操作符优先级高低
// 当前的高则直接压栈, 否则判断可能出现左右括号的情况进行讨论

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int grade(char op)		// 操作符优先级, '(' 优先级与课本上略有不同
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
	vector<char> ops(1, '$');
	string::const_iterator i = s.begin();
	while (i != s.end())
	{
		if (isalpha(*i))
			cout << *i;			// *i 为字母 直接输出
		else
			if (grade(*i) >= grade(ops[ops.size() - 1]))
				ops.push_back(*i);		// 直接 push 操作符的情况
			else
				if ('(' != ops[ops.size() - 1])		// 判断 栈顶是否为左括号
				{
					cout << ops[ops.size() - 1];
					ops.pop_back();
					i--;
				}
				else
					if (')' != *i)  // 栈顶为左括号时 判断 *i 是否为右括号
						ops.push_back(*i);
					else
						ops.pop_back();
		i++;
	}
}

int main(void)
{
	int t;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> s;
		transform(s);
		cout << endl;
	}

	return 0;
}