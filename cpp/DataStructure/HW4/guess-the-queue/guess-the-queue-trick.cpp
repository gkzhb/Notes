// SPOJ, Guess the Queue
// Solution 2, AC
// 本来打算用双向链表来实现, 结果最后 TLE
// 是在已知位置输出 ID 的地方拖了后腿, 因为我是用遍历去做的
// 之后在网上查找的时候发现了 deque, 于是换了个容器, 用deque, 因为它支持 random access, 
// 把那个拖后腿的直接用 return dt[pos - 1].i; 替换就 AC 了...
// PS: 感觉自己这样做好像作弊了

#include <iostream>
#include <deque>
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

	long getId(long pos) { return dt[pos - 1].i; }

	long getPos(long id) { return d[id] - dt.front().n + 1; }
	
private:
	deque<Node> dt;
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
	cout << "The running time of program \"guess-trick.cpp\": " << end - start << endl;
#endif

	return 0;
}

// 参考资料:
// [[C++ STL容器总结][https://juejin.im/post/5a5607166fb9a01cb256d501]]
// [[带你深入理解STL之Deque容器][https://blog.csdn.net/terence1212/article/details/52326945]]