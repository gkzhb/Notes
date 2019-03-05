// 多线程

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

	int n, m, remain, i;
	long long max = 1ll << 62, min = 0, mid, ret, vol;
	long long a[100050];

	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> a[i];

	while (max >= min)
	{
		mid = (max + min) >> 1;
		remain = m;
		vol = 0;
		for (i = 0; i < n && remain > 0; i++)
			if (a[i] + vol <= mid)
				vol += a[i];
			else
			{
				remain--;
				if (a[i] > mid)
					break;
				vol = a[i];
			}
		if (i < n || remain == 0)
			min = mid + 1;
		else
		{
			ret = mid;
			max = mid - 1;
		}
	}

	cout << ret << endl;

	return 0;
}