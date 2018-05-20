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

std::istream &Student_info::read(std::istream &is)//����Student��Ϣ
{
	if (std::cin>>n>> mid >> final)//�������������С���ĩ�ɼ����������ܳɼ�
	{
		hw.clear();
		double y;
		while (std::cin>>y)					//����ƽʱ��ҵ�ɼ�
			hw.push_back(y);
		std::cin.clear();
		try
		{
			total = 0.4*final + 0.2*mid + 0.4*median(hw);	//�����ܳɼ�
			if (hw.empty())
				throw std::domain_error("Empty Vector!");
		}
		catch (std::domain_error)
		{
			std::cout << name << " has done no homework" << std::endl;	//�����δд����ҵ��ѧ��
		}
	}
	return std::cin;
}

bool cmp(const Student_info &a, const Student_info &b)//�Ƚ�ѧ���ܳɼ�
{
	return a.grade() > b.grade();
}

bool compare(const Student_info &a, const Student_info &b)	//�������Ƚ�
{
	return a.name <= b.name;
}

typedef std::vector<double>::iterator iter;
typedef std::string::size_type size_s;
typedef std::list<Student_info>::iterator iter_s;
typedef std::list<Student_info>::const_iterator citer_s;


void output(const std::list<Student_info> &x,const std::string::size_type max)//����༶ѧ����Ϣ
{
	std::streamsize prec = std::cout.precision(3);
	for (citer_s i = x.begin(); i != x.end(); i++)
		std::cout << i->name << std::string(max - i->name().size(), ' ') << i->grade() << std::endl;	//����������ܳɼ�
	std::cout.precision(prec);
}