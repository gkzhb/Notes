#ifndef GUARD_BigNum_h
#define GUARD_BigNum_h

#include <vector>

class BigNum
{
public:
	typedef std::vector<short>::size_type size_type;
	BigNum():data(2,0) {}		// 默认初始化为0
	BigNum(int x);				// 用int类型初始化
	size_type size() const { return data.size() - 1; }

private:
	std::vector<short> data;	// 第一个数据记录正负
};

#endif