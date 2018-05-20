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
	size_s max = 0;							//字符串长度 姓名最大长度
	while (read(datum))						 //读入数据
	{
		max = max > datum.name.size() ? max : datum.name.size();
		data.push_back(datum);
	}
	max++;
	cal(data);								//计算总成绩
	sort(data.begin(), data.end(), cmp);	//按总成绩排序
	output(data,max); 						//输出总成绩

	return 0;
}

std::istream &read(Student &x)
{
	if (std::cin>>x.name>> x.mid >> x.final)//读入姓名、期中、期末成绩
	{
		x.hw.clear();
		double y;
		while (std::cin>>y)					//读入平时作业成绩
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
			i->total=0.4*i->final+0.2*i->mid+0.4*cal_hw(i->hw);	//计算总成绩
			if (i->hw.empty())
				throw std::domain_error("No homework");
		}
		catch (std::domain_error)
		{
			std::cout << i->name << " has done no homework" << std::endl;	//输出从未写过作业的学生
		}
	}
}
double cal_hw(std::vector<double> x)		//计算家庭作业成绩
{
	if (x.empty())
		return 0.0;
	else
	{
		std::vector<double>::size_type mid = x.size() / 2;
		sort(x.begin(), x.end());
		return x.size() % 2 ? x[mid] : (x[mid] + x[mid - 1]) / 2.0;			//计算家庭作业的中值
	}
}

void output(const std::vector<Student> &x,const size_s max)
{
	std::streamsize prec = std::cout.precision(3);
	for (citer_s i = x.begin(); i != x.end(); i++)
		std::cout << i->name << std::string(max - i->name.size(), ' ') << i->total << std::endl;	//输出姓名和总成绩
	std::cout.precision(prec);
}