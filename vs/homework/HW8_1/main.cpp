#include"Student_info.h"
#include<algorithm>
#include<iomanip>
#include<stdexcept>
#include<fstream>

using std::vector;		using std::string;
using std::cin;			using std::cout;
using std::endl;		using std::setprecision;
int main()
{
	vector<Student_info> students;		// �洢����
	Student_info record;				// ����ʱ��ʱ�洢����
	string::size_type maxlen = 0;		// ��¼����ֳ���
	std::ifstream infile("grades.txt");
	while (record.read(infile))			// ��ȡ����
	{
		maxlen = std::max(maxlen, record.name().size());
		students.push_back(record);
	}

	std::sort(students.begin(), students.end(), Student_info::compare);

	for (vector<Student_info>::size_type i = 0;		// ��������ͳɼ�
		i != students.size(); ++i)
	{
		cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
		try
		{
			double final_grade = students[i].grade();
			std::streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
		catch (std::domain_error e) {
		cout << e.what() << endl;
		}
	}
	return 0;
}