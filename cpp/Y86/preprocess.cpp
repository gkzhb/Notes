#include "preprocess.h"
#include <fstream>
#include <vector>
#include <string>
#include <cstring>  // strlen()
#include <cctype>	// isspace()
#define MAX(A, B) ((A) > (B) ? (A) : (B))
using namespace std;

// 获取 16 进制字符转化为数字
int getHexChar(char c)
{
	if (isdigit(c))
		return c - '0';
	else
		return tolower(c) - 'a' + 10;
}

// 判断字符是否为十六进制数字
bool judgeHexChar(char c)
{
	c = tolower(c);
	if (!isdigit(c) && (c < 'a' || c > 'f'))
		return false;
	else
		return true;
}

// 从字符串中读取 16 进制数
long long getHex(char **a)
{
	long long ret = 0;
	while(isdigit(**a) || isalpha(**a))
	{
		ret = (ret << 4) + getHexChar(**a);
		(*a)++;
	}
	return ret;
}

// 预处理，将名为 fileName 的 yo 文件内数据读取到向量 mem (内存)中
// lineMaxChar: 读取文件时每行最多读取字符数
// 返回值 int:
//		0: 正常读取
//		正数: 该行数据不符合格式要求
//		-1: 读取文件未读取到末尾，可能发生其它的读取错误
int preProcess(vector<char> &mem, const string &fileName, int lineMaxChar)
{
	mem.clear();
	ifstream in(fileName, ifstream::in);
	char *line = new char[lineMaxChar];
	int len, pos = 0;
	char *i, *j;
	char c1, c2;
	long long x, max = 0;
	while (in.getline(line, lineMaxChar))
	{
		i = line;
		len = strlen(line);
		j = i + len;
		while (i != j && isspace(*i))
			i++;
		if (*i == '0' || *(i + 1) == 'x')
		{
			i += 2;
			x = getHex(&i);		// 读入十六进制的内存地址
			max = MAX(max, x);	// 记录内存中最大的内存地址
		}
	}
	max = max > 0xff ? max : 0xff;
	mem.resize(max + 1);
	in.clear();
	in.seekg(0);
	while (in.getline(line, lineMaxChar))
	{
		pos++;		// 记录读入文件行数
		i = line;
		len = strlen(line);
		j = i + len;
		while (i != j && isspace(*i))
			i++;
		if (i == j || *i == '|')
			continue;
		if (*i != '0' || *(i + 1) != 'x')
			return pos;
		i += 2;
		x = getHex(&i);		// 读入十六进制的内存地址
		while (i != j && (':' == *i || isspace(*i)))
			i++;
		while (i != j && !isspace(*i) && '|' != *i)		// 将数据写入 mem 即“内存”中
		{
			c1 = *i;
			c2 = *(i + 1);
			if (!judgeHexChar(c1) || !judgeHexChar(c2))		// 判断即将读入的两个字符合法
				return pos;
			c1 = (getHexChar(c1) << 4) + getHexChar(c2);
			i += 2;
			mem[x++] = c1;
		}

	}
	if (!in.eof())
		return -1;
	else
		return 0;
}
