#include "Date.h"
#include <stdexcept>

const int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

Date::Date(int year, int month, int day)
{
	y = year; m = month; d = day;
}

Date::Date(std::istream &in)
{
	in >> y >> m >> d;
	try
	{
		if (!valid())
			throw std::domain_error("invalid data");
	}
	catch (std::domain_error e)
	{
		if (m < 1 || m>12)
			std::cout << "invalid month" << std::endl;
		else
			std::cout << "invalid day" << std::endl;
		exit(1);
	}
}

bool Date::leap_year() const
{
	return 0 == y % 100 ? 0 == y % 400 : 0 == y % 4;
}

bool Date::valid() const
{
	if (0 < m&&m < 13 && d>0)
		if (2 != m || !leap_year())
			return d <= mon[m - 1];
		else
			return d <= 29;
	else
		return false;
}

bool compare(const Date &a, const Date &b)
{
	if (a.year() != b.year())
		return a.year() < b.year();
	else
		if (a.month() != b.month())
			return a.month() < b.month();
		else
			return a.day() <= b.day();
}

void Date::add_year()
{
	y++;
	if (!valid())
		d--;
}

void Date::add_month()
{
	m++;
	if (!valid())
		if (m > 12)
		{
			y++;
			m = 1;
		}
		else
		{
			Date tmp(y, m, d);
			d = mon[m - 1];
			if (2 == m && tmp.leap_year())
				d++;
		}
}

void Date::add_day()
{
	d++;
	if (!valid())
	{
		m++; d = 1;
		if (m > 12)
		{
			y++; m = 1;
		}
	}
}

int inteval_same_year(Date a, Date b)	// 同一年计算相隔天数
{
	int days=0;
	if (a.month() == b.month())
		days= b.day() - a.day();
	else
	{
		if (b.month() - a.month() > 1)
			for (Date i(a.year(), a.month() + 1, 1); i.month() != b.month(); i.add_month())
			{
				days += mon[i.month() - 1];
				if (2 == i.month() && i.leap_year())
					days++;
			}
		days += b.day() + mon[a.month() - 1] - a.day();
	}
	return days;
}

int inteval(Date a, Date b)
{
	int days=0;
	if (!compare(a, b))
	{
		Date tmp = a;
		a = b; b = tmp;
	}
	if (a.year() == b.year())
		days = inteval_same_year(a, b);
	else
	{
		if (b.year() - a.year() > 1)
			for (Date i(a.year() + 1, 1, 1); i.year() != b.year(); i.add_year())
				days += i.leap_year() ? 366 : 365;
		Date x(a.year(), 12, 31), y(b.year(), 1, 1);
		days += inteval_same_year(a, x) + inteval_same_year(y, b) + 1;
	}
	return days;
}

std::ostream &output(const Date &a,std::ostream &out)
{
	out << a.year() << "年" << a.month() << "月" << a.day() << "日";
	return out;
}