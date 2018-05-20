#ifndef GUARD_output_h
#define GUARD_output_h
#include <iostream>
#include <string>
template <class Out>
void output(Out begin, Out end)			// 输出迭代器[begin,end)之间迭代器所指向的数据
{
	for (Out i = begin; i != end; i++)
		std::cout << *i << "  ";		// 输出迭代器i中数据
	std::cout << std::endl;
}
#endif