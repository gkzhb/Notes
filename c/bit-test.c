#include <stdio.h>

int main(void)
{
	signed int a = 0x12345678;
	signed int b = 0x1234567812345678;
	signed int c = 0xafffffff;
	printf("%d %d %d %d\n", a, b, c, __INT32_MAX__);
	a = a >> 3;
	b = b >> 3;
	c = c << 1 >> 3;
	printf("%d %d %d\n", a, b, c);

	return 0;
}