#include<iostream>
#include"Queue.h"

struct line {
	int time, num;	//记录入队时间和个数
	line() :time(0), num(0) { }
} ;
void out(const line&x);

int main(void)
{
	line tmp;
	Queue<line> data;
	std::cout << "\t\t\t食堂某个窗口高峰期的排队状况模拟：" << std::endl;
	for (line i; !data.full(); i.time++)
	{
		if (0 == i.time % 8)
		{
			i.num++;
			data.in(i);
			std::cout << i.time << "s: 第" << i.num << "人进队." << std::endl;
		}
		if (0 != i.time && 0 == i.time % 25)
		{
			tmp = data.head();
			data.out();
			std::cout << "\t\t\t" << i.time << "s: 第" << tmp.num << "人出队." << std::endl;
		}
	}
	std::cout << "\t\t\t该窗口排队人数已达到" << data.size() << "人！请分流！" << std::endl;
	tmp = data.head();
	std::cout << "\t\t队首人员于" << tmp.time << "s入队." << std::endl;
	tmp = data.tail();
	std::cout << "\t\t队尾人员于" << tmp.time << "s入队." << std::endl;

	Queue<line> q1(data), q2;
	q1.output(out);
	q2 = q1;
	q2.output(out);

	return 0;
}

void out(const line&x)
{
	std::cout << x.time;
}