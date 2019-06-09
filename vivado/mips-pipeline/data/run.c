#include <stdio.h>

int main(void)
{
	int i, j, k, tmp;
	const int Size = 5;
	int a[Size][Size], b[Size][Size], c[Size][Size];
	int x[125], y[125], z[125];
	int a0, a1, a2, a3, s0, s1, s2, t3, t4, t5, t6, s3, s4, s5;
	int flag = 1;
	for (i = 0; i != Size; i++)
		for (j = 0; j != Size; j++)
		{
			a[i][j] = 1;
			b[i][j] = 1;
			c[i][j] = 1;
		}
	for (i = 0; i != Size; i++)
	{
		for (j = 0; j != Size; j++)
		{
			for (k = 0; k != Size; k++)
			{
				tmp = a[i][k] & b[k][j];
				c[i][j] = c[i][j] | tmp;
				tmp = i * 25 + j * 5 + k;
				x[tmp] = i * Size + k;
				y[tmp] = k * Size + j;
				z[tmp] = i * Size + j;
				// printf("%d: %d, %d, %d\n", tmp, x[tmp], y[tmp], z[tmp]);
				// getchar();
			}
		}
	}

	
	a0 = 0;
	a3 = 5;
	s0 = 0;
	s1 = 0;
	s2 = 0;
	i = 0;
	while (a0 != a3)
	{
		s3 = s0;
		a1 = 0;
		s1 = 0;
		while (a1 != a3)
		{
			s0 = s3;
			s4 = s1;
			a2 = 0;
			while (a2 != a3)
			{
				if (s0 != x[i])
				{
					printf("s0 = %d, x[%d] = %d\n", s0, i, x[i]);
					flag = 1;
				}
				if (s1 != y[i])
				{
					printf("s1 = %d, y[%d] = %d\n", s1, i, y[i]);
					flag = 1;
				}
				if (s2 != z[i])
				{
					printf("s2 = %d, z[%d] = %d\n", s2, i, z[i]);
					flag = 1;
				}
				a2++;
				s0++;
				s1 += a3;
				i++;
			}
			a1++;
			s2++;
			s1 = s4 + 1;
		}
		a0++;
	}
	return 0;
}
