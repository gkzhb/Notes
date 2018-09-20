#include<stdio.h>
//#include<conio.h>
int main()
{
	int c;
	while((c=getchar())!='0')
		printf("0x%02x\n",(unsigned int)c);
	return 0;
}
