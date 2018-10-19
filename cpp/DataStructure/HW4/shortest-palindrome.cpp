// LeetCode, Shortest Palindrome
// 根据高大爷的 PDF 讲稿, 添加特殊符号再反向添加原字符串,
// 最后求出next 数组最后一位 next[s.size()] 就是开头最长回文子串的后一个字符下标

// #define TEST
#ifdef TEST
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#endif

class Solution {
public:
	int preprocessing(const string &s)
	{
		vector<int> next(s.size() + 1, 0);
		int i = 0, j = -1;
		next[0] = -1;
		while (i < s.size())
			if (-1 == j || s[i] == s[j])
			{
				i++;
				j++;
				next[i] = j;
			}
			else
				j = next[j];
		return next[s.size()];
	}

	string shortestPalindrome(string s) {
		string reverse(s.rbegin(), s.rend());
		int max, len = s.size();
		reverse = s + "#" + reverse;
		max = preprocessing(reverse);
		string ans;
		for (int i = len - 1; i >= max; i--)
			ans = ans + s[i];
		ans = ans + s;
		return ans;
	}
};

#ifdef TEST
int main(void)
{
	string s;
	std::cin >> s;
	Solution a;
	std::cout << a.shortestPalindrome(s) << std::endl;
	return 0;
}
#endif