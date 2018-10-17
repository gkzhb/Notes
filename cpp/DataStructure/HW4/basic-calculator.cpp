#define LOCAL
#ifdef LOCAL
#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;
#endif

class Solution {
public:
	int cal(int a, int b, char op)
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