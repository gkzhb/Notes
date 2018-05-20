#ifndef GUARD_grade_h
#define GUARD_grade_h

// 'grade.h'
//#include <vector>
#include <string>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const Vec<double>&);
const std::string &letter_grade(double, double, const Vec<double>&);	// added; 计算成绩等级字母

#endif

