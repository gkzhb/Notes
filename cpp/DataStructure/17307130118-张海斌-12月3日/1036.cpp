// Online Judeg, 1036
// 对于 n 个节点的二叉树，其形状有 (2n)!/((n + 1)! * n!) 种

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<unsigned int>::const_iterator citer;

class BigNum		// 很大的正整数
{
public:
	BigNum(int x = 0)
	{
		while (x)
		{
			data.push_back(x % 1000);
			x /= 1000;
		}
		if (data.empty())
			data.push_back(0);
	}

	friend BigNum operator*(const BigNum &x, int y)
	{
		BigNum ret(0);
		unsigned int i = 0, j, t;
		while (i < x.data.size())
		{
			t = x.data[i] * y;
			for (j = i; 0 != t; j++)
			{
				if (ret.data.size() == j)
					ret.data.push_back(t % 1000);
				else
				{
					ret.data[j] += t % 1000;
					t += ret.data[j] / 1000 * 1000;
					ret.data[j] %= 1000;
				}
				t /= 1000;
			}
			if (ret.data.size() == i)
				ret.data.push_back(0);
			i++;
		}
		return ret;
	}

	friend BigNum operator/(const BigNum &x, int y)
	{
		vector<unsigned int> a;
		int i = x.data.size(), t = 0;
		do
		{
			i--;
			t = t * 1000 + x.data[i];
			if (t >= y)
			{
				a.push_back(t / y);
				t %= y;
			}
			else
				a.push_back(0);
		} while(0 != i);
		t = 0;
		unsigned len = a.size() - 1;
		while(t < len && a[t] == 0)
			t++;
		i = len - 1;
		BigNum ret(a[len]);
		while (i >= t)
			ret.data.push_back(a[i--]);
		return ret;
	}
	
	friend ostream &operator<<(ostream &out, const BigNum &x)
	{
		if (1 == x.data.size())
		{
			out << x.data[0];
			return out;
		}
		citer i = x.data.end() - 1;
		streamsize sz = out.width();
		char prev = out.fill();
		out << *(i--);
		out.width(3);
		out.fill('0');
		for (; i != x.data.begin(); i--)
			out << setw(3) << *i;
		out << setw(3) << *i;
		out.width(sz);
		out.fill(prev);
		return out;
	}

private:
	vector<unsigned int> data;
};

int main()
{
	int n;
	BigNum ans(1);
	cin >> n;
	n--;
	if (0 == n)
	{
		cout << '1' << endl;
		return 0;
	}
	for (int i = n + 2; i < n * 2 + 1; i++)
		ans = ans * i;
	for (int i = 2; i < n + 1; i++)
		ans = ans / i;

	cout << ans;
	return 0;
}

// 参考：https://blog.csdn.net/adminabcd/article/details/46672759
