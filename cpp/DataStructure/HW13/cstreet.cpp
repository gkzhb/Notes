// SPOJ, CSTREET - Cobbled streets
// 求最小生成树对应边权之和，套用之前 RepairRoad.cpp 的大部分代码

#include <cstdio>
#include <list>
#include <vector>
#include <queue>
#define mint long long
using namespace std;
class Node
{
public:
	mint d, w;	// d: destination, w: weight(cost)
};
class Cmp
{
public:
	bool operator()(Node &x, Node &y)
	{ return x.w > y.w; }
};


int main()
{
	mint n, m, t, k = 0, i, u, v, w, p, cnt;
	long long ans;
	Node nd;
	vector<list<Node> > b;
	vector<bool> milk;
	scanf("%lld", &t);
	while (k++ < t)
	{
		scanf("%lld%lld%lld", &p, &n, &m);
		ans = 0;
		cnt = 1;
		priority_queue<Node, vector<Node>, Cmp> a;
		b.clear();
		b.resize(n);
		if (n > milk.size())
		milk.resize(n);		// 记录建筑是否在最小生成树中
		milk[0] = 1;
		for (i = 1; i < n; i++)
			milk[i] = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%lld%lld%lld", &u, &v, &w);
			u--, v--;
			nd.w = w;
			nd.d = v;
			if (0 != v)
				b[u].push_back(nd);
			nd.d = u;
			if (0 != u)
				b[v].push_back(nd);
			if (milk[u] ^ milk[v])
				if (milk[v])
					a.push(nd);
				else
				{
					nd.d = v;
					a.push(nd);
				}
		}
		while (cnt < n)
		{
			if (!a.empty())
				nd = a.top();
			while(!a.empty() && milk[nd.d])
			{
				a.pop();
				nd = a.top();
			}
			if (a.empty())
				break;
			a.pop();
			u = nd.d;
			ans += nd.w;
			milk[u] = 1;
			cnt++;
			for (list<Node>::const_iterator i = b[u].begin(), j = b[u].end(); i != j; i++)
				if (!milk[i->d])
					a.push(*i);
		}
		if (cnt < n)
			printf("impossible\n");
		else
			printf("%lld\n", ans * p);
	}
	return 0;
}
