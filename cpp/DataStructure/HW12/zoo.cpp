// OJ, 1043 zoo
// 一开始打算用平衡树去做，将所有点按觅食能力排序插入树中，然后每投喂一次删除一个节点。不过这样做在寻找区间内第 k 强的狮子时会非常耗时，因为会扫到区间外的点。也没想到添加什么辅助数据结构方法可以优化。
// 于是换一种更暴力的做法，就是直接在区间内寻找第 k 小的值。通过类似快排将区间二分的方式可以较快速地找到结果。但是这样做这题还是太慢，而且好像在某组数据下会找不到可以投喂的狮子导致出错。
// 好吧，在网上发现原题，可以对区间进行排序然后构造区间的平衡树，之后一直增删树中节点达到改变区间的目的。不过我觉得我的答案应该是 TLE 而不应该是 WA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int a[100050];
static pair<int, int> b[100050];

int partition(int start, int end)
{
	int mid = b[end - 1].first;
	for (int i = start; i < end; i++)
		if (b[i].first <= mid)
		{
			if (start != i)
				swap(b[i], b[start]);
			start++;
		}
	return start;
}

void find(int start, int end, int k, pair<int, int> &x)
{
	if (k > end)
	{
		x.first = x.second = -1;
		return;
	}
	int pos = partition(start, end);
	if (pos - 1 == k)
		x = b[k];
	else
		if (pos > k)
			find(start, pos - 1, k, x);
		else
			find(pos, end, k, x);
}

int main()
{
	int n, m, x, y, k, len;
	pair<int, int> ret;
	cin >> n >> m;
	vector<bool> c(n, true);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> k;
		x--, y--, k--;
		len = 0;
		for (int j = x; j <= y; j++)
			if (c[j])
			{
				b[len].first = a[j];
				b[len++].second = j;
			}
		find(0, len, k, ret);
		if (-1 != ret.second)
		{
			c[ret.second] = false;
			cout << ret.first << endl;
		}
	}
	return 0;
}

// 参考资料：
// https://blog.csdn.net/u010558281/article/details/76572832
// http://jcf94.com/2015/03/16/2015-03-16-vijos-p1081/
