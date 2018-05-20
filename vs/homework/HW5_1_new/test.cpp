#include<iostream>
#include"Queue.h"
int main(void)
{
	struct line {
		int time, num;	//��¼���ʱ��͸���
		line() :time(0), num(0) { }
	} tmp;
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
	return 0;
}