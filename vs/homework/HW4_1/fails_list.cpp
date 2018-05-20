#include "Student_info.h"
#include "fails_list.h"

typedef std::list<Student_info>::iterator iter_s;

bool npass(iter_s x)			// 判断学生成绩是否不及格
{
	return x->final < 60.0;
}

std::list<Student_info> extract_fails(std::list<Student_info> &x)
{
	std::list<Student_info> fails;
	iter_s i = x.begin();
	while (i != x.end())
		if (npass(i))		// 判断学生成绩是否不及格
		{							// 学生成绩不及格
			fails.push_back(*i);
			i = x.erase(i);
		}
		else
			i++;					// 学生成绩及格，保留
	return fails;
}