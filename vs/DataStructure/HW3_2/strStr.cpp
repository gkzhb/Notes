#define TEST
#ifdef TEST
#include <iostream>
#include <string>

using std::string;
#endif

class Solution {
public:
	int strStr(string haystack, string needle) {
		string::size_type l1 = haystack.size(), l2 = needle.size(), i, j;
		if (0 == l2)
			return 0;
		if (l1 < l2)
			return -1;
		for (i = 0; i < l1 - l2 + 1; i++)
		{
			for (j = 0; j < l2; j++)
				if (haystack[i + j] != needle[j])
					break;
			if (j == l2)
				return i;
		}
		return -1;
	}
};


#ifdef TEST
int main(void)
{
	string a, b;
	std::cin >> a >> b;
	Solution x;
	std::cout << x.strStr(a, b) << std::endl;
	return 0;
}
#endif