// Online Judge, 1015 排序集合
// 用 a[n] 存储 n 个整数是否在集合内
// i 从 0 增加到 n - 1，如果 k 大于所有 a[i] 取 1 的数的个数，
// 将该位设为 0，即不在集合内，同时 k 减小 a[i] 取 1 的数的个数
// 若 k 小于，则 k 减小 1（大于或等于后面所有数都不取的情况）
// 重复循环该过程

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, k, i, j;
	cin >> n >> k;
	if (k < 2)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<bool> a(n, 1);

	i = 0;
	k--;	// 减去空集
	while (k)
	{
		j = 1 << (n - i - 1);
		while (k > 0 && k > j)
		{
			k -= j;
			j >>= 1;
			a[i] = 0;
			i++;
		}
		if (k > 0)
		{
			k--;
			i++;
			if (0 == k)
				for (j = i; j < n; j++)
					a[j] = 0;
		}

	}

	for (i = 0; i < n; i++)
		if (a[i])
			cout << i + 1 << ' ';
	cout << endl;

	return 0;
}