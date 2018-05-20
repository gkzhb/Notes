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
	size_s max = 0;							//�ַ������� ������󳤶�
	while (read(datum))						 //��������
	{
		max = max > datum.name.size() ? max : datum.name.size();
		data.push_back(datum);
	}
	max++;
	cal(data);								//�����ܳɼ�
	sort(data.begin(), data.end(), cmp_name);//����������
	sort(data.begin(), data.end(), cmp);	//���ܳɼ�����
	output(data,max); 						//����ܳɼ�

	return 0;
}