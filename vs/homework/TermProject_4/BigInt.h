#ifndef GUARD_BigInt_h
#define GUARD_BigInt_h

#include<vector>
#include<iostream>
#include<string>

#define schar signed char

class Divide_Return;

class BigInt		// �ܴ������
{
public:
	typedef std::vector<schar>::size_type size_type;
	typedef std::vector<schar>::iterator iterator;
	typedef std::vector<schar>::const_iterator const_iterator;

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
	friend BigInt operator*(const BigInt&x, const BigInt& y);
	friend Divide_Return divide_BigInt(const BigInt&, const BigInt&);
	friend int judge(BigInt::const_iterator b, BigInt::const_iterator e, const BigInt& x);


public:
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
		if (n < data.size())
			return data[n];
		else
			return 0;
	}
	schar operator[](size_type n) const
	{
		if (n < data.size())
			return data[n];
		else
			return 0;
	}
	void copy(const_iterator begin, const_iterator end);		//��[begin,end)���乹����ֵ��BigInt
};

class Divide_Return
{
public:
	BigInt quo, rem;	// �� ����
	Divide_Return(const BigInt&quotient, const BigInt&remainder) :quo(quotient), rem(remainder) {}
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
int judge(BigInt::const_iterator b, BigInt::const_iterator e, const BigInt& x);
BigInt operator*(const BigInt&x, const BigInt& y);
BigInt operator/(const BigInt&x, const BigInt& y);
BigInt operator%(const BigInt&x, const BigInt& y);
Divide_Return divide_BigInt(const BigInt&, const BigInt&);

#endif