#include <iostream>
int main(void)
{
    using std::string;
    using std::cout;
    using std::cin;
    using std::endl;

    string::size_type n,m;
    cout << "请输入正方形的边长：";
    cin >> n;
    cout << endl;
    for (string::size_type i = 0; i < n;i++)
    {
        for (string::size_type j = 0; j < n;j++)
            cout << " *";
        cout << endl;
    }

    cout << endl
         << "请输入长方形的长和宽：";
    cin >> m >> n;
    cout << endl;
    for (string::size_type i = 0; i < n;i++)
    {
        for (string::size_type j = 0; j < m;j++)
            cout << " *";
        cout << endl;
    }

    cout << endl
         << "请输入等腰三角形的底边长（奇数）：";
    do
    {
        cin >> n;
        cout << endl;
        if (0 == n % 2)
            cout << "请输入一个奇数：";
    } while(0==n%2);
    for (string::size_type i = 0; i < n / 2 + 1; i++)
    {
        for (string::size_type j = 0; j < 5 - i;j++)
            cout << "  ";
        for (string::size_type j = 0; j < i * 2 + 1;j++)
            cout << " *";
        cout << endl;
    }

    return 0;
}