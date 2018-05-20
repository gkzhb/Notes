#include <iostream>
#include "Student_info.h"

typedef std::vector<double>::iterator iter;
typedef std::string::size_type size_s;
typedef std::list<Student>::iterator iter_s;
typedef std::list<Student>::const_iterator citer_s;

std::istream &read(Student &x)//读入Student信息
{
	if (std::cin>>x.name>> x.mid >> x.final)//读入姓名、期中、期末成绩
	{
		x.hw.clear();
		double y;
		while (std::cin>>y)					//读入平时作业成绩
			x.hw.push_back(y);
		std::cin.clear();
	}
	return std::cin;
}

bool cmp(const Student &a, const Student &b)//比较学生总成绩
{
	return a.total > b.total;
}

bool cmp_name(const Student &a, const Student &b)	//按姓名比较
{
	return a.name <= b.name;
}

void output(const std::list<Student> &x,const std::string::size_type max)//输出班级学生信息
{
	std::streamsize prec = std::cout.precision(3);
	for (citer_s i = x.begin(); i != x.end(); i++)
		std::cout << i->name << std::string(max - i->name.size(), ' ') << i->total << std::endl;	//输出姓名和总成绩
	std::cout.precision(prec);
}