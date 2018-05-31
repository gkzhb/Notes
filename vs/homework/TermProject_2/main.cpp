#include "BigInt.h"
int main(void)
{
	using std::cin;		using std::cout;
	using std::endl;
	BigInt a;
	cout << "Initialize a:" << a << endl << "Input a:";
	cin >> a; 
	cout << "Read a:" << a << endl;
	BigInt b(-552354234), c(5, 3),d(5,3);
	cout << "print b:" << b << endl << "print c:" << c << endl << "print d:" << d << endl;
	c = -c; b = absv(b);
	cout << "print b=absv(b):" << b << endl << "print c=-c:" << c << endl;
	cout << "print b>c :" << (int)(b > c) << endl;
	cout << "print a>=b:" << (int)(a >= b) << endl;
	cout << "print a<b :" << (int)(a < b) << endl;
	cout << "print -c==d :" << (int)(-c==d) << endl;
	return 0;
}