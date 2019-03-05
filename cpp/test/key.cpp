#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int main()
{
	int key;
	while ((key = getch()) != 'q')
	{
		cout << key << endl;
		switch (key)
		{
			case 72:
				cout << "up" << endl;
				break;
			case 80:
				cout << "down" << endl;
				break;
			case 75:
				cout << "left" << endl;
				break;
			case 77:
				cout << "right" << endl;
				break;
		}
	}

	system("pause");
	return 0;
}
