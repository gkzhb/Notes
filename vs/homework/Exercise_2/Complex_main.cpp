#include "Complex.h"

using std::cin;		using std::cout;
using std::endl;

void cal(const Complex& c1, const Complex& c2)
{
	cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
	cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
	cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;
	cout << c1 << " / " << c2 << " = " << c1 / c2 << endl;
}

int main()
{
	Complex c1, c2;
	double d;

	cout << "������һ������(ʵ�� �鲿): ";
	cin >> c1 ;
	cout << c1 << endl;
	cout << "������һ��ʵ��: ";
	cin >> d;
	c2 = Complex(d);

	cal(c1, c2);
	cal(c2, c1);

	cout << "������һ������(ʵ�� �鲿): ";
	cin >> c1 ;
	cout << c1 << endl;
	cout << "������һ������(ʵ�� �鲿): ";
	cin >> c2;
	cout << c2 << endl;

	cal(c1, c2);
	cal(c2, c1);

	return 0;
}