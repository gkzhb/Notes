// SPOJ, PFDEP - Project File Dependencies
// 拓扑排序问题

#include <cstdio>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Node
{
	public:
		Node(): in(0) { }
		int in;			// 记录该点的入度
		list<int> e;	// edges 从该点发出的边
};

/* class Compare
{
	public:
		bool operator()(int x, int y)
		{ return x > y; }
}; */

int main()
{
	int n, m, i, j, t, x, d;
	scanf("%d %d", &n, &m);
	vector<bool> b(n, true);	// 记录入度是否为 0
	vector<Node> a(n, Node());
	priority_queue<int, vector<int>, greater<int> > que;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &t);
		b[--x] = false;
		a[x].in = t;
		for (j = 0; j < t; j++)
		{
			scanf("%d", &d);
			a[--d].e.push_back(x);
		}
	}
	for (i = 0; i < n; i++)
		if (b[i])
			que.push(i);
	while (!que.empty())
	{
		i = que.top();
		que.pop();
		printf("%d ", i + 1);
		for (list<int>::const_iterator p = a[i].e.begin(), q = a[i].e.end(); p != q; p++)
			if (0 == --a[*p].in)
				que.push(*p);
	}
	putchar('\n');
	return 0;
}
