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
	bool leap_year() const;		// �ж��Ƿ�����
	bool valid() const;

	void add_year();		// ����1��
	void add_month();		// ����1��
	void add_day();		// ����1��

private:
	int y, m, d;	// ������
};

bool compare(const Date &a, const Date &b);	//�Ƚ��Ƿ�a���ڸ���
int inteval(Date a, Date b);
std::ostream &output(const Date &a,std::ostream &out);		// ��ӡ����

#endif