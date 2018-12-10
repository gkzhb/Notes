// SPOJ, Labyrinth
// 类似 Longest path in a tree
// 两次 dfs 找最远点，对应第二次最远距离就是所求值

#include <iostream>
#include <vector>
#include <string>

using namespace std;


void dfs(vector<int> &Dis, const vector<vector<int>> &a, int pos, int last, int &maxIndex)
{
	if (Dis[pos] > Dis[maxIndex])
		maxIndex = pos;
	for(int i = 0, next; i < a[pos].size(); i++)
	{
		next = a[pos][i];
		if (next != last)
		{
			Dis[next] = Dis[pos] + 1;
			dfs(Dis, a, next, pos, maxIndex);
		}
	}
}

int main()
{
	int c, r, t;
	const string PRE = "Maximum rope length is ";
	const int X[2] = {-1, 0};
	const int Y[2] = {0, -1};
	cin >> t;
	for(int i = 0, max; i < t; i++)
	{
		cin >> c >> r;
		vector<vector<int>> a;
		vector<vector<int>> b(r, vector<int>(c, 0));
		char ch;
		for(int j = 0, t = 0; j < r; j++)
			for(int k = 0; k < c; k++)
			{
				cin >> ch;
				if ('.' == ch)
				{
					b[j][k] = t;
					a.push_back(vector<int>());
					for(int d = 0, xx, yy; d < 2; d++)	// 将邻接矩阵转化为相邻关系列表
					{
						xx = X[d] + j;
						yy = Y[d] + k;
						if (xx >= 0 && yy >=0 && b[xx][yy] != -1)
						{
							a[t].push_back(b[xx][yy]);
							a[b[xx][yy]].push_back(t);
						}
					}
					t++;
				}
				else
					b[j][k] = -1;
			}
		b.clear();
		vector<int> Dis(a.size(), 0);	// 存储每个节点到初始节点的距离
		max = 0;
		dfs(Dis, a, 0, 0, max);
		Dis[max] = 0;
		dfs(Dis, a, max, max, max);
		cout << PRE << Dis[max] << '.' << endl;
	}
	return 0;
}
