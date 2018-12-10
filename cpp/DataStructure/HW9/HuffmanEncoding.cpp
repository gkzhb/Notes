// SPOJ, VHUFFM - Variable Radix Huffman Encoding
// 按规则模拟

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class SortNode
{
	public:
		SortNode(): dt(0), num(-1) { }
		SortNode(int data, int number): dt(data), num(number) { }
		int dt, num;
		static bool comp(const SortNode &x, const SortNode &y)
		{
			return x.dt > y.dt;
		}
};

class TreeNode
{
	public:

		SortNode dt;
		list<int> ch;	// children
};
	
class HTree
{
	public:
		
	private:
		vector<Node> dt;
};
int main()
{
	int r, n, i;
	while(cin >> r, 0 != r)
	{
		cin >> n;
		vector<int> freq;
		vector<vector> 
		for(i = 0; i < n; i++)
	}

	return 0;
}
