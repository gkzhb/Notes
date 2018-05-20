#ifndef GUARD_Student_info
#define GUARD_Student_info

// 'Student_info.h' header file
#include <iostream>
#include <string>
#include "Vec.h"
class Student_info
{
public:
	Student_info();
	Student_info(std::istream&);
	std::string name() const { return n; }
	bool valid()	const { return !homework.empty(); }
	std::istream& read(std::istream&);
	double grade() const;
	const std::string& letter_grade() const;
private:
	std::string n;		// ����
	double midterm, final;	// ���С���ĩ�ɼ�
	Vec<double> homework;	// ��ҵ�ɼ�
};

bool compare(const Student_info&, const Student_info&);		// �������Ƚ�
std::istream& read_hw(std::istream&, Vec<double>&);		// ������ҵ
#endif

