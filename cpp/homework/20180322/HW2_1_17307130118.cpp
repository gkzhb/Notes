#include<iostream>
#include<algorithm>
#include<vector>
#include<cctype>
struct Words //�洢���ʼ�����ִ���
{
	std::string word;	//����
	unsigned int time;	//���ִ���
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
		std::cout << "����������Ӣ�ﵥ�ʣ�" << std::endl;
		get_words(std::cin, a,total);								//��ȡ���ʲ�ͳ�ƴ���
		output(total, a);											//������ʼ�����
	}
	catch (std::domain_error)
	{
		std::cout << "δ�����κε��ʣ������ԣ�" << std::endl;
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
				while (k!=out.end()&&k->word!=temp.word)	//������out��Ѱ��temp.word�Ƿ���ֹ�
					k++;
				if (k==out.end())
				{											//k.wordδ���ֹ�
					temp.time = 1;
					out.push_back(temp);
				}
				else
					k->time++;								//k.word���ֹ�
			}
			i = j;
		}
	}
	if (out.empty())
		throw std::domain_error("No input Words!");
}

void output(int total,const std::vector<Words> &out)
{
	std::cout << "����������" << total << std::endl
			  << "ÿ�����ʵĳ��ִ�����" << std::endl;

	citer i = out.begin();
	int max=0;
	while (i!=out.end())	//ͳ�Ƶ�����ĳ���
	{
		if (i->word.size()>max)
			max = i->word.size();
		i++;
	}
	max++;
	for (i = out.begin(); i != out.end();i++)
		std::cout << i->word << std::string(max - i->word.size(), ' ') << i->time << std::endl;
}