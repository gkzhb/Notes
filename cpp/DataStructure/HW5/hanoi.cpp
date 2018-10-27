// Online Judge, 1014 新汉诺塔
// 在除去位置正确的最大的圆盘之后，由大圆盘向小圆盘的顺序计算出各个圆盘的期望位置（使得垒在一起的圆盘尽可能少地移动），
// 根据期望位置计算出步数（使擂起来的圆盘在移动中始终在期望位置上），最终得到(0, 1, n - 1)的状态
// 再将最下面的当前最大圆盘与其目标位置进行对比，若不在期望位置，则移动上面 (n - 1) 个圆盘放到空闲的柱上，
// 若在，则直接消去当前最大圆盘

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

long a[46];
void getConst()	// 计算移动 i 层汉诺塔需要的步数
{
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i < 46; i++)
		a[i] = a[i - 1] * 2 + 1;
}

// 计算出每个圆盘的期望位置，并且返回将汉诺塔移动到(0, 1, n - 1)状态需要的步数
long long getExpectedPosition(const vector<int> &start, const vector<int> &target, int n)
{
	long long ans = 0;
	int exp[46];
	exp[n - 1] = 6 - start[n] - target[n];
	for (int i = n - 1; i > 0; i--)
		if (start[i] == exp[i])
			exp[i - 1] = exp[i];
		else
		{
			exp[i - 1] = 6 - start[i] - exp[i];
			ans += 1 + a[i - 1];
		}
	return ans;
}

int main(void)
{
	int n, i, j, x, num, pos;
	long long ans = 0;	// 记录移动步数
	cin >> n;
	vector<int> start(n + 1, 0), target(n + 1, 0);	// 储存各个编号的圆盘的柱子位置 A~C 对应于 1~3


	for (i = 0; i < 3; i++)
	{
		cin >> x;
		for (j = 0; j < x; j++)
		{
			cin >> num;
			start[num] = i + 1;
		}
	}
	for (i = 0; i < 3; i++)
	{
		cin >> x;
		for (j = 0; j < x; j++)
		{
			cin >> num;
			target[num] = i + 1;
		}
	}

	while (target[n] == start[n])	// 去除位置正确的最大的圆盘
		n--;
	getConst();
	ans = getExpectedPosition(start, target, n);
	
	pos = 6 - start[n] - target[n];	// 记录垒起来的汉诺塔的位置
	ans++;
	n--;

	while (n)		// 逐个消去最大圆盘
	{
		while (n > 0 && pos == target[n])
			n--;
		if (0 == n)
			break;
		ans += a[n - 1] + 1;
		pos = 6 - pos - target[n];
		n--;
	}

	cout << ans << endl;

	return 0;
}