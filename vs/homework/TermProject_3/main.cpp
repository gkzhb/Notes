#include "BigInt.h"
int main(void)
{
	using std::cin;		using std::cout;
	using std::endl;
	BigInt a,b;
	int n;
	cout << "Please selet Mode:" << endl << "1.auto" << endl << "2.manual" << endl
		<< "Please enter 1 or 2:\t";
	cin >> n;
	if (2==n)
		while (cin)
		{
			cin >> a >> b;
			cout << "a=" << a << endl
				<< "b=" << b << endl;
			cout << "a+b=" << a + b << endl
				<< "a-b=" << a - b << endl;
		}
	if (1==n)
	{
		int error = 0, total = 0;
		for (int i=-10000;i<10001;i+=323)
			for (int j = 10000; j > -20001; j-=214)
			{
				total++;
				a = i; b = j;			
				cout << a << '-' << b << '=' << a - b << ' '
					<< i << '-' << j << '=' << i - j << ' ';
				if (a - b == i - j)
					cout << "yes" << endl;
				else
					error++;
				cout << a << '+' << b << '=' << a + b << ' '
					<< i << '+' << j << '=' << i + j << ' ';
				if (a + b == i + j)
					cout << "yes" << endl;
				else
					error++;
			}
		cout << "Total error: " << error << endl << "Total run: " << total << endl;
	}
	return 0;
}