#include"Shape.h"

int main(void)
{
	using std::cin;		using std::cout;
	using std::endl;
	cout << "�����������ε������߳���";
	Triangle x(cin);
	cout << "�����ε��ܳ�Ϊ��" << x.perimeter() << "�����Ϊ��" << x.area() << endl;
	cout << "��������εĳ��Ϳ�";
	Rectangle y(cin);
	cout << "���ε��ܳ�Ϊ��" << y.perimeter() << "�����Ϊ��" << y.area() << endl;
	cout << "������Բ�İ뾶��";
	Circle z(cin);
	cout << "Բ���ܳ�Ϊ��" << z.perimeter() << "�����Ϊ��" << z.area() << endl;

	return 0;
}