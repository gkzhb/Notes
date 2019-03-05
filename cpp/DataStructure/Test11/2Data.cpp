#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int n, m, remain, i;
	long long max = 1ll << 40, min = 0, mid, ret, vol;
	long long a[100050];
	while (1)
	{
		// cin >> n >> m;
		max = 1ll << 62, min = 0;
		n = rand() % 10000 + 10;
		m = rand() % n + 1;
		for (i = 0; i < n; i++)
			// cin >> a[i];
			a[i] = rand() % 1000000000 + 1;

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
		mid = ret;
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
		{
			cout << "No" << endl;
			cout << n << ' ' << m << endl;
			for (i = 0; i < n; i++)
				cout << a[i] << ' ';
			cout << endl;
			cout << ret << endl;
			break;
		}
	}

	return 0;
}
