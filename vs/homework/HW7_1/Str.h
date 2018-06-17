#ifndef GUARD_Str_h
#define GUARD_Str_h

#include"Vec.h"
#include<algorithm>
#include<iostream>
#include<iterator>

class Str 
{
	friend std::istream& operator>>(std::istream&, Str&);

public:
	typedef typename Vec<char>::size_type size_type;		// Str长度类型

	Str() {}
	Str(size_type n, char c) :data(n, c) {}					// 构造n个字符c构成的字符串
	Str(const char* cp) { std::copy(cp, cp + std::strlen(cp), std::back_inserter(data)); }	// char数组构造字符串
	template<class In> Str(In b, In e) { std::copy(b, e, std::back_inserter(data));	}	// 迭代器区间[b,e)构造字符串

	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }

	size_type size() const { return data.size(); }		// Str长度

	Str operator+=(const Str& s)
	{
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

private:
	Vec<char> data;			// 字符串数据
};

std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);
#endif