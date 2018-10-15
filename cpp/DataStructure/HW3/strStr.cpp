#ifdef LOCAL
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#endif

class Solution {
public:
	void preprocessing(vector<int> &next, const string &s)
	{
		int i = 0, j = -1;
		next[0] = -1;
		while (i < s.size() - 1)
			if (-1 == j || s[i] == s[j])
			{
				i++;
				j++;
				next[i] = j;
			}
			else
				j = next[j];
	}

	int kmp(string &a, string &b)
	{
		if (0 == a.size())
			return 0;
		if (0 == b.size())
			return -1;
		int i = 0, j = 0;
		vector<int> next(a.size() + 1, 0);
		preprocessing(next, a);
		while (j < b.size())
		{
			if (-1 == i || a[i] == b[j])
			{
				i++;
				j++;
			}
			else
				i = next[i];
			if (i == a.size())
				return j - i;
		}
		return -1;
	}
    int strStr(string haystack, string needle) {
        return kmp(needle, haystack);
    }
};

#ifdef LOCAL
int main(void)
{
	string a, b;
	cin >> a >> b;
	Solution x;
	cout << x.strStr(a, b) << endl;
	return 0;
}
#endif