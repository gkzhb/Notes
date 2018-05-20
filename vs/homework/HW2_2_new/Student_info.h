#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <vector>
#include <string>

struct Student
{
	std::string name;
	double mid, final,total;
	std::vector<double> hw;
};

std::istream &read(Student &x);
bool cmp(const Student &a, const Student &b);	//���ܳɼ��Ƚ�
bool cmp_name(const Student &a, const Student &b);	//�������Ƚ�
void output(const std::vector<Student> &x,const std::string::size_type max);

#endif