#include "Date.h"

using std::cout;		using std::endl;

int main()
{
	cout << "�������������ڣ������գ��Կո�ָ�����" << endl;
	Date a(std::cin), b(std::cin);
	
	cout << "����һ��";
	output(a,cout);
	cout << endl;
	cout << "���ڶ���";
	output(b, cout);
	cout << endl;

	cout << "���������������Ϊ��" << inteval(a, b) << endl;
	cout << "������һ����һ��Ϊ��";
	b = a; b.add_day(); output(b,cout);
	cout << endl;
	cout << "������һ����һ��Ϊ��";
	b = a; b.add_month(); output(b, cout);
	cout << endl;
	cout << "������һ����һ��Ϊ��";
	b = a; b.add_year(); output(b, cout);
	cout << endl;

	return 0;
}