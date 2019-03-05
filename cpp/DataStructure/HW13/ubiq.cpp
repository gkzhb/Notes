// POJ, Ubiquitous Religions
// 并查集求集合的数目

#include <cstdio>
#include <vector>
using namespace std;
int a[50050];
bool b[50050];

// 寻找 x 的祖先
int find(int x)
{
	if (a[x] == x)
		return x;
	else
		return a[x] = find(a[x]);
}

// 统计集合数目
int count(int n)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
		b[find(i)] = true;
	for (int i = 0; i < n; i++)
		if (b[i])
			ret++;
	return ret;
}

int main()
{
	int n, m, t = 1;
	while (1)
	{
		scanf("%d %d", &n, &m);
		if (0 == n && 0 == m)
			break;
		for (int i = 0; i < n; i++)
		{
			a[i] = i;
			b[i] = false;
		}
		for (int i = 0, x, y; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			a[find(x)] = find(y);	// 添加 x y 连通
		}
		printf("Case %d: %d\n", t++, count(n));
	}
	return 0;
}

// 参考资料：
// 高大爷的并查集 PPT
