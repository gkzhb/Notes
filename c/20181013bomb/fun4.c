#include <stdio.h>

int fun4(int x, int y, int z)
{
	int i = z - y, j = i >> 31;
	i = (i + j) / 2;
	j = i + y;
	if (j > x)
	{
		z = j - 1;
		fun4(x, y, z);
		i = i + i;
	}
	else
	{
		i = 0;
		if (j < x)
		{
			y = j + 1;
			fun4(x, y, z);
			i = 2 * i + 1;
		}
	}
	
}

int main(void)
{
	for (int i = 0; i < 15; i++)
		printf("%d : %d\n", i, fun4(i, 0, 14));
		
	return 0;
}