#include <iostream>
#include "Str.h"
int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Please enter your first name: ";
    Str name;
    cin >> name;
	while (getchar() != '\n')
		;
    cout << "Please enter the number of blanks surrounding the greeting: ";
    Str::size_type flag,line;
    cin >> flag;
	cout << endl;
    line = flag * 2 + 3;
	Str hello = "Hello, "+name+"!";
    Str space(hello.size() + flag * 2, ' ');
    Str second = "*" + space + "*";
    Str first(second.size(), '*');
    Str space2(flag, ' ');

    for (int i = 0; i < line; i++)
        if (0==i||line-1==i)
            cout << first << endl;
        else
            if (1+flag==i)
                cout << '*' << space2 << hello << space2 << '*' << endl;
            else
                cout << second << endl;

	cout << "逐个字符输出greeting(字符之间以空格分隔):" << endl;		// 输出
	for (Str::size_type i = 0; i != hello.size(); ++i)
		cout << hello[i] << ' ';
	cout << endl;

    return 0;
}
