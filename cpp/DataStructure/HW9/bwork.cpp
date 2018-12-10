// SPOJ, Boring Homework
// 使用中序遍历，计算各个节点为根节点的子树 其根节点与最右侧在打印中的列数
// 然后通过层次遍历逐行打印

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class Node
{
	public:
		Node(): lc(-1), rc(-1), lp(0), rp(0), p(0), dt(0) { }
		int lc, rc, lp, rp, p, dt;
		// lc(left child) 左孩子 rc 右孩子
		// lp(left positon) 左端打印位置最后一个字符在行中的位置的后一位(从 0 开始) rp 同理右边对应最后一个字符的位置的后一位
		// p 该节点 o 的打印位置
		// 实际上 lp == p
		// dt 节点数据
};

class Sig
{
	public:
		Sig() { }
		Sig(int data, int layer): dt(data), lay(layer) { }
		int dt, lay;	// dt:节点下标	lay:节点所在层数
};

class Bst	// Binary Search Tree
{
	public:
		Bst(): dt(), size(0) { }
		Bst(int n): dt(n, Node()), size(0) { }
		void push(int x)
		{
			int pos = 0, last;
			if (0 == size)
			{
				dt[size++].dt = x;
				return;
			}
			while(-1 != pos)
			{
				last = pos;
				if (dt[pos].dt > x)
					pos = dt[pos].lc;
				else
					pos = dt[pos].rc;
			}
			if (dt[last].dt > x)
				dt[last].lc = size;
			else
				dt[last].rc = size;
			dt[size++].dt = x;
		}
		void cal()	// 使用中序遍历计算每行的字符下标位置
		{
			inorder(0, 0);
		}
		void print()	// 打印各行字符
		{
			int i = 1;
			list<Sig> que;	// 队列记录层次遍历
			// 打印第一行
			que.push_back(Sig(0,0));
			printNode(que, 0);
			while (!que.empty())
			{
				printVertical(que, i);
				printNode(que, i);
				i++;
			}
		}
	private:
		// 打印 |  lay: 当前打印的层次
		void printVertical(list<Sig> &a, int lay)
		{
			int j, k, pos = 0;
			list<Sig>::const_iterator i = a.begin(), ending = a.end();
			while(ending != i && lay == i->lay)
			{
				j = i->dt;
				k = dt[j].p;
				cout << string(k - pos, ' ') << '|';
				pos = k + 1;
				i++;
			}
			cout << endl;
		}
		// 打印节点所在行，同时向队列中添加下一层次的节点	lay: 打印层次
		void printNode(list<Sig> &a, int lay)
		{
			int k, j = 0, pos = 0;
			while(!a.empty() && lay == a.front().lay)
			{
				j = a.front().dt;
				k = dt[j].lc;
				if (-1 != k)
				{
					a.push_back(Sig(k, lay + 1));
					cout << string(dt[k].p - pos, ' ') << '+';
					pos = dt[k].p + 1;
					cout << string(dt[k].rp - pos, '-');
				}
				else
					cout << string(dt[j].p - pos, ' ');
				pos = dt[j].p;
				cout << 'o';
				pos++;
				k = dt[j].rc;
				if (-1 != k)
				{
					a.push_back(Sig(k, lay + 1));
					cout << string(dt[k].lp - pos, '-') << '+';
					pos = dt[k].lp + 1;
				}
				a.pop_front();
			}
			cout << endl;
		}
		// 中序遍历 p: 当前子树根节点下标 pos: 当前子树最左侧字符所在下标
		int inorder(int p, int pos)
		{
			if (-1 != dt[p].lc)
				pos = inorder(dt[p].lc, pos);
			dt[p].lp = dt[p].p = pos++;
			if (-1 != dt[p].rc)
				pos = inorder(dt[p].rc, pos);
			return dt[p].rp = pos;
		}
		vector<Node> dt;
		int size;	// 记录当前树中节点个数
};

int main()
{
	int t, n, x;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		Bst a(n);
		for(int j = 0; j < n; j++)
		{
			cin >> x;
			a.push(x);
		}
		a.cal();
		cout << "Case #" << i + 1 << ":" << endl;
		a.print();
	}
	return 0;
}
