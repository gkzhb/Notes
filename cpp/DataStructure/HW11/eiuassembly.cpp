// SPOJ, EIUASSEMBLY - Assembly line
// 对流水线生产效率进行二分搜索，从而寻找到最高生产效率

#include <iostream>

using namespace std;


int main()
{
	long long n, m, t, i, max, min, mid, remain, ans;
	int a[100050], b[100050];
	cin >> t;
	while(t)
	{
		cin >> n >> m;
		min = -1;
		max = 1ll << 40;
		for(i = 0; i < n; i++)
		{	
			cin >> a[i] >> b[i];
			if (min == -1 || a[i] < min)
				min = a[i];
		}
		ans = 0;
		while (min <= max)
		{
			remain = m;
			mid = (min + max) / 2;
			for (i = 0; i < n && remain >= 0; i++)
				if (a[i] < mid)
					remain -= 1ll * (mid - a[i]) * 1ll * b[i];
			if (remain >= 0)
			{
				ans = mid;
				min = mid + 1;
			}
			else
				max = mid - 1;
		}
		
		cout << ans << endl;
		t--;
	}
	return 0;
}


// 参考资料：
// https://github.com/tr0j4n034/SPOJ/blob/master/EIUASSEMBLY.cpp
