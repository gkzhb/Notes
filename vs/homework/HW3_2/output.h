#ifndef GUARD_output_h
#define GUARD_output_h
#include <iostream>
#include <string>
template <class Out>
void output(Out begin, Out end)			// ���������[begin,end)֮���������ָ�������
{
	for (Out i = begin; i != end; i++)
		std::cout << *i << "  ";		// ���������i������
	std::cout << std::endl;
}
#endif