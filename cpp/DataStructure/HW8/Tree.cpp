#include<vector>
#include<iostream>
using namespace std;
class Node
{
	public:
		Node(int data, int lc = -1, int rc = -1) : dt(data), l(lc), r(rc) { }
		int dt;
		int l, r;
};
class Tree
{
	public:
		Tree(): data() { }
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
					if (x > data[j].dt)
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
		void travel()
		{
			trvl(0);
		}
		void clear() { data.clear(); }
	private:
		void trvl(int x)
		{
			cout << data[x].dt << ' ';
			if (data[x].l != -1)
				trvl(data[x].l);
			if (data[x].r != -1)
				trvl(data[x].r);
		}
		vector<Node> data;
};

int main()
{
	int n, i, x;
	Tree a;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> x;
		a.push(x);
	}
	a.travel();
	return 0;
}
