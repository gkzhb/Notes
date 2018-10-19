// LeetCode, Remove Duplicate Letters
// 用两个数组 a b 分别记录26个字母的出现次数以及是否在新串中使用
// 在遍历中, 每次未压入栈以及从栈中弹出的字母对应的 a 数组中的值就要减 1 
// (用来判断在后面出现该字母时是否能够忽略它, 当值为 1 则不能出栈或者必须将字母入站)
// 用一个栈存储新串的字母(先压入 'a' - 1 以避免后面更多的分类讨论)
// 从头开始遍历原字符串, 若字符串中字符已经用过, 直接跳过该字母,
// 否则判断 若其 ascii 大于栈顶元素 ascii, 直接将其压栈
// 否则判断栈顶元素是否可以出栈, 若可以则出栈, 重复此过程直到

// #define LOCAL
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