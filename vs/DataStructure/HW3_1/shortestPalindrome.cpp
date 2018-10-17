// #define TEST
#ifdef TEST
#include <iostream>
#include <string>

using std::string;
#endif

class Solution {
public:
	string shortestPalindrome(string s) {
		string::size_type i, j, k, len = s.size(), max = 0;
		if (len < 2)
			return s;
		for (i = 1; i < len; i++)
			if (s[i] == s[0])
			{
				j = 1;
				k = i - 1;
				while (j < k)
				{
					if (s[j] != s[k])
						break;
					j++;
					k--;
				}
				if (j >= k)
					max = i;
			}
		string ans;
		for (i = len - 1; i > max; i--)
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