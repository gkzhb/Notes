// SPOJ, Count the Pairs
// 先排序，然后二分查找寻找加 k 的值

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(const vector<int> &a, int x, int l = 0)
{
	if (a[0] >= x)
		return -1;
	int len = a.size();
	if (a[len - 1] <= x)
		return len - 1;
	int r = len - 1, mid;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			r = mid;
		else
			l = mid;
	}
	return l;
}

int main()
{
	int n, k, i, x, j, ans = 0;
	vector<int> a;
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());

	i = 0;
	while(i < a.size() - 1)
	{
		j = binSearch(a, a[i] + k, i + 1);
		if (a[j] == a[i] + k)
			ans++;
		i++;
	}
	cout << ans << endl;
	return 0;
}