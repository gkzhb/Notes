// LeetCode, Median of Two Sorted Arrays
// 用两个下标标记 i j 将两个数组分为两部分，使左半部分与右半部分数目差不超过 1
// 只要 i 确定了，那么 j 的值也确定了，所以我们只要通过二分法找到 i 的正确位置，使 i j 将两个数组分为一大一小两部分，就可以算出中位数了。

#define TEST
#ifdef TEST
#include <iostream>
#include <vector>
using namespace std;
#endif

class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			if (nums1.size() <= nums2.size())
				return median(nums1, nums2);
			else
				return median(nums2, nums1);
		}
		double median(vector<int>& a, vector<int>& b)
		{
			vector<int>::size_type i, j, n = a.size(), m = b.size(),  x = (n + m + 1) / 2, max = n, min = 0;
			int mid;
			while (min <= max)// (!(i == len1 || j == len2 || (a[i - 1] < b[j] && b[j - 1] < a[i])))
			{
				i = (max + min) / 2;
				j = x - i;
				if (i < n && j > 0 && b[j - 1] > a[i])
					min = i + 1;
				else
					if (i > 0 && j < m && b[j] < a[i - 1])
						max = i - 1;
					else
					{
						if (i == 0)
							mid = b[j - 1];
						else
							if (j ==0)
								mid = a[i - 1];
							else
								mid = a[i - 1] > b[j - 1] ? a[i - 1] : b[j - 1];
						break;
					}
			}
			if ((n + m) % 2 == 1)
				return (double)mid;
			if (i == n)
				return (mid + b[j]) / 2.0;
			if (j == m)
				return (mid + a[i]) / 2.0;
			return (mid + (a[i] < b[j] ? a[i] : b[j])) / 2.0;
		}
		
};

#ifdef TEST
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n, 0), b(m, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	Solution p;
	cout << p.findMedianSortedArrays(a, b) << endl;
	return 0;
}
#endif
// 参考资料：
// https://www.geeksforgeeks.org/median-two-sorted-arrays-different-sizes-ologminn-m/
