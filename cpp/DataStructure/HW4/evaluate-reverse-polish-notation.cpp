// LeetCode, Evaluate Reverse Polish Notation
// 逐个处理 vector 中每个字符串, 若有数字则转化为 int 存入栈中, 
// 若是操作符, 则将栈顶两个元素进行相应操作, 对栈进行相应的处理

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
	int stoInt(const string & s)	// 将 string 转化为 int 类型
	{
		int ans = 0, flag = 1;
		string::const_iterator i = s.begin();
		if (*i == '-')
		{
			flag = -1;
			i++;
		}
		while(i != s.end())
		{
			ans = ans * 10 + *i - '0';
			i++;
		}
		return ans * flag;
	}

	int cal(int a, int b, char op)		// 计算 a op b 的值
	{
		switch(op)
		{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
		}
		return 0;
	}

    int evalRPN(vector<string>& tokens) {
		if (tokens.empty())
			return 0;
        vector<int> a;
		int tmp;
		for (vector<string>::const_iterator i = tokens.begin(); i != tokens.end(); i++)
		{
			if (i->size() > 1 || isdigit((*i)[0]))
			{
				tmp = stoInt(*i);
				a.push_back(tmp);
			}
			else
			{
				a[a.size() - 2] = cal(a[a.size() - 2], a[a.size() - 1], (*i)[0]);
				a.pop_back();
			}

		}
		return a[0];
    }
};

#ifdef LOCAL
int main(void)
{
	int n;
	vector<string> a;
	Solution b;
	string tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	cout << b.evalRPN(a) << endl;

	return 0;
}
#endif