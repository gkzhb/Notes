#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <string>
struct Student
{
	std::string name;
	double mid, final,total;
	std::vector<double> hw;
};
typedef std::vector<double>::iterator iter;
typedef std::string::size_type size_s;
typedef std::vector<Student>::iterator iter_s;
typedef std::vector<Student>::const_iterator citer_s;

std::istream &read(Student &x);
void cal(std::vector<Student> &x);
double cal_hw(std::vector<double> x);
void output(const std::vector<Student> &x,const size_s max);
bool cmp(const Student &a, const Student &b)
{
	return a.total >= b.total;
}

int main(void)
{
	std::vector<Student> data;
	Student datum;
	size_s max = 0;							//�ַ������� ������󳤶�
	while (read(datum))						 //��������
	{
		max = max > datum.name.size() ? max : datum.name.size();
		data.push_back(datum);
	}
	max++;
	cal(data);								//�����ܳɼ�
	sort(data.begin(), data.end(), cmp);	//���ܳɼ�����
	output(data,max); 						//����ܳɼ�

	return 0;
}

std::istream &read(Student &x)
{
	if (std::cin>>x.name>> x.mid >> x.final)//�������������С���ĩ�ɼ�
	{
		x.hw.clear();
		double y;
		while (std::cin>>y)					//����ƽʱ��ҵ�ɼ�
			x.hw.push_back(y);
		std::cin.clear();
	}
	return std::cin;
}

void cal(std::vector<Student> &x)
{
	for(iter_s i = x.begin();i!=x.end();i++)
	{
		try
		{
			i->total=0.4*i->final+0.2*i->mid+0.4*cal_hw(i->hw);	//�����ܳɼ�
			if (i->hw.empty())
				throw std::domain_error("No homework");
		}
		catch (std::domain_error)
		{
			std::cout << i->name << " has done no homework" << std::endl;	//�����δд����ҵ��ѧ��
		}
	}
}
double cal_hw(std::vector<double> x)		//�����ͥ��ҵ�ɼ�
{
	if (x.empty())
		return 0.0;
	else
	{
		std::vector<double>::size_type mid = x.size() / 2;
		sort(x.begin(), x.end());
		return x.size() % 2 ? x[mid] : (x[mid] + x[mid - 1]) / 2.0;			//�����ͥ��ҵ����ֵ
	}
}

void output(const std::vector<Student> &x,const size_s max)
{
	std::streamsize prec = std::cout.precision(3);
	for (citer_s i = x.begin(); i != x.end(); i++)
		std::cout << i->name << std::string(max - i->name.size(), ' ') << i->total << std::endl;	//����������ܳɼ�
	std::cout.precision(prec);
}