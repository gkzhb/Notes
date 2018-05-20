#include <iostream>
#include "median.h"
#include "Student_info.h"
Student_info::Student_info() :mid(0), final(0)
{

}

Student_info::Student_info(std::istream& is)
{
	read(is);
}

double Student_info::grade() const
{
	return total;
}

bool compare(const Student_info&x, const Student_info&y)
{
	return x.name() < y.name();
}

std::istream &Student_info::read(std::istream &is)//读入Student信息
{
	if (std::cin>>n>> mid >> final)//读入姓名、期中、期末成绩，并计算总成绩
	{
		hw.clear();
		double y;
		while (std::cin>>y)					//读入平时作业成绩
			hw.push_back(y);
		std::cin.clear();
		try
		{
			total = 0.4*final + 0.2*mid + 0.4*median(hw);	//计算总成绩
			if (hw.empty())
				throw std::domain_error("Empty Vector!");
		}
		catch (std::domain_error)
		{
			std::cout << name << " has done no homework" << std::endl;	//输出从未写过作业的学生
		}
	}
	return std::cin;
}

bool cmp(const Student_info &a, const Student_info &b)//比较学生总成绩
{
	return a.grade() > b.grade();
}

bool compare(const Student_info &a, const Student_info &b)	//按姓名比较
{
	return a.name <= b.name;
}

typedef std::vector<double>::iterator iter;
typedef std::string::size_type size_s;
typedef std::list<Student_info>::iterator iter_s;
typedef std::list<Student_info>::const_iterator citer_s;


void output(const std::list<Student_info> &x,const std::string::size_type max)//输出班级学生信息
{
	std::streamsize prec = std::cout.precision(3);
	for (citer_s i = x.begin(); i != x.end(); i++)
		std::cout << i->name << std::string(max - i->name().size(), ' ') << i->grade() << std::endl;	//输出姓名和总成绩
	std::cout.precision(prec);
}