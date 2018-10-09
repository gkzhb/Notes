#include <iostream>
#include <vector>

using std::vector;
using std::istream;		using std::ostream;
typedef vector<char>::const_iterator citer;
// typedef vector<char>::iterator iter;

class BigNum		// 很大的正整数
{
public:
	BigNum(int x = 0)
	{
		while (x)
		{
			data.push_back((char)x%10);
			x /= 10;
		}
		if (data.empty())
			data.push_back(0);
	}

	friend BigNum operator*(const BigNum x, int y)
	{
		BigNum ret(0);
		unsigned int i = 0, j, k, t;
		while (i < x.data.size())
		{
			t = int(x.data[i]) * y;
			for (j = i; 0 != t; j++)
			{
				if (ret.data.size() == j)
					ret.data.push_back(char(t % 10));
				else
				{
					ret.data[j] += t % 10;
					for (k = j; ret.data[k] > 9; k++)
					{
						ret.data[k] -= 10;
						if (ret.data.size() == k + 1)
							ret.data.push_back(char(1));
						else
							ret.data[k + 1]++;
					}
				}
				t /= 10;
			}
			if (ret.data.size() == i)
				ret.data.push_back(char(0));
			i++;
		}	
		return ret;
	}
	
	friend ostream &operator<<(ostream &out, const BigNum &x)
	{
		citer i;
		for (i = x.data.end() - 1; i != x.data.begin(); i--)
			out << char(*i + '0');
		out << char(*i + '0');
		return out;
	}

private:
	vector<char> data;
};

int main(void)
{
	unsigned int t, n;
	vector<BigNum> f;
	BigNum tmp(1);
	f.push_back(tmp);
	std::cin >> t;
	for (unsigned int i = 0; i < t; i++)
	{
		std::cin >> n;
		if (n > f.size())
			for (unsigned int j = f.size(); j < n; j++)
			{
				tmp = f[j - 1] * (j + 1);
				f.push_back(tmp);
			}
		std::cout << f[n - 1] << std::endl;
	}

	return 0;
}