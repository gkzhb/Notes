// Online Judge, 1014 新汉诺塔
// 使用广度优先搜索，寻找让 stat 加 1 的最小步数，其它非最优情况剪枝

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Node
{
public:
	char mv, stat; 
	// mv: 最后一次操作 从字节中低四位表示的位置移动到字节中高四位表示的位置
	// stat: 目前完成状态（从最大盘开始，摆放正确的连续编号的大盘个数）
	int t;
	// t: 操作步数
	vector<char> dt[3];

	Node(): mv(0), t(0) { }
	Node(char move, int count, vector<char> (&data)[3]): mv(move), t(count)
	{
		dt[0] = data[0];
		dt[1] = data[1];
		dt[2] = data[2];
		judgeStat();
	}
	char judgeStat()
	{
		int i;
		for (i = total; i > 0; i--)
			if (dt[(target[i] >> 6) & 3][target[i] & 63] != i)
				break;
		return stat = total - i;
	}	
	bool finish() const { return stat == total; }		// 判断是否变成目标状态

	static int total;		// 总圆盘个数
	static char target[46];	// 目标状态 保存对应序号圆盘的位置（字节中高 2 位表示圆盘所在柱子数，低 6 位表示在柱上从低到高的编号（从 0 开始））
	static void setTot(int n) { total = n; }
};
int Node::total = 0;
char Node::target[46];

bool compare(char x, char y)
{
	return x > y;
}

int doit(vector<char> (&s)[3], int n)
{
	list<Node> a;
	Node tmp;
	int i, j, lastStat, status = 0, best = 0;
	list<Node>::iterator head;
	a.push_back(Node(0x77, 0, s));
	head = a.begin();
	while (1)
	{
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if ((i != j) && (j | (i << 4) != head->mv) && !head->dt[i].empty() && head->dt[i].back() <= n - head->stat && (head->dt[j].empty() || head->dt[i].back() < head->dt[j].back()))
				{
					tmp = *head;
					tmp.mv = i | (j << 4);
					tmp.t++;
					tmp.dt[j].push_back(tmp.dt[i].back());
					tmp.dt[i].pop_back();
					tmp.judgeStat();
					if (tmp.finish())
						return tmp.t;
					a.push_back(tmp);
				}
		head++;
		a.pop_front();
	}
}

int main(void)
{
	int n, i, j, x, num;
	char tmp;
	vector<char> start[3];
	cin >> n;
	Node::setTot(n);

	for (i = 0; i < 3; i++)
	{
		cin >> x;
		for (j = 0; j < x; j++)
		{
			cin >> num;
			start[i].push_back(num);
		}
		sort(start[i].begin(), start[i].end(), compare);
	}
	
	for (i = 0; i < 3; i++)
	{
		cin >> x;
		tmp = i << 6;
		for (j = 0; j < x; j++)
		{
			cin >> num;
			Node::target[num] = tmp | j;
		}
	}

	cout << doit(start, n) << endl;

	return 0;
}