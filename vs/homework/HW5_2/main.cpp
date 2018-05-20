#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::cin;                       using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;   using std::streamsize;
using std::endl;                    using std::string;
using std::max;                    using std::vector;
//using namespace std;
#define random(a,b) (rand()%(b-a+1)+a)			// 生成[a,b)之间的随机数

void median_test(int n);	// 创建含n个整数的随机数组以测试median模板函数（整数范围0~100）

int main()
{
	srand((unsigned)time(NULL));
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;       // the length of the longest name
	const char *inFile = "grades.txt";
	const char *outFile = "final.txt";

	// read and store all the students' data.
	// Invariant:	`students' contains all the student records read so far
	//			`maxlen' contains the length of the longest name in `students'
	
	std::ifstream in(inFile);
	std::ofstream out(outFile);
	
	while (record.read(in)) {
		// find length of longest name
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0;
	     i != students.size(); ++i) {

		// write the name, padded on the right to `maxlen' `+' `1' characters
		cout << students[i].name()
		     << string(maxlen + 1 - students[i].name().size(), ' ');
		out << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ');

		// compute and write the grade
		try {
			const string &final_grade = students[i].letter_grade();
			cout << final_grade;
			out << final_grade;
		} catch (domain_error e) {
			cout << e.what();
			out << e.what();
		}
		cout << endl;
		out << endl;
	}

	median_test(11);

	return 0;
}

void median_test(int n)
{
	vector<int> a;
	int i;
	for (i = 0; i < n; i++)
		a.push_back(random(0, 100));
	cout << endl << "The following is the result of testing median function on array" << endl
		<< "The random array is:" << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl << "The median of the array is: " << median(a) << endl
		<< "After median function called, the array is unchanged:" << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}