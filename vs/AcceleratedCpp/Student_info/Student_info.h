#ifndef GUARD_Student_info_h
#define GUARD_Studnet_info_h
//#pragma once

#include<vector>
#include<iostream>
#include<string>
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
	std::string n;
	double midterm, final;
	std::vector<double> homework;
};
bool compare(const Student_info&, const Student_info&);
#endif