#ifndef GUARD_BigInt_h
#define GUARD_BigInt_h

#include<vector>
#include<iostream>
#include<string>

#define schar signed char

class BigInt		// �ܴ������
{
	friend std::istream& operator>>(std::istream& is, BigInt &x);
	friend std::ostream& operator<<(std::ostream& os, const BigInt &x);
	friend bool operator==(const BigInt& x, const BigInt& y);
	friend bool operator>(const BigInt& x, const BigInt& y);
	friend BigInt absv(const BigInt&);
	friend BigInt operator+(const BigInt&, const BigInt&);
	friend BigInt operator-(const BigInt&, const BigInt&);
	friend int abscom(const BigInt& x, const BigInt& y);	// �Ƚ�x y����ֵ 1:x�� 0:��� -1:y��
	friend BigInt add(const BigInt& x, const BigInt& y);		// x y����ֵ���
	friend BigInt subtract(const BigInt& x, const BigInt& y);	// x y����ֵ����������жϵ���Ϊ|x|>|y|��

public:
	typedef std::vector<schar>::size_type size_type;
	
	BigInt() :data(2, 0) {}	// Ĭ�ϳ�ʼ��Ϊ0
	BigInt(size_type n, unsigned int v) :data(n + 1, v) { data[0] = 0; }	// ��nλv���ֳ�ʼ��
	BigInt(int x);			// ��int���ͳ�ʼ��
	BigInt(const BigInt& x) { data = x.data; }
	
	size_type size() const { return data.size()-1; }		// ���ݵ�λ��
	BigInt operator-()										// ���ظ���
	{
		data[0] = data[0] ? 0 : 1;
		return *this;
	}

private:
	std::vector<schar> data;	// ��һ�����ݼ�¼����
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

BigInt absv(const BigInt&);		// ����ֵ����


BigInt add(const BigInt& x, const BigInt& y);		// x y����ֵ���
BigInt subtract(const BigInt& x, const BigInt& y);	// x y����ֵ����������жϵ���Ϊ|x|>|y|��

#endif