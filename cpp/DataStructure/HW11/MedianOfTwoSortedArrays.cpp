// LeetCode, Median of Two Sorted Arrays
//
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
			vector<int>::size_type i, j, len1 = a.size(), len2 = b.size(),  m = (len1 + len2) / 2, max = len1, min = 0;
			i = (max + min) / 2;
			j = m - i;
			while (!(i == len1 || j == len2 || (a[i - 1] < b[j] && b[j - 1] < a[i])))
			{
				if (b[j - 1] > a[i])
					min = i + 1;
				i = (max + min) / 2;
				j = m - i;
			}
		}
		
};

// 参考资料：
// https://www.geeksforgeeks.org/median-two-sorted-arrays-different-sizes-ologminn-m/
