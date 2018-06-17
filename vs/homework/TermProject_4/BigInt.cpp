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
	return judge(x.data.begin() + 1, x.data.end(), y);
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

void BigInt::copy(const_iterator begin, const_iterator end)
{
	data.clear();
	data.push_back(0);
	for (const_iterator i = begin; i < end; ++i)
		data.push_back(*i);
}

BigInt operator*(const BigInt&x, const BigInt& y)
{
	BigInt ans;
	if (0 == x || 0 == y)
		return 0;
	if (x.data[0] == y.data[0])			// 计算符号
		ans.data[0]=0;
	else
		ans.data[0]=1;
	BigInt::size_type i = 1, j = 1, k, m = x.data.size(), n = y.data.size();
	schar p, q = 0;		// p 该位乘积	q 进位数
	while (i < m || q>0)
	{
		k = i + j - 1;
		p = x[i] * y[j] + q;
		q = p / 10;
		if (k == ans.data.size())
			ans.data.push_back(p % 10);
		else
		{
			ans.data[k] += p % 10;
			if (ans.data[k] > 9)
			{
				q += ans.data[k] / 10;
				ans.data[k] %= 10;
			}
		}

		if (++j >= n && 0 == q)
		{
			j = 1;
			i++;
		}
	}
	i = ans.data.size();
	while (0 == ans.data[--i]&&i>1)
		ans.data.pop_back();
	return ans;
}

int judge(BigInt::const_iterator b,BigInt::const_iterator e,const BigInt& x)
{
	BigInt::const_iterator i = e, j = x.data.end() - 1;
	if (e - b > x.data.size() - 1)
		return 1;
	else
		if (e - b < x.data.size() - 1)
			return -1;
	while (--i > b&&*i == *j)
		--j;
	if (*i == *j)
		return 0;
	else
		if (*i > *j)
			return 1;
		else
			return -1;
}

BigInt operator/(const BigInt& x, const BigInt& y)
{
	return divide_BigInt(x, y).quo;
}
BigInt operator%(const BigInt& x, const BigInt& y)
{
	return divide_BigInt(x, y).rem;
}

Divide_Return divide_BigInt(const BigInt& tmp,const BigInt& y)
{
	typedef BigInt::const_iterator citer;
	typedef BigInt::iterator iter;
	int tt = abscom(tmp, y);
	if (tt<=0)
		if (-1==tt)
			return Divide_Return(0,tmp);
		else
			return Divide_Return(tmp.data[0] == y.data[0] ? 1 : -1, 0);
	if (0 == y)
		throw std::domain_error("Divide ZERO!");
	BigInt x(tmp);
	iter xb = x.data.end() - y.data.size() + 1, xe = x.data.end(), i, k;
	citer j;
	BigInt ans(x.data.size()-y.data.size()+1,0);
	schar p;

	while (xb > x.data.begin()+1 || judge(xb, xe, y)>=0)
	{
 		while (judge(xb, xe, y)>=0)
		{
			ans.data[xb - x.data.begin()] += 1;
			p = 0;
			for (i = xb, j = y.data.begin() + 1; i < xe || p; ++i)
			{
				if (j == y.data.end())
					*i -= p;
				else
					*i -= *(j++) + p;
				if (*i < 0)
				{
					p = 1;
					*i += 10;
				}
				else
					p = 0;
			}
			while (0 == *(xe - 1) && x.data.size() > 2)
			{
				if (xb == xe - 1)
					xb--;
				x.data.pop_back(); xe = x.data.end();
			}
		}
		if (xe - xb == y.data.size() - 1 && xb > x.data.begin() + 1)
			--xb;
		else
			while (xb > x.data.begin()+1 && xe - xb < y.data.size() - 1)
				--xb;
	}
	while (ans.data.size() > 2 && 0 == *(ans.data.end() - 1))
		ans.data.pop_back();
	if (tmp.data[0] != y.data[0])
		ans.data[0] = 1;
	if (x.data.size() == 2 && x.data[1] == 0)
		x.data[0] = 0;
	return Divide_Return(ans,x);
}