#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "accumulate.h"
#include "max_min_element.h"
#include "output.h"

#define random(a,b) (rand()%(b-a+1)+a)			// 生成[a,b)之间的随机数

int main()
{
	srand((unsigned)time(NULL));
	std::vector<int> a;
	std::vector<double> b;
	std::vector<std::string> c;
	int ans_1=0;
	double ans_2=0.0;
	std::string ans_3;
	for (int i = 0; i < 10; i++)
		a.push_back(random(1, 100));				// 生成10个随机整数
	std::cout << "The integer list:" << std::endl;
	output(a.begin(), a.end());
	accumulate(a.begin(), a.end(),ans_1);
	std::cout << "The sum of the integer list: " << ans_1 << std::endl;
	std::cout << "The max element in the integer list: " << *max_element(a.begin(), a.end()) << std::endl;
	std::cout << "The min element in the integer list: " << *min_element(a.begin(), a.end()) << std::endl << std::endl;

	for (int i = 0; i < 10; i++)
		b.push_back(rand() / (double)RAND_MAX);		// 生成10个[0，1)之间的随机浮点数
	std::cout << "The double list:" << std::endl;
	output(b.begin(), b.end());
	accumulate(b.begin(), b.end(), ans_2);
	std::cout << "The sum of the double list: " << ans_2 << std::endl;
	std::cout << "The max element in the double list: " << *max_element(b.begin(), b.end()) << std::endl;
	std::cout << "The min element in the double list: " << *min_element(b.begin(), b.end()) << std::endl << std::endl;

	for (int i = 0; i < 10; i++)
	{													// 生成10个随机字符串
		std::string s = "";
		int len = random(1, 10);
		for (int j = 0; j < len; j++)					// 生成一个长度为[1,10)内随机数len的随机字符串(只含有字母'a'~'z')
			s = s + (char)random((int)'a', (int)'z');
		c.push_back(s);
	}
	std::cout << "The string list:" << std::endl;
	output(c.begin(), c.end());
	accumulate(c.begin(), c.end(), ans_3);
	std::cout << "The concatenation of the string list: " << ans_3 << std::endl;
	std::cout << "The max string in the string list: " << *max_element(c.begin(), c.end()) << std::endl;
	std::cout << "The min string in the string list: " << *min_element(c.begin(), c.end()) << std::endl << std::endl;

	return 0;
}