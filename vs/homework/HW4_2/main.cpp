#include "Date.h"

using std::cout;		using std::endl;

int main()
{
	cout << "请输入两个日期（年月日，以空格分隔）：" << endl;
	Date a(std::cin), b(std::cin);
	
	cout << "日期一：";
	output(a,cout);
	cout << endl;
	cout << "日期二：";
	output(b, cout);
	cout << endl;

	cout << "两个日期相隔天数为：" << inteval(a, b) << endl;
	cout << "给日期一增加一天为：";
	b = a; b.add_day(); output(b,cout);
	cout << endl;
	cout << "给日期一增加一月为：";
	b = a; b.add_month(); output(b, cout);
	cout << endl;
	cout << "给日期一增加一年为：";
	b = a; b.add_year(); output(b, cout);
	cout << endl;

	return 0;
}