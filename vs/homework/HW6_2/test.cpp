#include<iostream>
#include"Queue.h"

struct line {
	int time, num;	//��¼���ʱ��͸���
	line() :time(0), num(0) { }
} ;
void out(const line&x);

int main(void)
{
	line tmp;
	Queue<line> data;
	std::cout << "\t\t\tʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ�⣺" << std::endl;
	for (line i; !data.full(); i.time++)
	{
		if (0 == i.time % 8)
		{
			i.num++;
			data.in(i);
			std::cout << i.time << "s: ��" << i.num << "�˽���." << std::endl;
		}
		if (0 != i.time && 0 == i.time % 25)
		{
			tmp = data.head();
			data.out();
			std::cout << "\t\t\t" << i.time << "s: ��" << tmp.num << "�˳���." << std::endl;
		}
	}
	std::cout << "\t\t\t�ô����Ŷ������Ѵﵽ" << data.size() << "�ˣ��������" << std::endl;
	tmp = data.head();
	std::cout << "\t\t������Ա��" << tmp.time << "s���." << std::endl;
	tmp = data.tail();
	std::cout << "\t\t��β��Ա��" << tmp.time << "s���." << std::endl;

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