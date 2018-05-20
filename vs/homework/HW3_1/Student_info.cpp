#include <iostream>
#include "Student_info.h"

typedef std::vector<double>::iterator iter;
typedef std::string::size_type size_s;
typedef std::list<Student>::iterator iter_s;
typedef std::list<Student>::const_iterator citer_s;

std::istream &read(Student &x)//����Student��Ϣ
{
	if (std::cin>>x.name>> x.mid >> x.final)//�������������С���ĩ�ɼ�
	{
		x.hw.clear();
		double y;
		while (std::cin>>y)					//����ƽʱ��ҵ�ɼ�
			x.hw.push_back(y);
		std::cin.clear();
	}
	return std::cin;
}

bool cmp(const Student &a, const Student &b)//�Ƚ�ѧ���ܳɼ�
{
	return a.total > b.total;
}

bool cmp_name(const Student &a, const Student &b)	//�������Ƚ�
{
	return a.name <= b.name;
}

void output(const std::list<Student> &x,const std::string::size_type max)//����༶ѧ����Ϣ
{
	std::streamsize prec = std::cout.precision(3);
	for (citer_s i = x.begin(); i != x.end(); i++)
		std::cout << i->name << std::string(max - i->name.size(), ' ') << i->total << std::endl;	//����������ܳɼ�
	std::cout.precision(prec);
}