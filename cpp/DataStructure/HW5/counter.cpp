// Online Judge, 1013 计数器
// 假设 n 有 k 位数，分为两部分计算：
// 1. 计算 1 ~ （10 ^ k - 1) 中各数字数目
// 2. 计算 10 ^ k ~ n 中各数字数目（从高位数字向低位数字遍历计算）

#include <iostream>

using namespace std;

int main(void)
{
	long n, cp, a[10], lg = 1, tmp, zero = 0, count = 1, x = 1, y = 0;
	cin >> n;
	cp = n;

	int t = 1;
	while (cp / 10 != 0)
	{
		cp /= 10;
		t++;
		lg *= 10;
	}
	if (1 == lg)
	{
		cout << 0 << endl;
		for (int i = 0; i < n; i++)
			cout << 1 << endl;
		for (int i = n; i < 9; i++)
			cout << 0 << endl;
		return 0;
	}
	for(long j = 10; j < lg; j *= 10)
	{
		x = 10 * x + j / 10 * 9;
		count += x;
		y = 10 * y + j / 10 * 9;
		zero += y;
	}
	for (int i = 1; i < 10; i++)
		a[i] = count;
	a[0] = zero;
	cp = 0;
	for (long j = lg; 0 != j; j /= 10)
	{
		tmp = n / j % 10;
		for (int i = j == lg ? 1 : 0; i < tmp; i++)
			a[i] += j * (cp + 1);
		for (int i = tmp; i < 10; i++)
			a[i] += j * cp;
		a[tmp] += n % j + 1;
		cp = cp * 10 + (j == lg ? tmp - 1 : tmp);
	}

	for (int i = 0; i < 10; i++)
		cout << a[i] << endl;

	return 0;
}