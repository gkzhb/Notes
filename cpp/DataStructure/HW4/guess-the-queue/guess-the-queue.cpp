// SPOJ, Guess the Queue
// Solution 1, TLE
// 用双向链表来实现, TLE
// 用一个 map 记录队列中绝对编号(从0开始向正和负扩展), 从而计算出队列中的位置

#include <iostream>
#include <list>
#include <map>

// #define TEST
#ifdef TEST
#include <ctime>
#endif

using namespace std;

class Node
{
public:
	Node(): i(0), n(0) { }
	Node(long id, long num): i(id), n(num) { }
	long i, n;
};

class busQueue
{
public:
	busQueue(): size(0) { }
	void pop_back()
	{
		d.erase(dt.back().i);
		dt.pop_back();
		size--;
	}
	void pop_front()
	{
		d.erase(dt.front().i);
		dt.pop_front();
		size--;
	}

	void push_back(long id)
	{
		if (dt.empty())
			dt.push_back(Node(id, 0));
		else
			dt.push_back(Node(id, dt.back().n + 1));
		d[id] = dt.back().n;
		size++;
	}
	void push_front(long id)
	{
		if (dt.empty())
			dt.push_back(Node(id, 0));
		else
			dt.push_front(Node(id, dt.front().n - 1));
		d[id] = dt.front().n;
		size++;
	}

	long getId(long pos)
	{
		list<Node>::const_iterator iter;
		pos--;
		if (size > pos * 2)
		{
			iter = dt.begin();
			for (long i = 0; i < pos; i++)
				iter++;
		}
		else
		{
			iter = dt.end();
			pos = size - pos;
			for (long i = 0; i < pos; i++)
				iter--;
		}
		return iter->i;
	}

	long getPos(long id) { return d[id] - dt.front().n + 1; }
	
private:
	list<Node> dt;
	map<long, long> d;
	long size;
};

int main(void)
{
#ifdef TEST
	long start = clock();
#endif

	long t, n, op, id;
	char pos;
	cin >> t;
	for (long i = 0; i < t; i++)
	{
		busQueue a;
		cout << "Case " << i + 1 << ':' << endl;
		cin >> n;
		for (long j = 0; j < n; j++)
		{
			cin >> op >> pos;
			if (2 != op)
			{
				cin >> id;
				if (1 == op)
					switch(pos)
					{
						case 'B': a.push_back(id);break;
						case 'F': a.push_front(id);break;
					}
				else
					switch(pos)
					{
						case 'D': cout << a.getId(id) << endl;break;
						case 'P': cout << a.getPos(id) << endl;break;
					}
			}
			else
				switch(pos)
				{
				case 'B': a.pop_back();break;
				case 'F': a.pop_front();break;
				};
		}
	}

#ifdef TEST
	long end = clock();
	cout << "The running time of program \"guess-the-queue.cpp\"" << end - start << endl;
#endif

	return 0;
}