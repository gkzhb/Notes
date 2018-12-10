class Solution {
	public:
		int trapRainWater(vector<vector<int>>& heightMap) {
				vector<vector<int>> &a = heightMap;
				int m = a.size(), n = a[0].size();
				vector<vector<bool>> b(m, vector<bool>(n, 0));
				
				for(int i = 0; i < m; i++)
					b[i][0] = b[
		}
};
