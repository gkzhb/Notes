#include"median.h"
#include<vector>
#include<algorithm>

double median(std::vector<double> x)		//计算向量的中值
{
	if (x.empty())
		return 0.0;
	else
	{
		std::vector<double>::size_type mid = x.size() / 2;
		sort(x.begin(), x.end());
		return x.size() % 2 ? x[mid] : (x[mid] + x[mid - 1]) / 2.0;			//计算中值
	}
}