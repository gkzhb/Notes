#include<stdio.h>

int main(void)
{
	char a[10];
	a[0] = a[1] = a[2] = 0;
	printf("%16c\n", 'a');
	printf("aa%n\n", a + 1);
	printf("%d\n", a[1]);
	return 0;
}