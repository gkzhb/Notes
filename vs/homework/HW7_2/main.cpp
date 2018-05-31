#include"Shape.h"

int main(void)
{
	using std::cin;		using std::cout;
	using std::endl;
	cout << "请输入三角形的三条边长：";
	Triangle x(cin);
	cout << "三角形的周长为：" << x.perimeter() << "，面积为：" << x.area() << endl;
	cout << "请输入矩形的长和宽：";
	Rectangle y(cin);
	cout << "矩形的周长为：" << y.perimeter() << "，面积为：" << y.area() << endl;
	cout << "请输入圆的半径：";
	Circle z(cin);
	cout << "圆的周长为：" << z.perimeter() << "，面积为：" << z.area() << endl;

	return 0;
}