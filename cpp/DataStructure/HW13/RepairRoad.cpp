// SPOJ, Petya and Repairment of Roads
// 使用 Kruskal 算法，开始时将所有与 milkman 相邻的边加入到边集(堆)中，
// 然后取出其中最短的与没有牛奶的人相邻的边，将这个人的邻边加入到堆中。
// 重复此过程直到所有人都有牛奶

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
	mint n, m, t, k = 0, i, u, v, w, cnt;
	long long ans;
	Node nd;
	vector<list<Node> > b;
	vector<bool> milk;
	scanf("%lld", &t);
	while (k++ < t)
	{
		scanf("%lld%lld", &n, &m);
		ans = cnt = 0;
		priority_queue<Node, vector<Node>, Cmp> a;
		b.clear();
		b.resize(n);
		if (n > milk.size())
		milk.resize(n);		// 记录是否有牛奶
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &u);
			milk[i] = u;
			cnt += u;
		}
		for (i = 0; i < m; i++)
		{
			scanf("%lld%lld%lld", &u, &v, &w);
			u--, v--;
			nd.w = w;
			nd.d = v;
			// 有向边中指向有牛奶的边不需要保存
			if (!milk[v])
				b[u].push_back(nd);
			nd.d = u;
			if (!milk[u])
				b[v].push_back(nd);
			// 用有牛奶与无牛奶间的边初始化堆
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
			printf("%lld\n", ans);
	}
	return 0;
}
