#include "BigNum.h"
BigNum::BigNum(int x)
{
	if (x < 0)
	{
		data.push_back(1);
		x = -x;
	}
	else
		data.push_back(0);
	while (x != 0)
	{
		data.push_back(x % 10);
		x /= 10;
	}
}