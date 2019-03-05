#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int a[3] = {10, 11, 10};
	int x, y = 1000;
	for(int i = 0; i < 3; i++)
	{
		while ((x = rand()) >= a[i] * y)
			;
		printf("第 %d 位组长编号： %d\n", i, x % a[i]);
	}
	return 0;
}
