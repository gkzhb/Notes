// SPOJ, Guess the Queue
// 用双向链表来实现

#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>
// #include <map>

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
		dt.pop_back();
		size--;
	}
	void pop_front()
	{
		dt.pop_front();
		size--;
	}

	void push_back(long id)
	{
		if (dt.empty())
			dt.push_back(Node(id, 0));
		else
			dt.push_back(Node(id, dt.back().n + 1));
		size++;
	}
	void push_front(long id)
	{
		if (dt.empty())
			dt.push_back(Node(id, 0));
		else
			dt.push_front(Node(id, dt.front().n - 1));
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
		return (*iter).i;
	}

	long getPos(long id) 
	{
		list<Node>::const_iterator iter;
		for (iter = dt.begin(); iter != dt.end() && (*iter).i != id; iter++)
			;
		if (iter == dt.end())
			return 0;
		else
			return (*iter).n;
	}

	bool empty() { return 0 == size; }
	
private:
	list<Node> dt;
	long size;
};

int main(void)
{
	srand(unsigned(time(0)));
	long t, n, op, id, tmp;
	char pos;
	busQueue a;
	ostream fin, fout;
	fin.open("input.in");
	fout.open("guess1.out");
	t = 10;
	fin << t << endl;
	for (long i = 0; i < t; i++)
	{
		fout << "Case " << i + 1 << ':' << endl;
		n = rand() % 100 + 10;
		fin << n << endl;
		for (long j = 0; j < n; j++)
		{
			op = rand() % 3 + 1;
			while (2 == op && a.empty())
				op = rand() % 3 + 1;
			tmp = rand() % 2;

			fin << op << pos;
			if (2 != op)
			{
				id = rand() % 10000 + 1;
				while (a.getPos(id))
					id = rand() % 1000 + 1;
				fin << id << endl;
				if (1 == op)
					switch(pos)
					{
						case 'B': a.push_back(id);break;
						case 'F': a.push_front(id);break;
					}
				else
					switch(pos)
					{
						case 'D': fout << a.getId(id) << endl;break;
						case 'P': fout << a.getPos(id) << endl;break;
					}
			}
			else
			{
				switch(pos)
				{
				case 'B': a.pop_back();break;
				case 'F': a.pop_front();break;
				};
				fin << endl;
			}
		}
	}
	fin.close();
	fout.close();

	return 0;
}