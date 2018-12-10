#include <iostream>
#include <vector>

using namespace std;

int x[8] = {1, -1, -2, -2, -1, 1, 2, 2};
int y[8] = {2, 2, 1, -1, -2, -2, -1, 1};

bool jump(vector<vector<int>> &a, int x0, int y0, int step)
{
    bool flag = false;
    int xx, yy;
    if (step == a.size() * a[0].size())
        return true;
    for (int i = 0; i < 8; i++)
    {
        xx = x0 + x[i];
        yy = y0 + y[i];
        if (xx >= 0 && xx < a.size() && yy >= 0 && yy < a[0].size() && !a[xx][yy])
        {
            a[xx][yy] = step + 1;
            if (jump(a, xx, yy, step + 1))
                return true;
            a[xx][yy] = 0;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> tmp(m, 0);
    vector<vector<int>> a(n, tmp);
    a[0][0] = 1;
    if (jump(a, 0, 0, 1))
    {
        for (vector<vector<int>>::size_type i = 0; i < n; i++)
        {
            for (vector<int>::size_type j = 0; j < m - 1; j++)
                cout << a[i][j] << ' ';
            cout << a[i][m - 1] << endl;
        }
    }
    else
        cout << "QAQ" << endl;
    return 0;
}