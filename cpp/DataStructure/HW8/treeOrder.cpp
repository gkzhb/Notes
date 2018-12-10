// SPOJ, Tree order
// 寻找根节点的左子女，以将三个序列划分为量大部分，利用递归进行判断

#include<iostream>
#include<vector>
using namespace std;

bool judge(int *a, int *b, int *c, int len)
{
	if (len == 1)
		if (*a != *b || *a != *c)
			return false;
		else
			return true;
	int x = a[0], i;
	if (x != b[len - 1])
		return false;
	i = 0;
	while(i < len && c[i] != x)
		i++;
	if (i == len || (0 != i && !judge(a + 1, b, c, i)))
		return false;
	if (i + 1 < len && !judge(a + i + 1, b + i, c + i + 1, len - 1 - i))
		return false;

	return true;
}

int main()
{
	int n, x, i, *a, *b, *c;
	cin >> n;
	a = new int[n];
	b = new int[n];
	c = new int[n];
	for(i = 0; i < n; i++)
	{
		cin >> x;
		a[i] = x;
	}
	for(i = 0; i < n; i++)
	{
		cin >> x;
		b[i] = x;
	}
	for(i = 0; i < n; i++)
	{
		cin >> x;
		c[i] = x;
	}
	if (judge(a, b, c, n))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	delete []a;
	delete []b;
	delete []c;

	return 0;
}
