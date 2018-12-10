#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gmax, gmin;

int binSearch(const vector<int>& a, int x)
{
	if (x < a.front())
		return -1;
	if (x == a.front())
		return 0;
	if (x >= a.back())
		return a.size() - 1;
	int mid, i = 0, j = a.size() - 1;
	while (j - i > 1)
	{
		mid = (i + j) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			j = mid;
		else
			i = mid;
	}
	return i;
}
	
int find(const vector<vector<int>> &a, int min, int max, int pos)
{
	if (pos == a.size())
	{
		gmax = max;
		gmin = min;
		return max - min;
	}
	int ret, i = binSearch(a[pos], min), tmp;
	if ((-1 != i && a[pos][i] == min) || (i + 1 < a.front().size() && a[pos][i + 1] <= max))
		ret = find(a, min, max, pos + 1);
	else
		if (-1 == i)
			ret = find(a, min, a[pos].front(), pos + 1);
		else
		{
			ret = find(a, a[pos][i], max, pos + 1);
			if (i + 1 < a[0].size())
				tmp = find(a, min, a[pos][i + 1], pos + 1);
			else
				tmp = ret;
			if (tmp < ret)
				ret = tmp;
		}
	return ret;
}

int main()
{
	int n, m, i, j, x;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m, 0));
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			cin >> x;
			a[i][j] = x;
		}
		sort(a[i].begin(), a[i].end());
	}

	x = find(a, a[0][0], a[0][0], 1);
	for(i = 1; i < m; i++)
	{
		j = find(a, a[0][i], a[0][i], 1);
		if (j < x)
			x = j;
	}
	cout << x << endl;

	return 0;
}
