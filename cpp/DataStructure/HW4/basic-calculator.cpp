// LeetCode, Basic Calculator,
// 此题中只有加减与括号, 且没有负数, 所以从头到尾只要操作符两端数字已经算出来就可直接进行运算
// 从头到尾遍历字符串, 若为数字, 则用 while 循环将完整数字读取出来, 
// 并判断 ops 栈是否为空以及栈顶是否为左括号, 非空且非左括号则将数据进行运算;
// 若为 + - 操作符 或 左括号, 直接压栈;
// 若为后括号, 说明括号内数字已经计算出来, 将栈中的左括号出栈, 同上面读入数字进行相同判断决定是否进行计算

// #define LOCAL
#ifdef LOCAL
#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;
#endif

class Solution {
public:
	int cal(int a, int b, char op)	// calculate "a op b"
	{
		switch(op)
		{
		case '+': return a + b;
		case '-': return a - b;
		}
		return 0;
	}

    int calculate(string s) {
        string::const_iterator i = s.begin();
		vector<int> a;		// save numbers
		vector<char> ops;	// save operators
		int tmp;
		while (i != s.end())
		{
			while (i != s.end() && isspace(*i))
				i++;
			if (i == s.end())
				break;
			if (isdigit(*i))
			{
				tmp = *i - '0';
				i++;
				while (i != s.end() && isdigit(*i))
				{
					tmp = tmp * 10 + *i - '0';
					i++;
				}
				if (!ops.empty() && *(ops.end() - 1) != '(')
				{
					a[a.size() - 1] = cal(a[a.size() - 1], tmp, *(ops.end() - 1));
					ops.pop_back();
				}
				else
					a.push_back(tmp);
			}
			else
			{
				if (*i == ')')
				{
					ops.pop_back();
					if (!ops.empty())
					{
						a[a.size() - 2] = cal(a[a.size() - 2], a[a.size() - 1], *(ops.end() - 1));
						ops.pop_back();
						a.pop_back();
					}
				}
				else
					ops.push_back(*i);
				i++;
			}
		}
		return a[0];
    }
};

#ifdef LOCAL
int main(void)
{
	string s;
	getline(cin, s);
	Solution a;
	cout << a.calculate(s) << endl;

	return 0;
}
#endif