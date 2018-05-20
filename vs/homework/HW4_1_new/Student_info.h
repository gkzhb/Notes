#ifndef GUARD_Student_info
#define GUARD_Student_info

// 'Student_info.h' header file
#include <iostream>
#include <string>
#include <vector>
class Student_info
{
public:
	Student_info();
	Student_info(std::istream&);
	std::string name() const { return n; }
	bool valid()	const { return !homework.empty(); }
	std::istream& read(std::istream&);
	double grade() const;
private:
	std::string n;		// 姓名
	double midterm, final;	// 期中、期末成绩
	std::vector<double> homework;	// 作业成绩
};

bool compare(const Student_info&, const Student_info&);		// 按姓名比较
std::istream& read_hw(std::istream&, std::vector<double>&);		// 读入作业
#endif

