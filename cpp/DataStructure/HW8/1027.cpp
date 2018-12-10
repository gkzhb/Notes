// Online Judge, 1027
// dist(k, k + 1) 的值可分为 k 的二进制个位是 0 还是 1 两种情况分别计算

#include <iostream>

using namespace std;

int dist(int k)
{
	int ret = 0;
	if (k & 0x1 == 1)
	{
		int i = (k ^ (k + 1)) >> 1;
		while(i & 1 == 1)
		{
			ret++;
			i >>= 1;
		}
		ret--;
	}
	else
	{
		k >>= 1;
		while((k & 1) == 0)
		{
			ret++;
			k >>= 1;
		}
	}
	return ret;
}

int main()
{
	int l, r, ans = 0;
	cin >> l >> r;
	for(int i = l; i < r; i++)
		ans += dist(i);
	cout << ans << endl;
	return 0;
}
