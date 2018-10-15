#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

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

int kmp(string a)
{
	int i = 0, j = 0;
	vector<int> next(a.size() + 1, 0);
	preprocessing(next, a);
	char c;
	while ((c = getchar()) == '\n')
		;
	while (c != '\n')
	{
		if (-1 == i || a[i] == c)
		{
			i++;
			j++;
			c = getchar();
		}
		else
			i = next[i];
		if (i == a.size())
		{
			cout << j - i << endl;
			i = next[i];
		}
	}
	return -1;
}

int main(void)
{
	string s;
	char *a;
	while (cin)
	{
		gets(a);
		gets(a);
		s = a;
		kmp(s);
	}

	return 0;
}