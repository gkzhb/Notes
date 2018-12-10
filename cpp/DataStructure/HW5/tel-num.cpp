// Online Judge, 1016 电话号码
// 先通过转换单词表，并用 kmp 算法在密码串中寻找它们的出现位置，
// 利用二位数组存储密码串中每个位置对应的所有的 从该位置开始可能匹配的单词长度
// 通过广度优先搜索，寻找可能的匹配的最大长度，并对每个位置作标记是否走到过

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


// #define TEST
// #define TEST1

// 构建字母到数字字符的映射
void getConst(char a[26])
{
	int i;
	for (i = 0; i < 4; i++)
		a[i * 3] = a[i * 3 + 1] = a[i * 3 + 2]= i + 1 + '0';
	a[12] = a[13] = '5';
	for (i = 0; i < 4; i++)
		a[i * 3 + 14] = a[i * 3 + 15] = a[i * 3 + 16] = i + 6 + '0';
#ifdef TEST1
	for (i = 0; i < 26; i++)
		cout << char('a' + i) << " : " << a[i] << endl;
#endif
}

// 将字母转换为数字字符
string convert(const string &x, char a[26])
{
	string ret;
	for (string::size_type i = 0; i < x.size(); i++)
		ret.push_back(a[x[i] - 'a']);
	return ret;
}

// kmp 预处理
void preProcess(const string &a, vector<int> &next)
{
	next.clear();
	next.resize(a.size() + 1);
	next[0] = -1;
	int i = 0, j = -1;
	while (i < a.size())
		if (j == -1 || a[i] == a[j])
		{
			j++;
			i++;
			next[i] = j;
		}
		else
			j = next[j];
}

vector<int> kmp(const string &s, const string &target)
{
	vector<int> next, ret;
	int j = 0;
	preProcess(target, next);
	string::size_type i = 0;
	
	while (i < s.size())
	{
		if (-1 == j || s[i] == target[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
		if (j == target.size())
		{
			ret.push_back(i - j);
			j = next[j];
		}
	}
	return ret;
}

// 广搜查找匹配长度
bool doit(const vector<vector<int>> &s)
{
	list<int> a;
	int i, j, k, target = s.size();
	vector<bool> b(target, false);
	a.push_back(0);

#ifdef TEST
	list<int>::iterator p = a.begin();
	while (p != a.end())
	{
		i = *p;
#else
	while (!a.empty())
	{
		i = a.front();
#endif
		for (j = 0; j < s[i].size(); j++)
		{
			k = i + s[i][j];
			if (k == target)
				return true;
			if (!b[k])
			{
				a.push_back(k);
				b[k] = true;
#ifdef TEST
				cout << k << ' ';
#endif
			}
		}

#ifdef TEST
		p++;
#else
		a.pop_front();
#endif
	}
	return false;
}

int main(void)
{
	int n, i;
	string::size_type j;
	char a[26];
	bool ans;
	string secret, tmp;
	vector<vector<int>> s;	// 构建 secret 串中每一个位置可以匹配的单词长度 的向量
	vector<int> temp;
	getConst(a);
	cin >> n >> secret;
	s.resize(secret.size());
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		tmp = convert(tmp, a);
#ifdef TEST
		cout << tmp << endl;
#endif
		temp = kmp(secret, tmp);
		j = tmp.size();
		for (vector<int>::const_iterator k = temp.begin(); k != temp.end(); k++)
			s[*k].push_back(j);
	}

#ifdef TEST
	cout << endl;
	for (i = 0; i < s.size(); i++)
	{
		cout << i << " : ";
		for (int k = 0; k < s[i].size(); k++)
			cout << s[i][k] << ' ';
		cout << endl;
	}
	cout << endl;
#endif

	ans = doit(s);
	if (ans)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}