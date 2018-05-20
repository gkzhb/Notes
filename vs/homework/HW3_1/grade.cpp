#include"grade.h"
#include<vector>
#include"Student_info.h"
#include"median.h"
#include<iostream>

typedef std::vector<double>::iterator iter;
typedef std::string::size_type size_s;
typedef std::list<Student>::iterator iter_s;
typedef std::list<Student>::const_iterator citer_s;

void cal(std::list<Student> &x)
{
	for(iter_s i = x.begin();i!=x.end();i++)
	{
		try
		{
			i->total=0.4*i->final+0.2*i->mid+0.4*median(i->hw);	//计算总成绩
			if (i->hw.empty())
				throw std::domain_error("Empty Vector!");
		}
		catch (std::domain_error)
		{
			std::cout << i->name << " has done no homework" << std::endl;	//输出从未写过作业的学生
		}
	}
}
