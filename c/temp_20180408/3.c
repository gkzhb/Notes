#include<stdio.h>
// ���⳵�Ƽ�

char get_char(void);		// ��ȡһ����ѡһ�ַ�

int main(void)
{
	int i=0,j=0,l,t;
	double k,s,ans;
	char c;
	printf("��ѡ����̣�\n1.����\n2.����\n���ѡ��");
	c = get_char();
	i = c - '0';
	do
	{
		printf("�Ƿ�����߷壺\n1.��\n2.��\n���ѡ��");
		c = get_char();
		l=c-'0';
		j=(c=='1')?1:0;
		printf("�Ƿ�ҹ�䣺\n1.��\n2.��\n���ѡ��");
		c = get_char();
		l=l*10+c-'0';
		k=(c=='1')?1.2:1;
	} while (k==11);
	printf("������ʻ�������");
	scanf("%lf",&s);
	printf("�������ʱ�䣺");
	scanf("%d",&t);
	s+=(double)(1+j)*(double)t/5.0;
	if (s<3.0)
		ans=13.0;
	else
		if (i==2||s<15.0)
			ans=13.0+k*2.3*(s-3.0);
		else
			ans=13.0+k*2.3*12.0+(2.3*k+2.3*0.5)*(s-15.0);
	printf("���⳵�Ƽ�Ϊ��%d",(int)(ans+0.5));
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