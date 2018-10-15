class Solution {
public:
    string shortestPalindrome(string s) {
		vector<int> next(s.size() + 1, 0);
 		int i = 0, j = -1, max = 1;
		next[0] = -1;
		while (i < s.size())
			if (-1 == j || s[i] == s[j])
			{
				i++;
				j++;
				next[i] = j;
				if (2 * i + 1 > j && 2 * i + 1 > max)
					max = 2 * i + 1;
			}
			else
				j = next[j];
    }
};