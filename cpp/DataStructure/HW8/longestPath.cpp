// SPOJ, Longest path in a tree
// 假设节点标号小的节点更接近根节点，从而从树的所用边中构造出树
// 然后统计每个节点 对应以此节点为根的子树的最大深度
// 从根节点开始，选择子节点中深度最大的两支，得到一个较大长路径
// 然后在每个子节点对应的子树中寻找最长路径
// 递归这个过程得到最大路径

#include <iostream>
#include <vector>
#include <list>
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))

using namespace std;

class Node
{
	public:
		Node() : dep(0), ch() { }
		list<int> ch;
		int dep;
};

class Tree
{
	public:
		Tree() { }
		Tree(int size): dt(size, Node()) { }
		void push(int x, int y)
		{
			int max = MAX(x, y), min = MIN(x, y);
			dt[min].ch.push_back(max);
		}
		int getDep()
		{
			travel(1);
			return dt[1].dep;
		}
		int longest(int x, int max)
		{
			bool flag = false;
			list<int>::const_iterator i = dt[x].ch.begin(), j = dt[x].ch.end();
			int cur = dt[x].dep, max2 = max, xx;
			max = -1;
			cur--;
			while(i != j)
			{
				xx = dt[*i].dep;
				if (xx > max)
					if (xx == cur)
						if (!flag)
							flag = true;
						else
						{
							max = cur;
							break;
						}
					else
						max = xx;
				i++;
			}
			if (max != -1)
				max = max + cur + 2;
			else
				max = cur + 1;
			max = MAX(max, max2);
			i = dt[x].ch.begin();
			while(i != j)
			{
				if (dt[*i].dep * 2 > max)
				{
					cur = longest(*i, max);
					if (cur > max)
						max = cur;
				}
				i++;
			}
			return max;
		}
	private:
		void travel(int x)
		{
			if (dt[x].ch.empty())
				return;
			list<int>::iterator i = dt[x].ch.begin(), j = dt[x].ch.end();
			while(i != j)
			{
				travel(*i);
				dt[x].dep = dt[x].dep >= dt[*i].dep ? dt[x].dep : dt[*i].dep;
				i++;
			}
			dt[x].dep++;
		}
		vector<Node> dt;
};

int main()
{
	int n, i, u, v;
	cin >> n;
	Tree a(n + 1);
	n--;
	for(i = 0; i < n; i++)
	{
		cin >> u >> v;
		a.push(u, v);
	}
	if (0 == a.getDep())
		cout << 0 << endl;
	else
		cout << a.longest(1, 0) << endl;

	return 0;
}