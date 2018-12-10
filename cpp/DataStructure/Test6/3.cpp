// OJ, 勇士联赛
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void swap(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}
vector<int> a, cp, ans;
void bubble(vector<int> &score, vector<int> &a)
{
    bool flag = true;
    int i, j; 
    for(i = score.size() - 1; flag; i--)
    {
        flag = false;
        for(j = 0; j < i; j++)
            if (score[a[j]] < score[a[j + 1]])
            {
                swap(&a[j], &a[j + 1]);
                flag = true;
            }
    }
}
bool compare(int x, int y)
{
	return (ans[x] > ans[y]) || (ans[x] == ans[y] && x < y);
}

int main()
{
    int n, m, i, j, x, max = 0;
    cin >> n >> m;
	a.resize(n, 0);
	cp.resize(n, 0);
	ans.resize(n, 0);
    for(i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
        cp[i] = i;
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n / 2; j++)
            ans[a[cp[j * 2]] > a[cp[j * 2 + 1]] ? cp[j * 2] : cp[j * 2 + 1]]++;
        sort(cp.begin(), cp.end(), compare);
    }
    for(i = 0; i < n; i++)
        cout << ans[i] << ' ';

    return 0;
}