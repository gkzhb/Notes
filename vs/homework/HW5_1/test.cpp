#include<iostream>
#include"Queue.h"
int main(void)
{
	Queue<int> data;
	for (int i = 0; i < 5; i++)
		data.push_back(i);
	return 0;
}