#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y)
{
	while (0 != y)
	{
		x %= y;
		x = x ^ y;
		y = x ^ y;
		x = x ^ y;
	}
	return x;
}

int main()
{
	int n, i, max, count, x;
	cin >> n;
	cin >> max;
	count = max;
	for(i = 1; i < n; i++)
	{
		cin >> x;
		if (1 != max)
			max = gcd(max, x);
		count += x;
	}
	cout << count / max << endl;

	return 0;
}
