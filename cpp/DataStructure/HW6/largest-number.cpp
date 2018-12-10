// LeetCode, Largest Number
// 先将数字转化为字符串，方便比较高位数字
// 重写 compare 函数实现 string 数字排序
// 关键在于排序函数如何实现
// 若一个 string 为另一个 string 从 0 开始的子串，需要比较后者的后半部分与其前半部分的大小关系，于是变成一个需要递归实现的问题

#define LOCAL
#ifdef LOCAL
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#endif

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> snum;
		int backZero = 0;
		for(vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
			if (*i != 0)
				snum.push_back(to_string(*i));
			else
				backZero++;
		sort(snum.begin(), snum.end(), compare);
		string ans;
		for(vector<string>::size_type i = 0; i < snum.size(); i++)
			ans = ans + snum[i];
		if (ans.size() != 0)
			ans = ans + string(backZero, '0');
		else
			ans = "0";
		return ans;
	}
	static bool compare(const string &a, const string &b)
	{
		string::size_type i = 0;
		while(i < a.size() && i < b.size() && a[i] == b[i])
			i++;
		if (i != b.size() && i != a.size())
			if (a[i] > b[i])
				return 1;
			else
				return 0;
		if (i == b.size() && i == a.size())
			return 1;
		if (i == a.size())
			return !cmp(b, i);
		else
			return cmp(a, i);
	}
	static bool cmp(const string &s, int x)
	{
		string::size_type i = 0, len = x;
		while(i < len && x < s.size() && s[x] == s[i])
		{
			i++, x++;
			if (i == len)
				i = 0;
		}

		if (x == s.size())
			if (0 == i)
				return 0;
			else
				return !cmp(s, i);
		else
			if (s[x] > s[i])
				return 1;
			else
				return 0;
	}
};

#ifdef LOCAL
int main()
{
	int n, i, x;
	vector<int> a;
	cin >> n;
	for(i = 0;i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}

	Solution b;
	cout << b.largestNumber(a) << endl;

	return 0;
}
#endif