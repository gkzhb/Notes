#include <iostream>
int main(void)
{
    using std::string;
    using std::cout;
    using std::cin;
    using std::endl;

    string::size_type n,m;
    cout << "�����������εı߳���";
    cin >> n;
    cout << endl;
    for (string::size_type i = 0; i < n;i++)
    {
        for (string::size_type j = 0; j < n;j++)
            cout << " *";
        cout << endl;
    }

    cout << endl
         << "�����볤���εĳ��Ϳ�";
    cin >> m >> n;
    cout << endl;
    for (string::size_type i = 0; i < n;i++)
    {
        for (string::size_type j = 0; j < m;j++)
            cout << " *";
        cout << endl;
    }

    cout << endl
         << "��������������εĵױ߳�����������";
    do
    {
        cin >> n;
        cout << endl;
        if (0 == n % 2)
            cout << "������һ��������";
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