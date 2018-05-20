#include<stdio.h>
//	矩形相交面积

int max(int x, int y);
int min(int x, int y);
int in(int x, int y, int x1, int y1, int x2, int y2);

int main(void)
{
	int a[4],b[4],i,x[4],y[4],ans;
	printf("请输入Ax1 Ay1 Ax2 Ay2:\n");
	for (i = 0; i < 4; i++)
		scanf("%d", a + i);
	putchar('\n');
	x[0] = min(a[0], a[2]);
	x[1] = max(a[0], a[2]);
	y[0] = min(a[1], a[3]);
	y[1] = max(a[1], a[3]);
	printf("请输入Bx1 By1 Bx2 By2:\n");
	for (i = 0; i < 4;i++)
		scanf("%d", b + i);
	putchar('\n');
	x[2] = min(b[0], b[2]);
	x[3] = max(b[0], b[2]);
	y[2] = min(b[1], b[3]);
	y[3] = max(b[1], b[3]);
	if (in(x[2],y[2],x[0],y[0],x[1],y[1]))
		ans = min(x[1] - x[2], x[3] - x[2]) * min(y[1] - y[2], y[3] - y[2]);
	else
		if (in(x[2], y[3], x[0], y[0], x[1], y[1]))
			ans = min(x[1] - x[2], x[3] - x[2]) * (y[3] - y[0]);
		else
			if (in(x[0],y[0],x[2],y[2],x[3],y[3]))
				ans=min(x[3]-x[0],x[1]-x[0])*min(y[3]-y[0],y[1]-y[0]);
			else
				if (in(x[0],y[1],x[2],y[2],x[3],y[3]))
					ans=min(x[3]-x[0],x[1]-x[0])*(y[1]-y[2]);
				else
					ans=0;
	printf("公共部分面积S=%d",ans);
	return 0;
}

int max(int x,int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int min(int x,int y)
{
	if (x < y)
		return x;
	else
		return y;
}

int in(int x, int y, int x1, int y1, int x2, int y2)
{
	return (x1 < x && x < x2 && y1 < y && y < y2);
}