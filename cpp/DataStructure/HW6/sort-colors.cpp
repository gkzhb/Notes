// LeetCode, Sort Colors
// 用数组 a 记录每种颜色结束的位置，每次读入一个新颜色，对应改变每种颜色结束位置并赋值

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int a[3] = {0, 0, 0}, i = 0, n = nums.size(), x;
		i = 0;
		while (i < n)
		{
			x = nums[i];
			nums[a[x]] = x;
			a[x]++;
			for (int j = x + 1; j < 3; j++)
			{
				if (a[j] >= a[j - 1])
					nums[a[j]] = j;
				a[j]++;
			}
			i++;
		}
    }
};

