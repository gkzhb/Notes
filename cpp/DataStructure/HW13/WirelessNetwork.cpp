// POJ, 2236 Wireless Network
// 使用并查集

#include <cstdio>
#include <vector>
#include <list>
#include <cmath>
using namespace std;
int x[1010], y[1010], f[1010];
bool b[1010];		// 存储电脑是否修好

// 寻找 x 的祖先
int find(int x)
{
	if (f[x] == x)
		return x;
	else
		return f[x] = find(f[x]);
}

int main()
{
	int n, i, j, dx, dy;
	char c;
	long long d;
	scanf("%d%lld", &n, &d);
	vector<list<int> > a(n);
	d = d * d;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", x + i, y + i);
		f[i] = i;
		b[i] = 0;
	}
	// 将座标转化为邻接表
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
		{
			dx = abs(x[j] - x[i]), dy = abs(y[j] - y[i]);
			if (1ll * dx * dx + 1ll * dy * dy <= d)
			{
				a[i].push_back(j);
				a[j].push_back(i);
			}
		}
	while(1)
	{
		while ((c = getchar()) != EOF && (c != 'O' && c != 'S'))
			;
		if (EOF == c)
			break;
		switch (c)
		{
			case 'O':
				scanf("%d", &i);
				b[--i] = 1;
				for (list<int>::const_iterator p = a[i].begin(), q = a[i].end(); p != q; p++)
					if (b[*p])
						f[find(i)] = find(*p);
				break;
			case 'S':
				scanf("%d%d", &i, &j);
				if (find(--i) == find(--j))
					printf("SUCCESS\n");
				else
					printf("FAIL\n");
				break;
			default:
				printf("Error\n");
		}
	}
	return 0;
}
