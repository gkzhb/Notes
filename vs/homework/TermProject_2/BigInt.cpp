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
	while (x)
	{
		data.push_back(x % 10);
		x /= 10;
	}
}

bool operator>(const BigInt x, const BigInt y)
{
	if (x.data[0] != y.data[0])		// 判断x y正负号是否相同
		if (x.data[0])
			return false;
		else
			return true;
	else
	{ 
		bool p = false;		// 比较x y绝对值大小结果
		if (x.data.size() != y.data.size())
			if (x.data.size() > y.data.size())
				p = true;
			else
				p = false;
		else
			for (BigInt::size_type i = x.data.size()-1; i; --i)
				if (x.data[i] != y.data[i])
				{	
					if (x.data[i] > y.data[i])				
						p = true;					
					else					
						p = false;
					break;
				}
		return x.data[0] ? !p : p;
	}
}
bool operator==(const BigInt x, const BigInt y)
{
	return x.data == y.data;
}
bool operator!=(const BigInt x, const BigInt y)
{
	return !(x == y);
}
bool operator>=(const BigInt x, const BigInt y)
{
	return x == y || x > y;
}
bool operator<(const BigInt x, const BigInt y)
{
	return !(x >= y);
}
bool operator<=(const BigInt x, const BigInt y)
{
	return !(x > y);
}

std::istream& operator>>(std::istream& is, BigInt &x)
{
	char c;
	std::vector<char> tmp;	// 顺序记录数据
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
	for (std::vector<char>::reverse_iterator i = tmp.rbegin(); i != tmp.rend(); ++i)
		x.data.push_back(*i);

	return is;
}

std::ostream& operator<<(std::ostream& os, const BigInt &x)
{
	if (x.data[0])
		os << '-';
	for (std::vector<char>::const_reverse_iterator i = x.data.rbegin(); i != --x.data.rend(); ++i)
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