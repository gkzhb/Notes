// POJ, 2002 Squares
// 在所有点中任取两点判读以这两点连线为边的正方形是否存在
// 通过 map 存储点的位置是否存在

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &x, pair<int, int> &y)
{
	return (x.first < y.first) || (x.first == y.first && x.second < y.second);
}

int main()
{
	int n, x, y, dx, dy;
	long long ans;
	pair<int, int> tmp;
	while (cin >> n, 0 != n)
	{
		ans = 0;
		vector<pair<int, int> > dt;
		map<pair<int, int>, bool> a;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp.first >> tmp.second;
			a[tmp] = true;
			dt.push_back(tmp);
		}
		sort(dt.begin(), dt.end(), cmp);
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
			{
				dx = dt[i].first - dt[j].first;
				dy = dt[i].second - dt[j].second;
				if (a.count(make_pair(dt[i].first + dy, dt[i].second - dx)) != 0 && a.count(make_pair(dt[j].first + dy, dt[j].second - dx)))
					ans++;
			}
		cout << ans / 2 << endl;
	}
	return 0;
}

// 参考资料：
// http://blog.sina.com.cn/s/blog_6635898a0100lxxa.html
