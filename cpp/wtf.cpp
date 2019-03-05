#include <iostream>
using namespace std;
int main()
{
	int n, i = 0;
	cin >> n;
	while(n >> (i * 8))
		i++;
	cout << i << endl;
	return 0;
}