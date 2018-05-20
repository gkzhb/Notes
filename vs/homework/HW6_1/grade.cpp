#include <stdexcept>
//#include <vector>
#include <string>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;


// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const Vec<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

// added; 计算学生的成绩字母等级
const std::string &letter_grade(double midterm, double final, const Vec<double>& homework)
{
	static const double Standard[] = { 90,85,82,78,75,71,66,62,60 };
	static const std::string alf_grade[]={"A","A-","B+","B","B-","C+","C","C-","D","F" };
	int i = 0;
	double total = grade(midterm, final, homework);
	while (total < Standard[i]&&i<9)
		i++;
	return alf_grade[i];
}