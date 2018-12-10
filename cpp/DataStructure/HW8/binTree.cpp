// SPOJ, Ceiling Function
// 首先构造出树，然后用二叉树的中序遍历比较不同树的形状

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Node
{
	public:
		Node(int data, int lc = -1, int rc = -1) : dt(data), l(lc), r(rc) { }
		int dt;
		int l, r;
};

class BinTree
{
	public:
		BinTree() : data() { }
		void push(int x)
		{
			if (data.empty())
				data.push_back(Node(x));
			else
			{
				int j = 0, i;
				while (-1 != j)
				{
					i = j;
					if (x > data[i].dt)
					{
						j = data[i].r;
						if (-1 == j)
						{
							j = data.size();
							data[i].r = j;
							data.push_back(Node(x));
							j = -1;
						}
					}
					else
					{
						j = data[i].l;
						if (-1 == j)
						{
							j = data.size();
							data[i].l = j;
							data.push_back(Node(x));
							j = -1;
						}
					}
				}
			}
		}
		void clear() { data.clear(); }
		static bool compare(const BinTree &x, BinTree &y)
		{
			/* 本打算用非递归实现，调试太久放弃了
			int i = 0, j = 0, xx, yy;
			bool flag = false;
			vector<int> a, b;
			do
			{
				while (-1 != i && -1 != j)
				{
					a.push_back(i);
					b.push_back(j);
					if (!judgeNode(x, y, i, j))
						return false;
					i = x.data[i].l;
					j = y.data[j].l;
				}
				xx = a.size() - 1;
				yy = b.size() - 1;
				if (0 == xx && flag)
					xx = -1;
				// a.pop_back();
				// b.pop_back();
				if (-1 != xx)
				{
					if (0 == xx)
						flag = true;
					i = x.data[a[xx]].r;
					j = y.data[b[yy]].r;
					if (!judgeNode(x, y, i, j))
						return false;
				}
				while(xx != 0 && (-1 == x.data[a[xx - 1]].r || x.data[a[xx - 1]].r == a[xx]))
				{
					xx--;
					yy--;
					a.pop_back();
					b.pop_back();
				}

			}while(!a.empty());*/
			return travel(x, y, 0, 0);
		}
	private:
		vector<Node> data;
		static bool travel(const BinTree &x, BinTree &y, int i, int j)
		{
			if (!judgeNode(x, y, i, j))
				return false;
			if (x.data[i].l != -1)
				if (!travel(x, y, x.data[i].l, y.data[j].l))
					return false;
			if (x.data[i].r != -1)
				if (!travel(x, y, x.data[i].r, y.data[j].r))
					return false;
			return true;
		}
		static bool judgeNode(const BinTree &x, BinTree &y, int i, int j)
		{
			if ((-1 == x.data[i].l && -1 != y.data[j].l) || (-1 != x.data[i].l && -1 == y.data[j].l) || (-1 == x.data[i].r && -1 != y.data[j].r) || (-1 != x.data[i].r && -1 == y.data[j].r))
				return false;
			else
				return true;
		}
};

int main()
{
	int n, k, i, j, x;
	bool flag;
	vector<BinTree> a;
	while (cin >> n >> k)
	{
		for(i = 0; i < n; i++)
		{
			a.push_back(BinTree());
			flag = false;
			for(j = 0; j < k; j++)
			{
				cin >> x;
				a.back().push(x);
			}
			for(j = 0; j < a.size() - 1; j++)
				if (BinTree::compare(a[j], a.back()))
					break;
			if (j < a.size() - 1)
				a.pop_back();
			/*else
				cout << "无重复结构" << endl; */
		}
		cout << a.size() << endl;
		a.clear();
	}
	return 0;
}
