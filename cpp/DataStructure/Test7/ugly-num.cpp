#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n, index2, index3, index5;
	long long i;
	index2 = index3 = index5 = 0;
	vector<long long> a(1, 1);
	cin >> n;
	n--;
	while (n)
	{
		if (a[index2] * 2 < a[index3] * 3)
			if (a[index2] * 2 < a[index5] * 5)
			{
				i = a[index2] * 2;
				index2++;
			}
			else
			{
				i = a[index5] * 5;
				index5++;
			}
		else
			if (a[index3] * 3 < a[index5] * 5)
			{
				i = a[index3] * 3;
				index3++;
			}
			else
			{
				i = a[index5] * 5;
				index5++;
			}
		if (i > a.back())
		{
			a.push_back(i);
			n--;
		}
	}
	cout << a.back() << endl;
	return 0;
}
