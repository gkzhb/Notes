#include <stdio.h>

int main(void)
{
	int x;
	printf("%5c", 'c');
	printf("%6c%n%7c", 'b', &x, 'a');
	printf("%d\n", x);
	return 0;
} 
