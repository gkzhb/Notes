#ifndef GUARD_BigInt_h
#define GUARD_BigInt_h

#include<vector>
#include<iostream>

class BigInt		// �ܴ������
{
	friend std::istream& operator>>(std::istream& is, BigInt &x);
	friend std::ostream& operator<<(std::ostream& os, const BigInt &x);
	friend bool operator==(const BigInt x, const BigInt y);
	friend bool operator>(const BigInt x, const BigInt y);
	friend BigInt absv(const BigInt&);

public:
	typedef std::vector<char>::size_type size_type;
	
	BigInt() :data(2, 0) {}	// Ĭ�ϳ�ʼ��Ϊ0
	BigInt(size_type n, unsigned int v) :data(n + 1, v) { data[0] = 0; }	// ��nλv���ֳ�ʼ��
	BigInt(int x);			// ��int���ͳ�ʼ��
	
	size_type size() const { return data.size()-1; }		// ���ݵ�λ��
	BigInt operator-()
	{
		data[0] = data[0] ? 0 : 1;
		return *this;
	}

private:
	std::vector<char> data;	// ��һ�����ݼ�¼����
};

std::istream& operator>>(std::istream& is, BigInt &x);
std::ostream& operator<<(std::ostream& os, const BigInt &x);

bool operator==(const BigInt x, const BigInt y);
bool operator!=(const BigInt x, const BigInt y);
bool operator>(const BigInt x, const BigInt y);
bool operator>=(const BigInt x, const BigInt y);
bool operator<(const BigInt x, const BigInt y);
bool operator<=(const BigInt x, const BigInt y);

BigInt absv(const BigInt&);		// ����ֵ����

#endif