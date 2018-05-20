#ifndef GUARD_Date_h
#define GUARD_Date_h

#include <iostream>

class Date
{
public:
	Date():y(0),m(0),d(0) {};
	Date(int year, int month, int day);
	Date(std::istream &in);
	int year() const {	return y;	}
	int month() const	{	return m;	}
	int day() const	{	return d;	}
	bool leap_year() const;		// 判断是否闰年
	bool valid() const;

	void add_year();		// 增加1年
	void add_month();		// 增加1月
	void add_day();		// 增加1天

private:
	int y, m, d;	// 年月日
};

bool compare(const Date &a, const Date &b);	//比较是否a日期更早
int inteval(Date a, Date b);
std::ostream &output(const Date &a,std::ostream &out);		// 打印日期

#endif