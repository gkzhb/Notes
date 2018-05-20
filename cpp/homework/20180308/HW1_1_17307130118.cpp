#include <iostream>
#include <string>
int main(void)
{
    using std::cin;
    using std::cout;
    using std::string;
    using std::endl;
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Please enter the number of blanks surrounding the greeting: ";
    string::size_type flag,line;
    cin >> flag;
    line = flag * 2 + 3;
    string hello = "Hello, " + name + "!";
    string space(hello.size() + flag * 2, ' ');
    string second = "*" + space + "*";
    string first(second.size(), '*');
    string space2(flag, ' ');

    for (int i = 0; i < line; i++)
        if (0==i||line-1==i)
            cout << first << endl;
        else
            if (1+flag==i)
                cout << '*' << space2 << hello << space2 << '*' << endl;
            else
                cout << second << endl;

    return 0;
}
