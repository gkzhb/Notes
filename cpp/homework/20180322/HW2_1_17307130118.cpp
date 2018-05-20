#include<iostream>
#include<algorithm>
#include<vector>
#include<cctype>
struct Words //存储单词及其出现次数
{
	std::string word;	//单词
	unsigned int time;	//出现次数
};

typedef std::vector<Words>::iterator iter;
typedef std::vector<Words>::const_iterator citer;
void get_words(std::istream &in, std::vector<Words> &out, int &total);
void output(int total,const std::vector<Words> &out);

bool not_space(char x)
{
	return !isspace(x);
}

int main(void)
{
	std::vector<Words> a;
	int total=0;
	try
	{
		std::cout << "请输入若干英语单词：" << std::endl;
		get_words(std::cin, a,total);								//读取单词并统计次数
		output(total, a);											//输出单词及次数
	}
	catch (std::domain_error)
	{
		std::cout << "未输入任何单词，请重试！" << std::endl;
	}
	return 0;
}

void get_words(std::istream &in, std::vector<Words> &out,int &total)
{
	std::string s;
	typedef std::string::iterator iters;
	out.clear();
	while (getline(in, s))
	{
		iters i, j;
		Words temp;
		i = s.begin();
		while (i!=s.end())
		{
			i = find_if(i, s.end(), not_space);
			j = find_if(i, s.end(), isspace);
			if (i!=j)
			{
				total++;
				iter k = out.begin();
				temp.word = std::string(i, j);
				while (k!=out.end()&&k->word!=temp.word)	//在向量out中寻找temp.word是否出现过
					k++;
				if (k==out.end())
				{											//k.word未出现过
					temp.time = 1;
					out.push_back(temp);
				}
				else
					k->time++;								//k.word出现过
			}
			i = j;
		}
	}
	if (out.empty())
		throw std::domain_error("No input Words!");
}

void output(int total,const std::vector<Words> &out)
{
	std::cout << "单词总数：" << total << std::endl
			  << "每个单词的出现次数：" << std::endl;

	citer i = out.begin();
	int max=0;
	while (i!=out.end())	//统计单词最长的长度
	{
		if (i->word.size()>max)
			max = i->word.size();
		i++;
	}
	max++;
	for (i = out.begin(); i != out.end();i++)
		std::cout << i->word << std::string(max - i->word.size(), ' ') << i->time << std::endl;
}