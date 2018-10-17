#include <iostream>
#include <string>
#include <vector>

using namespace std;

int binary_search(vector<int> &a, int index, int ls)
{
	int i = 1, j = a.size() - 1, mid;
	if (a[i] >= index)
		return a[i] - index + a[0] - 1;
	if (a[j] < index)
		return ls - index;
	if (a[j] == index)
		return a[0] - 1;
	while (i < j)
	{
		mid = (i + j) / 2;
		if (a[mid] == index)
			return a[0] - 1;
		else
			if (a[mid] > index)
				j = mid;
			else
				i = mid;
		if (1 == j - i && i == mid)
			i++;
	}
	return a[j] - index + a[0] - 1;
}

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

void kmp(const string &a, const string &b, vector<int> &s)
{
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
		{
			s.push_back(j - i);
			i = next[i];
		}
	}
}

int main(void)
{
	string s, tmp;
	int n, ls, len, size = 0, max = 0, min;
	vector<vector<int>> a; 
	cin >> s >> n;
	ls = s.size();
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		len = tmp.size();
		if (len < ls)
		{
			a.push_back(vector<int>());
			a[size].push_back(len);
			kmp(tmp, s, a[size]);
			if (1 == a[size].size())
				a.pop_back();
			else
			{
				// for (int k = 0; k < a[size].size(); k++)
					// cout << a[size][k] << ' ';
				// cout << endl;
				size++;
			}
		}
	}

	for (int i = 0; i < ls; i++)
	{
		min = -1;
		for (int j = 0; j < a.size(); j++)
		{
			len = binary_search(a[j], i, ls);
			// cout << len << ' ';
			if (-1 == min || len < min)
				min = len;
		}
		// cout << endl;
		if (min > max)
			max = min;
	}
	if (0 == max)
		cout << "DuiYouNe!?" << endl;
	else
		cout << max << endl;

	return 0;
}