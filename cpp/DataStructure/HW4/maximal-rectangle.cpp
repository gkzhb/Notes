// LeetCode, Maximal Rectangle,
// 先根据每行数据生成一个二维数组 a , 记录从每个位置开始计算该行后面连续的 1 的个数
// 然后在遍历整个 matrix , 在每个位置计算 以此位置为矩形左上顶点时 不同高度的矩形可能的最大面积, 与 max 值比较

#define LOCAL
#ifdef LOCAL
#include <iostream>
#include <vector>

using namespace std;
#endif

class Node
{
public:
	Node(int xx, int yy, int width, int height):x(xx), y(yy), w(width), h(height) { }
	int x, y, w, h;
	Node *next;
};

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		typedef vector<vector<char>>::size_type height;
		typedef vector<char>::size_type width;
		int max = 0, tmp;
		vector<vector<int>> a;
		height m = matrix.size(), i, h;
		if (0 == m)
			return 0;
		width n = matrix[0].size(), j, w;
		if (0 == m)
			return 0;
		for(i = 0; i < m; i++)
		{
			a.push_back(vector<int>(n, 0));
			tmp = 0;
			j = n;
			while(j)
			{
				j--;
				if (matrix[i][j] == '1')
				{
					a[i][j] = ++tmp;
					if (tmp > max)
						max = tmp;
				}
				else
					tmp = 0;
			}
		}

		for(i = 0; i < m; i++)
		{
			j = 0;
			while(j < n && '0' == matrix[i][j])
				j++;
			while(j < n)
			{
				w = a[i][j];
				h = 0;
				for(; w && i + h < m; h++)
				{
					if (a[i + h][j] < w)
						w = a[i + h][j];
					if (max < w * (h + 1))
						max = w * (h + 1);
				}
				j++;
			}		
		}
		return max;
	}
};

#ifdef LOCAL
int main(void)
{
	int m, n;
	char x;
	vector<vector<char>> a;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		a.push_back(vector<char>());
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			a[i].push_back(x);
		}
	}
	Solution b;
	cout << b.maximalRectangle(a) << endl;

	return 0;
}
#endif