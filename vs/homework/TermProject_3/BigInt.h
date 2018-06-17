#ifndef GUARD_BigInt_h
#define GUARD_BigInt_h

#include<vector>
#include<iostream>
#include<string>

#define schar signed char

class BigInt		// 很大的整数
{
	friend std::istream& operator>>(std::istream& is, BigInt &x);
	friend std::ostream& operator<<(std::ostream& os, const BigInt &x);
	friend bool operator==(const BigInt& x, const BigInt& y);
	friend bool operator>(const BigInt& x, const BigInt& y);
	friend BigInt absv(const BigInt&);
	friend BigInt operator+(const BigInt&, const BigInt&);
	friend BigInt operator-(const BigInt&, const BigInt&);
	friend int abscom(const BigInt& x, const BigInt& y);	// 比较x y绝对值 1:x大 0:相等 -1:y大
	friend BigInt add(const BigInt& x, const BigInt& y);		// x y绝对值相加
	friend BigInt subtract(const BigInt& x, const BigInt& y);	// x y绝对值相减（不经判断地认为|x|>|y|）

public:
	typedef std::vector<schar>::size_type size_type;
	
	BigInt() :data(2, 0) {}	// 默认初始化为0
	BigInt(size_type n, unsigned int v) :data(n + 1, v) { data[0] = 0; }	// 用n位v数字初始化
	BigInt(int x);			// 用int类型初始化
	BigInt(const BigInt& x) { data = x.data; }
	
	size_type size() const { return data.size()-1; }		// 数据的位数
	BigInt operator-()										// 重载负号
	{
		data[0] = data[0] ? 0 : 1;
		return *this;
	}

private:
	std::vector<schar> data;	// 第一个数据记录正负
	schar operator[](size_type n) 
	{ 
		if (n <= size())
			return data[n];
		else
			return 0;
	}
	schar operator[](size_type n) const
	{
		if (n <= size())
			return data[n];
		else
			return 0;
	}
};

std::istream& operator>>(std::istream& is, BigInt &x);
std::ostream& operator<<(std::ostream& os, const BigInt &x);

bool operator==(const BigInt& x, const BigInt& y);
bool operator!=(const BigInt& x, const BigInt& y);
bool operator>(const BigInt& x, const BigInt& y);
bool operator>=(const BigInt& x, const BigInt& y);
bool operator<(const BigInt& x, const BigInt& y);
bool operator<=(const BigInt& x, const BigInt& y);

BigInt absv(const BigInt&);		// 绝对值函数


BigInt add(const BigInt& x, const BigInt& y);		// x y绝对值相加
BigInt subtract(const BigInt& x, const BigInt& y);	// x y绝对值相减（不经判断地认为|x|>|y|）

#endif