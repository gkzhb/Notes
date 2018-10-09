#include <iostream>
#include "Table.h"

using std::cout;	

int main( ) 
{ 
	Leg legs[] = {Leg(70,"Red"), Leg(70,"Yellow"), Leg(70,"Blue"), Leg(70,"Green")};
	Desktop top(60, 80, "White");
	Table table(top, legs);
	cout << table;
	return 0; 
}
