#include<stdio.h>
int main(void)
{
	int a,b;
	while(1)
	{
		scanf("%d%d",&a,&b);
		printf("%d/%d=%d\n%d%%%d=%d\n",a,b,a/b,a,b,a%b);
	}
	return 0;
}
