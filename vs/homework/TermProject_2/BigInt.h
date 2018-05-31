#ifndef GUARD_BigInt_h
#define GUARD_BigInt_h

#include<vector>
#include<iostream>

class BigInt		// 很大的整数
{
	friend std::istream& operator>>(std::istream& is, BigInt &x);
	friend std::ostream& operator<<(std::ostream& os, const BigInt &x);
	friend bool operator==(const BigInt x, const BigInt y);
	friend bool operator>(const BigInt x, const BigInt y);
	friend BigInt absv(const BigInt&);

public:
	typedef std::vector<char>::size_type size_type;
	
	BigInt() :data(2, 0) {}	// 默认初始化为0
	BigInt(size_type n, unsigned int v) :data(n + 1, v) { data[0] = 0; }	// 用n位v数字初始化
	BigInt(int x);			// 用int类型初始化
	
	size_type size() const { return data.size()-1; }		// 数据的位数
	BigInt operator-()
	{
		data[0] = data[0] ? 0 : 1;
		return *this;
	}

private:
	std::vector<char> data;	// 第一个数据记录正负
};

std::istream& operator>>(std::istream& is, BigInt &x);
std::ostream& operator<<(std::ostream& os, const BigInt &x);

bool operator==(const BigInt x, const BigInt y);
bool operator!=(const BigInt x, const BigInt y);
bool operator>(const BigInt x, const BigInt y);
bool operator>=(const BigInt x, const BigInt y);
bool operator<(const BigInt x, const BigInt y);
bool operator<=(const BigInt x, const BigInt y);

BigInt absv(const BigInt&);		// 绝对值函数

#endif