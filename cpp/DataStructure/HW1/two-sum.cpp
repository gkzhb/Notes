#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		struct Num
		{
			int data, index;
			Num(int d, int i) { 
				data = d;
				index = i;
			}
			static bool compare(Num a,Num b) {
				return a.data < b.data;
			}
		};
		vector<Num> data;
		for (vector<int>::const_iterator i = nums.begin(); i != nums.end(); i++)
			data.push_back(Num(*i, i - nums.begin()));
		std::sort(data.begin(), data.end(),Num::compare);
		vector<Num>::const_iterator i = data.begin(), j = data.end() - 1, head, tail,mid;
		vector<int> ans;
		while (i<j)
		{
			if (i->data + j->data > target)
			{
				head = i;
				tail = j;
				int aim = target - i->data;
				while (head != tail && 1 != tail - head)
				{
					mid = head + (tail - head) / 2;
					if (aim == mid->data)
						j = head = tail = mid;
					else 
						if (aim > mid->data)
							head = mid;
						else
							j = tail = mid;
				}
			}

			if (i->data + j->data==target)
			{
				int m = i->index, n = j->index;
				ans.push_back(m > n ? n : m);
				ans.push_back(m > n ? m : n);
				return ans;
			}
			i++;
			j = data.end()-1;
		}
	}
};

int main(void)
{
	vector<int> nums, ans;
	int target, tmp, n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> tmp;
		nums.push_back(tmp);
	}
	std::cin >> target;
	Solution a;
	ans = a.twoSum(nums, target);
	std::cout << ans[0] << ' ' << ans[1] << std::endl;
	return 0;
}