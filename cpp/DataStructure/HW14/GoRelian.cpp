// SPOJ, GORELIAN - Here We Go(relians) Again
// 使用 Dijkstra 算法，加上堆进行优化

#include <cstdio>
#include <list>
#include <vector>
#include <queue>

using namespace std;

#define LEN 2520

class Compare
{
	public:
		bool operator()(pair<int, int> &x, pair<int, int> &y)
		{ return x.first > y.first; }
};

void readEastWest(vector<list<pair<int, int> > > &a, int colm, int i)
{
	int len = colm - 1, x = colm * i, j, dt;
	char ch;
	pair<int, int> tmp;
	for (j = 0; j < len; j++)
	{
		scanf("%d %c", &dt, &ch);
		if (0 != dt)
		{
			dt = LEN / dt;
			tmp.first = dt;
			switch (ch)
			{
				case '<':
					tmp.second = x + j;
					a[x + j + 1].push_back(tmp);
					break;
				case '>':
					tmp.second = x + j + 1;
					a[x + j].push_back(tmp);
					break;
				case '*':
					tmp.second = x + j + 1;
					a[x + j].push_back(tmp);
					tmp.second--;
					a[x + j + 1].push_back(tmp);
					break;
				default:
					printf("Error in read EW char\n");
			}
		}
	}
}

void readNorthSouth(vector<list<pair<int, int> > > &a, int colm, int i)
{
	int x = colm * i, j, dt;
	char ch;
	pair<int, int> tmp;
	for (j = 0; j < colm; j++)
	{
		scanf("%d %c", &dt, &ch);
		if (0 != dt)
		{
			dt = LEN / dt;
			tmp.first = dt;
			switch (ch)
			{
				case '^':
					tmp.second = x + j;
					a[x + j + colm].push_back(tmp);
					break;
				case 'v':
					tmp.second = x + j + colm;
					a[x + j].push_back(tmp);
					break;
				case '*':
					tmp.second = x + j + colm;
					a[x + j].push_back(tmp);
					tmp.second -= colm;
					a[x + j + colm].push_back(tmp);
					break;
				default:
					printf("Error in read NS char\n");
			}
		}
	}
}

int main()
{
	int n, m, i, j, target;
	long long ans;
	pair<int, int> t;
	vector<list<pair<int, int> > > a;	// 保存邻接表
	while (1)
	{
		scanf("%d %d", &n, &m);
		if ((n | m) == 0)
			break;
		m++;
		ans = 0;
		target = (n + 1) * m;
		vector<bool> c(target, false);		// 记录某点是否被走过
		priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> b;
		// 存储即将选择的边集的堆。pair 的 first 记录起点到目标的长度，second 记录目标位置
		a.clear();
		a.resize(target--);
		for (i = 0; i < n; i++)
		{
			readEastWest(a, m, i);
			readNorthSouth(a, m, i);
		}
		readEastWest(a, m, n);

		for (list<pair<int, int> >::const_iterator p = a[0].begin(), q = a[0].end(); p != q; p++)
			b.push(*p);
		c[0] = true;
		while (!b.empty())
		{
			t = b.top();
			while (t.first && c[t.second])
			{
				b.pop();
				if (b.empty())
					t.first = 0;
				else
					t = b.top();
			}
			if (0 != t.first)
			{
				i = t.second;
				j = t.first;
				if (i == target)
				{
					ans = j;
					break;
				}
				c[i] = true;
				for (list<pair<int, int> >::const_iterator p = a[i].begin(), q = a[i].end(); p != q; p++)
					if (!c[p->second])
					{
						t.second = p->second;
						t.first = p->first + j;
						b.push(t);
					}
				b.pop();
			}
		}
		if (b.empty())
			printf("Holiday\n");
		else
			printf("%lld blips\n", ans);
	}
	return 0;
}
