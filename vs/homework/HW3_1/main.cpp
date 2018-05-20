#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <ios>
#include <string>
#include <stdexcept>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include "fails_list.h"

typedef std::vector<double>::iterator iter;
typedef std::string::size_type size_s;
typedef std::list<Student>::iterator iter_s;
typedef std::list<Student>::const_iterator citer_s;

int main(void)
{
	std::list<Student> data,fails;
	Student datum;
	size_s max = 0;							//字符串长度 姓名最大长度
	while (read(datum))						 //读入数据
	{
		max = max > datum.name.size() ? max : datum.name.size();
		data.push_back(datum);
	}
	max++;
	cal(data);								//计算总成绩
	
	fails = extract_fails(data);			//分离出成绩不及格的学生名单
	data.sort(cmp_name);					//按姓名排序
	fails.sort(cmp_name);
	data.sort(cmp);							//按总成绩排序
	fails.sort(cmp);
	std::cout << "Passing student records:" << std::endl;
	output(data,max); 						//输出及格学生总成绩
	std::cout << "Failing student records:" << std::endl;
	output(fails, max);						//输出不及格学生总成绩

	return 0;
}