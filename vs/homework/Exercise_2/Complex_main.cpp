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

	cout << "请输入一个复数(实部 虚部): ";
	cin >> c1 ;
	cout << c1 << endl;
	cout << "请输入一个实数: ";
	cin >> d;
	c2 = Complex(d);

	cal(c1, c2);
	cal(c2, c1);

	cout << "请输入一个复数(实部 虚部): ";
	cin >> c1 ;
	cout << c1 << endl;
	cout << "请输入一个复数(实部 虚部): ";
	cin >> c2;
	cout << c2 << endl;

	cal(c1, c2);
	cal(c2, c1);

	return 0;
}