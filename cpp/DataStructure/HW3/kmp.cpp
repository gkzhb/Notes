#include <iostream>
#include <vector>
#include <string>

using std::cin;		using std::cout;	using std::endl;
using std::string;	using std::vector;


void preprocessing(vector<int> &next, const string &s)
{
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
}

int kmp(string a, string b)
{
	int i = 0, j = 0;
	vector<int> next(a.size(), 0);
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
			cout << j - i << endl;
	}
	return -1;
}

int main(void)
{
	string a, b;
	cin >> a >> b;
	cout << kmp(a, b) << endl;
	return 0;
}