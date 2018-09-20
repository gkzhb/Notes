#include "Table.h"
#include <string>

using std::cout;		using std::endl;

Table::Table(const Desktop &t, const Leg ls[]):dt(t)
{
	for (int i = 0; i < 4; i++)
		lg[i] = ls[i];
}

std::ostream &operator<<(std::ostream &os, const Table &t)
{
	cout << "This table has a " << t.dt.getColor() << ' ' << t.dt.getLength() << '*' << t.dt.getWidth() << " desktop." << endl
		<< "Its legs are as follow:" << endl;
	for (int i = 0; i < 4; i++)
		cout << t.lg[i].getColor() << ' ' << t.lg[i].getHeight() << endl;
	
	return os;
}