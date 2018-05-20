#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <vector>
#include <list>
#include <string>
class Student_info
{
public:
	Student_info();
	Student_info(std::istream&);
	std::string name() const { return n; }
	bool valid()	const { return !hw.empty(); }
	std::istream& read(std::istream&);
	double grade() const;
private:
	std::string n;
	double mid, final,total;
	std::vector<double> hw;
};

bool cmp(const Student_info &a, const Student_info &b);	//按总成绩比较
bool compare(const Student_info &a, const Student_info &b);	//按姓名比较
void output(const std::list<Student_info> &x,const std::string::size_type max);

#endif