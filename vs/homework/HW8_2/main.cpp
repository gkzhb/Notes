#include"Shape.h"
#include<fstream>
#include<iomanip>
using std::cin;		using std::cout;
using std::endl;
int main()
{
	const char* input = "shape.txt";
	std::ifstream infile(input);
	cout << "Area    Circumference" << endl;
	Shape record;
	while (record.read(infile))				// 计算、输出周长和面积
		if (record.valid())
			cout << std::setiosflags(std::ios::left)<<std::setw(8) << record.area() << record.perimeter() << endl;
		else
			cout << "invalid side length" << endl;
	return 0;
}