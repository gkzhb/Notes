// LeetCode, Maximum Gap
// 排序，找相邻两数的最大差

#define LOCAL

#ifdef LOCAL
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#endif

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
			return 0;
		sort(nums.begin(), nums.end());
		int max = 0;
		for (vector<int>::iterator i = nums.end() - 1; i != nums.begin(); i--)
			if (*i - *(i - 1) > max)
				max = *i - *(i - 1);
		return  max;
	}
};

#ifdef LOCAL
int main()
{
	
	return 0;
}
#endif