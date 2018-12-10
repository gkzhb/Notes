#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
	int n, m, i, j, x, xx, y, yy, ht = 0, cht, ans = 0;
	cin >> n >> m;
	vector<vector<bool>> b(n, vector<bool>(m, 0));
	vector<vector<int>> a(n, vector<int>(m, 0));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			cin >> x;
			a[i][j] = x;
			if (0 == i || n - 1 == i || 0 == j || m - 1 == j)
			{
				q.push({x, i * m + j});
				b[i][j] = 1;
			}
		}
	while (!q.empty())
	{
		pair<int, int> tp = q.top();
		q.pop();
		cht = tp.first;
		x = tp.second / m;
		y = tp.second % m;
		ht = max(ht, cht);
		for (i = 0; i < 4; i++)
		{
			xx = x + dx[i];
			yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && !b[xx][yy])
			{
				b[xx][yy] = 1;
				if (a[xx][yy] < ht)
					ans += ht - a[xx][yy];
				q.push({a[xx][yy], xx * m + yy});
			}
		}
	}
	cout << ans << endl;
	return 0;
}
		

