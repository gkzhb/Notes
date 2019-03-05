#include "Pipeline.h"
#include "preprocess.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define TEST_MEM_READ

void printHelp()
{
	cout << "Usage:" << endl;
	cout << "main.exe [Input File Name]" << endl;
}

int main(int argc, char **argv)
{
	if (1 == argc)
	{
		printHelp();
		system("pause");
		return 0;
	}
	if (argc > 2)
	{
		cout << "Too much arguments!" << endl;
		printHelp();
		system("pause");
		return 0;
	}
	vector<char> memory;
	string file(argv[1]);
	int stat = preProcess(memory, file);
#ifdef TEST_MEM_READ
	int i;
	for (i = 0; i < memory.size(); i++)
	{
		cout << setw(2) << setfill('0') << hex << (unsigned int)((unsigned char)(memory[i]));
	}
	cout << endl << "#" << endl;
#endif
	execute(memory);
#ifndef __gnu_linux__
	system("pause");
#endif
	return 0;
}
