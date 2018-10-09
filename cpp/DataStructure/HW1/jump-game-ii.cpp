#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> ans(nums.size(), 0);
		int i, j, max = 0, pos = 0;
		for (i = 0; i < nums.size();i++)
		{
			if (i + nums[i] < max || nums[i]/(i + nums[i] - max + 1) > 10)
				continue;
			for (j = 1; j <= nums[i]; j++)
			{
				if (( 0==ans[i+j]|| ans[i+j]>ans[i]+1) && (i+j<nums.size()))
					ans[i + j] = ans[i] + 1;
				if (i + j>max)
					max = i + j;
			}
		}
		return ans[nums.size() - 1];
	}
};

/* class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> ans(nums.size(), 0);
		int i, j;
		for (i = 0; i < nums.size();i++)
			for (j = 1; j <= nums[i]; j++)
				if ((0==ans[i+j] || ans[i+j]>ans[i]+1) && (i+j<nums.size()))
					ans[i + j] = ans[i] + 1;
		return ans[nums.size() - 1];
	}
 };	*/

int main(void)
{
	int n, x;
	//std::cin >> n;
	vector<int> nums;
	for (int i = 0; i < 24999; i++)
	{
		nums.push_back(25000-i);
	}
	for (int i = 0; i < 10000;i++)
		nums.push_back(1000);
	Solution a;
	std::cout << a.jump(nums) << std::endl;

	return 0;
}