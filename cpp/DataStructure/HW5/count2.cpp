#include <iostream>

using namespace std;

int main(void)
{
	long n, cp, a[10];
	cin >> n;
    for (int i = 0; i< 10; i++)
        a[i] = 0;
	for (long i = 1; i <= n; i++)
    {
        cp = i;
        while(cp)
        {
            a[cp % 10]++;
            cp /= 10;
        }
    }

    for (int i = 0; i < 10; i++)
        cout << a[i] << endl;

    return 0;
}