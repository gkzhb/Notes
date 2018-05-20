#include"Student_info.h"
#include<iostream>
Student_info::Student_info() :midterm(0), final(0)
{

}

Student_info::Student_info(std::istream& is)
{
	read(is);
}

bool compare(const Student_info&x, const Student_info&y)
{
	return x.name() < y.name();
}