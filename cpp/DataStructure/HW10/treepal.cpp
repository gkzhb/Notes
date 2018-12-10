// SPOJ, TREEPAL
// 回文串的两个点只可能在树的同一层上，所以只要对一层的节点数 x 求 C(x, 2) 的和即为答案
// 不知道为啥会 Runtime Error，估计是某个地方数组越界的问题，但是我没能 Debug 出来

#include <cstdio>
#include <vector>

using namespace std;

class Node
{
	public:
		Node(): ch(), dep(-1) { }
		vector<int> ch;
		int dep;
};

class Tree
{
	public:
		Tree(): dt() { }
		Tree(int n): dt(n + 1, Node()), dep(n + 1, 0) { }
		long long pal()
		{
			dfs(1, 0);
			long long ret = 0, t;
			for (int i = 1; i < dep.size(); i++)
			{
				t = dep[i];
				if (t > 1)
					ret += t * (t - 1) / 2;
			}
			return ret;
		}
		void dfs(int x, int p)
		{
			dt[x].dep = dt[p].dep + 1;
			// if (dt[x].dep == dep.size())
			// 	dep.push_back(0);
			dep[dt[x].dep]++;
			for (int i = 0; i < dt[x].ch.size(); i++)
				if (dt[x].ch[i] != p)
					dfs(dt[x].ch[i], x);
		}
			

		int push(int x, int y)
		{
			dt[x].ch.push_back(y);
			dt[y].ch.push_back(x);
		}
	private:
		vector<Node> dt;
		vector<int> dep;
};

long long gcd(long long x, long long y)
{
	while (y)
	{
		x = x % y;
		x = x ^ y;
		y = x ^ y;
		x = x ^ y;
	}
	return x;
}

int main()
{
	long long n;
	long long x, y, z, ans;
	while (EOF != scanf("%d", &n))
	{
		Tree a(n + 1);
		ans = 0;
		for(int i = 0, x, y; i < n - 1; i++)
		{
			scanf("%d %d", &x, &y);
			a.push(x, y);
		}
		x = a.pal(), y = (n * (n - 1)) / 2, z;
		z = gcd(x, y);
		printf("%lld/%lld\n", x / z, y / z);
	}

	return 0;
}
