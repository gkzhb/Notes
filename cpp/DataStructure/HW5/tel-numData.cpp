#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void getConst(char a[26])
{
	int i;
	for (i = 0; i < 4; i++)
		a[i * 3] = a[i * 3 + 1] = a[i * 3 + 2]= i + 1 + '0';
	a[12] = a[13] = '4';
	for (i = 0; i < 4; i++)
		a[i * 3 + 14] = a[i * 3 + 15] = a[i * 3 + 16] = i + 6 + '0';
#ifdef TEST1
	for (i = 0; i < 26; i++)
		cout << char('a' + i) << " : " << a[i] << endl;
#endif
}

string convert(const string &x, char a[26])
{
	string ret;
	for (string::size_type i = 0; i < x.size(); i++)
		ret.push_back(a[x[i] - 'a']);
	return ret;
}

int main(void)
{
	char a[26];
	string s;
	getConst(a);
	cin >> s;
	cout << convert(s, a) << endl;

	return 0;
}