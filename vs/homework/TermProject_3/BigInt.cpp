#include"BigInt.h"
#include<cctype>

BigInt::BigInt(int x)
{
	if (x < 0)
	{
		data.push_back(1);
		x = -x;
	}
	else
		data.push_back(0);
	if (x == 0)
		data.push_back(0);
	else
		while (x)
		{
			data.push_back(x % 10);
			x /= 10;
		}
}

int abscom(const BigInt& x, const BigInt& y)
{
	if (x.data.size() != y.data.size())
		if (x.data.size() > y.data.size())
			return 1;
		else
			return -1;
	else
	{
		BigInt::size_type i = x.data.size()-1;
		while (i&&x.data[i] == y.data[i])
			i--;
		if (0 == i)
			return 0;
		else
			if ((int)x.data[i] - (int)y.data[i] > 0)
				return 1;
			else
				return -1;
	}
}

bool operator>(const BigInt& x, const BigInt& y)
{
	if (x.data[0] != y.data[0])		// 判断x y正负号是否相同
		if (x.data[0])
			return false;
		else
			return true;
	else
	{ 
		int p = abscom(x, y);
		if ((x.data[0] && -1 == p) || (!x.data[0] && 1 == p))
			return true;
		else
			return false;
	}
}
bool operator==(const BigInt& x, const BigInt& y)
{
	return x.data == y.data;
}
bool operator!=(const BigInt& x, const BigInt& y)
{
	return !(x == y);
}
bool operator>=(const BigInt& x, const BigInt& y)
{
	return x == y || x > y;
}
bool operator<(const BigInt& x, const BigInt& y)
{
	return !(x >= y);
}
bool operator<=(const BigInt& x, const BigInt& y)
{
	return !(x > y);
}

std::istream& operator>>(std::istream& is, BigInt &x)
{
	char c;
	std::vector<schar> tmp;	// 顺序记录数据
	x.data.clear();
	do is.get(c);
	while (c != '-' && !isdigit(c));
	x.data.push_back('-'==c?1:0);
	if (!isdigit(c))
		is.get(c);
	do
	{
		tmp.push_back(c-'0');
		is.get(c);
	} while (isdigit(c));
	if (is)
		is.unget();
	for (std::vector<schar>::reverse_iterator i = tmp.rbegin(); i != tmp.rend(); ++i)
		x.data.push_back(*i);

	while (x.data.size() > 2 && *(x.data.end() - 1) == 0)
		x.data.pop_back();
	return is;
}

std::ostream& operator<<(std::ostream& os, const BigInt &x)
{
	if (x.data[0])
		os << '-';
	for (std::vector<schar>::const_reverse_iterator i = x.data.rbegin(); i != --x.data.rend(); ++i)
		os << (int)*i;
	return os;
}

BigInt absv(const BigInt& v)
{
	if (v.data[0])
	{
		BigInt tmp = v;
		tmp.data[0] = 0;
		return tmp;
	}
	else
		return v;
}

BigInt add(const BigInt& x, const BigInt& y)
{
	schar c = x[1] + y[1], p = c > 9 ? 1 : 0;
	BigInt::size_type i = 2, max = x.data.size() > y.data.size() ? x.data.size() : y.data.size();
	BigInt ans;
	ans.data[1] = c % 10;
	while (i < max||1 == p)
	{
		c = x[i] + y[i] + p;
		ans.data.push_back(c % 10);
		if (c > 9)
			p = 1;
		else
			p = 0;
		i++;
	}
	return ans;
}

BigInt subtract(const BigInt& x, const BigInt& y)
{
	schar c = x[1] - y[1], p = c >= 0 ? 0 : 1;
	BigInt::size_type i = 2, max = x.data.size();
	BigInt ans;
	if (p)
		c = c + 10;
	ans.data[1] = c;
	while (i < max)
	{
		c = x[i] - y[i] - p;
		if (c < 0)
		{
			c = c + 10;
			p = 1;
		}
		else
			p = 0;
		ans.data.push_back(c);
		i++;
	}
	while (ans.data[--i] == 0)
		ans.data.pop_back();
	return ans;
}

BigInt operator+(const BigInt& x, const BigInt& y)
{
	if (x.data[0] == y.data[0])
	{									// x y 同号相加
		BigInt ans(add(x,y));
		ans.data[0] = x.data[0];
		return ans;
	}
	else
	{									// x y 异号相加
		int p = abscom(x, y);
		if (p == 0)						
			return 0;					// x y 绝对值相等
		else
			if (1 == p)
			{							// x 绝对值大
				BigInt ans = subtract(x, y);
				ans.data[0] = x.data[0];
				return ans;
			}
			else
			{							// y 绝对值大
				BigInt ans = subtract(y, x);
				ans.data[0] = y.data[0];
				return ans;
			}
	}
}

BigInt operator-(const BigInt& x, const BigInt& y)
{
	BigInt tmp(y);
	tmp.data[0] = tmp.data[0] ? 0 : 1;
	return x + tmp;
}