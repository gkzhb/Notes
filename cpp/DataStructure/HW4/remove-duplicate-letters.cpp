#define LOCAL
#ifdef LOCAL
#include <iostream>
#include <vector>

using namespace std;
#endif

class Solution {
public:
	string removeDuplicateLetters(string s) {
		if (s.size() < 2)
			return s;
		vector<int> a(26, 0);		// 记录字母出现次数, 在后面程序中, 每忽略一次字母该次数减一
		vector<char> b(26, 0);		// 记录字母是否使用
		vector<char> ans;
		char top;
		for (string::const_iterator i = s.begin(); i != s.end(); i++)
			a[*i - 'a']++;
		ans.push_back('a' - 1);
		string::const_iterator i = s.begin();
		while (i != s.end())
		{
			top = *(ans.end() - 1);
			if (0 == b[*i - 'a'])
				if (*i < top && a[top - 'a'] > 1)
				{
					a[top - 'a']--;
					b[top - 'a'] = 0;
					ans.pop_back();
				}
				else
				{
					ans.push_back(*i);
					b[*i - 'a'] = 1;
					i++;
				}
			else
			{
				a[*i - 'a']--;
				i++;
			}
		}
		s = string(ans.begin() + 1, ans.end());
		return s;
	}
};

#ifdef LOCAL
int main(void)
{
	string s;
	Solution a;
	cin >> s;
	cout << a.removeDuplicateLetters(s) << endl;
	return 0;
}
#endif