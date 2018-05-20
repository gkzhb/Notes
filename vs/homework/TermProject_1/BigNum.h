#ifndef GUARD_BigNum_h
#define GUARD_BigNum_h

#include <vector>

class BigNum
{
public:
	typedef std::vector<short>::size_type size_type;
	BigNum():data(2,0) {}		// Ĭ�ϳ�ʼ��Ϊ0
	BigNum(int x);				// ��int���ͳ�ʼ��
	size_type size() const { return data.size() - 1; }

private:
	std::vector<short> data;	// ��һ�����ݼ�¼����
};

#endif