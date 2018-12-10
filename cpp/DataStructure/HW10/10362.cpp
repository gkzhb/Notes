#include<iostream>
#include<stdio.h>
#include<vector>
//打扰了,dfs WA了两发，只能生成函数递推公式了。。 
using namespace std;
struct Bignum{
	vector<int> num;
	Bignum operator * (int v){
		int size = this->num.size();
		for(int j = 0; j < this->num.size(); j++)
			this->num[j] = this->num[j] * v;
		for(int j = size - 1; j >= 0; j--){
			if(j > 0 && this->num[j] >= 10000){
				this->num[j - 1] += this->num[j] / 10000;
				this->num[j] %= 10000;
			}else if(j == 0 && this->num[0] >= 10000){
				this->num.insert(this->num.begin(), this->num[0] / 10000);
				this->num[1] %= 10000;
			}
		}
		return *this;
	}//5122940
	Bignum operator / (int k){
		int i = 0;
		while(i < this->num.size()){
			if(i < this->num.size() - 1){
				if(this->num[i] >= k){
					this->num[i + 1] += this->num[i] % k * 10000;
					this->num[i] /= k;
				}else{
					this->num[i + 1] += this->num[i] % k * 10000;
					this->num[i] = 0;
				}
			}else
				this->num[i] /= k;
			i++;
		}
		while(this->num[0] == 0)
			this->num.erase(this->num.begin());
		return *this;
	}
};
int main(){
	int N;
	scanf("%d", &N);
	Bignum sum;
	sum.num.push_back(1);
	int tmp = N;
	int j = 1;
	for(; tmp <= 2 * N - 2; tmp++, j++){
		sum = sum * tmp;
		sum = sum / j;
	}
	sum = sum / N;
	printf("%d", sum.num[0]);
	for(int i = 1; i < sum.num.size(); i++)
		printf("%04d", sum.num[i]);
} 
