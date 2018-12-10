static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int N=nums.size();
        if (N<2) return 0;
        auto lu = minmax_element(nums.begin(), nums.end());
        int l = *lu.first, u=*lu.second;
        
        int gap = max((u-l)/(N-1),1);
        int m = (u-l)/gap + 1;
        
        vector<int> bucket_max(m, INT_MIN);
        vector<int> bucket_min(m, INT_MAX);
        int k;
        for (auto num:nums)
        {
            k = (num-l)/gap;  // in kth bucket
            if (num>bucket_max[k]) bucket_max[k] = num;
            if (num<bucket_min[k]) bucket_min[k] = num;
        }
        
        gap = bucket_max[0]- bucket_min[0];
        int i=0,j;
        while (i<m)
        {
            j = i+1;
            while (j<m && bucket_max[j]==INT_MIN && bucket_min[j]==INT_MAX)
                j++;
            if (j==m) break;
            gap = max(gap, bucket_min[j]-bucket_max[i]);
            
            
            i=j;
        }
        return gap;
    }
};