#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int x, int y)
{
	return x > y;
}
int main()
{
	int n, i, ans = 0;
	cin >> n;
	vector<int> a(n, 0), b(n, 0);
	for(i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end(), comp);
	for(i = 0; i < n; i++)
		cin >> b[i];
	sort(b.begin(), b.end(), comp);

	i = 0;
	vector<int>::const_iterator j = b.begin(), k = b.end();
	while(j != k)
	{
		while (j != k && a[i] < *j)
			j++;
		if (j != k)
		{
			j++;
			i++;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}

