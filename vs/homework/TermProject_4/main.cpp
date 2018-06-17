#include "BigInt.h"
int main(void)
{
	using std::cin;		using std::cout;
	using std::endl;
	BigInt a,b;
	int x, y;
	int n;
	cout << "Please selet Mode:" << endl << "1.read int" << endl << "2.read BigInt"<< endl << "3.auto" << endl
		<< "Please enter 1 or 2 or 3:\t";
	cin >> n;
	switch (n)
	{
	case 2:
		while (cin)
		{
			cin >> a >> b;
			BigInt c(a / b), d(a%b);
			cout << "c=a/b=" << c << endl;
			cout << "d=a%b=" << d << endl;
			cout << "c*b+d= " << c * b + d << endl
				<< "a=     " << a << endl;
		}
		break;
	case 1:
		while (cin)
		{
			cin >> x >> y;
			a = x; b = y;
			cout << "a/b" << endl << a / b << endl << x / y << endl;
			cout << "a%b" << endl << a % b << endl << x % y << endl;
		}
		break;
	case 3:
		int error=0;
		for (int i=-500;i<500;i+=35)
			for (int j = 401; j > -401; j -= 2)
			{
				a = i; b = j;
				cout << i << '/' << j << '=' << i / j << endl;
				cout << i << '/' << j << '=' << a / b << endl;
				cout << i << '%' << j << '=' << i % j << endl;
				cout << i << '%' << j << '=' << a % b << endl;
				if (i / j != a / b || i % j != a % b)
					error++;
			}
		cout << "Error: " << error << endl;
	}
	return 0;
}