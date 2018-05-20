#include<stdio.h>
// 出租车计价

char get_char(void);		// 读取一个二选一字符

int main(void)
{
	int i=0,j=0,l,t;
	double k,s,ans;
	char c;
	printf("请选择里程：\n1.单程\n2.往返\n你的选择：");
	c = get_char();
	i = c - '0';
	do
	{
		printf("是否早晚高峰：\n1.是\n2.否\n你的选择：");
		c = get_char();
		l=c-'0';
		j=(c=='1')?1:0;
		printf("是否夜间：\n1.是\n2.否\n你的选择：");
		c = get_char();
		l=l*10+c-'0';
		k=(c=='1')?1.2:1;
	} while (k==11);
	printf("输入行驶里程数：");
	scanf("%lf",&s);
	printf("输入低速时间：");
	scanf("%d",&t);
	s+=(double)(1+j)*(double)t/5.0;
	if (s<3.0)
		ans=13.0;
	else
		if (i==2||s<15.0)
			ans=13.0+k*2.3*(s-3.0);
		else
			ans=13.0+k*2.3*12.0+(2.3*k+2.3*0.5)*(s-15.0);
	printf("出租车计价为：%d",(int)(ans+0.5));
	return 0;
}

char get_char(void)
{
	char c;
	do
		c=getchar();
	while (c != '1' && c != '2');
	while (getchar()!='\n')
		;
	return c;
}