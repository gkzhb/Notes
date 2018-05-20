#include"median.h"
#include<vector>
#include<algorithm>

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