#include<iostream>
#include"Student_info.h"
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>

int main(void)
{
	std::vector<Student_info> students;
	Student_info record;
	std::string::size_type maxlen = 0;

	//read and store the data
	while (record.read(std::cin))
	{
		maxlen = std::max(maxlen, record.name().size());
		students.push_back(record);
	}
	
	//alphabetize the student records
	sort(students.begin(), students.end(), compare);

	//write the names and grades
	for (std::vector<Student_info>::size_type i = 0; i != students.size(); i++)
	{
		std::cout << students[i].name() << std::string(maxlen + 1 - students[i].name.size(), ' ');
		try
		{
			double final_grade = students[i].grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(((std::streamsize)3)) << final_grade << std::setprecision(prec) << std::endl;
		}
		catch (std::domain_error e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}