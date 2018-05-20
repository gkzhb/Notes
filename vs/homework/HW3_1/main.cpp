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
	size_s max = 0;							//�ַ������� ������󳤶�
	while (read(datum))						 //��������
	{
		max = max > datum.name.size() ? max : datum.name.size();
		data.push_back(datum);
	}
	max++;
	cal(data);								//�����ܳɼ�
	
	fails = extract_fails(data);			//������ɼ��������ѧ������
	data.sort(cmp_name);					//����������
	fails.sort(cmp_name);
	data.sort(cmp);							//���ܳɼ�����
	fails.sort(cmp);
	std::cout << "Passing student records:" << std::endl;
	output(data,max); 						//�������ѧ���ܳɼ�
	std::cout << "Failing student records:" << std::endl;
	output(fails, max);						//���������ѧ���ܳɼ�

	return 0;
}