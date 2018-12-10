// SPOJ, Treeramids
// 同 Longest path in a tree 类似的构造树的方式
// （为了避免编号大的节点比编号小的节点更靠近根节点导致树建立失败，将所有相连的点都加入 child 中，最后从根节点开始删除 child 中唯一的父节点）
// 最后通过二叉树的后序遍历计算出结果

#include <iostream>
#include <vector>
#include <list>
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))

using namespace std;

class Node
{
	public:
		Node() : vol(1), ch() { }
		list<int> ch;
		int vol;
};

class Tree
{
	public:
		Tree() { }
		Tree(int size): dt(size, Node()) { }
		void push(int x, int y)
		{
			dt[x].ch.push_back(y);
			dt[y].ch.push_back(x);
		}
		
		int volume(int x, int parent)
		{
			if (dt[x].ch.empty())
				return 1;
			int ret = 0, vol = 0, store = 0;
			list<int>::iterator i = dt[x].ch.begin(), j = dt[x].ch.end();
			while(i != j)
			{
				if (*i == parent)
				{
					list<int>::iterator tmp = i++;
					dt[x].ch.erase(tmp);
					continue;
				}
				store = volume(*i, x);
				ret += store;
				vol += dt[*i].vol;
				i++;
			}
			vol += dt[x].ch.size() + 1;
			dt[x].vol = vol;
			ret += vol;
			return ret;
		}
	private:
		vector<Node> dt;
};

int main()
{
	int n, i, j, t, u, v;
	cin >> t;
	for(j = 0; j < t; j++)
	{
		cin >> n;
		Tree a(n);
		n--;
		for(i = 0; i < n; i++)
		{
			cin >> u >> v;
			a.push(u, v);
		}
		cout << a.volume(0, -1) << endl;
	}
	return 0;
}
