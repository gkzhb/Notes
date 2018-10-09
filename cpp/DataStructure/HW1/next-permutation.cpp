#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		vector<int>::iterator i;
		int tmp;
		for (i = nums.end() - 1; i != nums.begin() && *i <= *(i - 1); i--)
			;
		vector<int>::iterator begin = i, end = nums.end() - 1;
		if (i != nums.begin()) {
			vector<int>::iterator j = i;
			tmp = *(i - 1);
			while (j + 1 != nums.end() && *(j + 1) > tmp)
				j++;
			*(i - 1) = *j;
			*j = tmp;
		}
		while (begin<end) {
			tmp = *begin;
			*begin = *end;
			*end = tmp;
			begin++;
			end--;
		}
	}
};

int main(void)
{
	int n, x;
	vector<int> data;
	std::cin >> n;
	for (int i = 0; i < n;i++) {
		std::cin >> x;
		data.push_back(x);
	}
	Solution a;
	a.nextPermutation(data);
	for (int i = 0; i < n;i++)
		std::cout << data[i] << ' ';
	std::cout << std::endl;
	
	return 0;
}