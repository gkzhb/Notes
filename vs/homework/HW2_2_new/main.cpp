#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <string>
#include <stdexcept>
#include "Student_info.h"
#include "grade.h"
#include "median.h"

typedef std::vector<double>::iterator iter;
typedef std::string::size_type size_s;
typedef std::vector<Student>::iterator iter_s;
typedef std::vector<Student>::const_iterator citer_s;

int main(void)
{
	std::vector<Student> data;
	Student datum;
	size_s max = 0;							//字符串长度 姓名最大长度
	while (read(datum))						 //读入数据
	{
		max = max > datum.name.size() ? max : datum.name.size();
		data.push_back(datum);
	}
	max++;
	cal(data);								//计算总成绩
	sort(data.begin(), data.end(), cmp_name);//按姓名排序
	sort(data.begin(), data.end(), cmp);	//按总成绩排序
	output(data,max); 						//输出总成绩

	return 0;
}