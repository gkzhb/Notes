#include "preprocess.h"
#include <fstream>
#include <vector>
#include <string>
#include <cstring>  // strlen()
#include <cctype>	// isspace()
#define MAX(A, B) ((A) > (B) ? (A) : (B))
using namespace std;

// ��ȡ 16 �����ַ�ת��Ϊ����
int getHexChar(char c)
{
	if (isdigit(c))
		return c - '0';
	else
		return tolower(c) - 'a' + 10;
}

// �ж��ַ��Ƿ�Ϊʮ����������
bool judgeHexChar(char c)
{
	c = tolower(c);
	if (!isdigit(c) && (c < 'a' || c > 'f'))
		return false;
	else
		return true;
}

// ���ַ����ж�ȡ 16 ������
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

// Ԥ��������Ϊ fileName �� yo �ļ������ݶ�ȡ������ mem (�ڴ�)��
// lineMaxChar: ��ȡ�ļ�ʱÿ������ȡ�ַ���
// ����ֵ int:
//		0: ������ȡ
//		����: �������ݲ����ϸ�ʽҪ��
//		-1: ��ȡ�ļ�δ��ȡ��ĩβ�����ܷ��������Ķ�ȡ����
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
			x = getHex(&i);		// ����ʮ�����Ƶ��ڴ��ַ
			max = MAX(max, x);	// ��¼�ڴ��������ڴ��ַ
		}
	}
	max = max > 0xff ? max : 0xff;
	mem.resize(max + 1);
	in.clear();
	in.seekg(0);
	while (in.getline(line, lineMaxChar))
	{
		pos++;		// ��¼�����ļ�����
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
		x = getHex(&i);		// ����ʮ�����Ƶ��ڴ��ַ
		while (i != j && (':' == *i || isspace(*i)))
			i++;
		while (i != j && !isspace(*i) && '|' != *i)		// ������д�� mem �����ڴ桱��
		{
			c1 = *i;
			c2 = *(i + 1);
			if (!judgeHexChar(c1) || !judgeHexChar(c2))		// �жϼ�������������ַ��Ϸ�
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
