#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<map>

using namespace std;

map<string, int> a;

int main(void)
{
	const char *ERROR = "DuiYouNe!";
	string s, n1, n2;
	int n, j, tmax = 0;
	cin >> s >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> n1 >> n2 >> n2 >> n2 >> n2;
		string *target = NULL;
		if (n1 == s)
			target = &n2;
		if (n2 == s)
			target = &n1;
		if (target)
		{
			if (a.find(*target) == a.end())
				a[*target] = 1;
			else
			{
				j = ++a[*target];
				if (j > tmax)
					tmax = j;
			}
		}
	}
	vector<const map<string, int>::key_type *> max;
	for (map<string, int>::iterator i = a.begin(); i != a.end(); i++)
		if (i->second == tmax)
			max.push_back(&(i->first));
		
	if (max.size() <= 1)
		if (0 != tmax)
			cout << *max[0] << endl;
		else
			cout << ERROR << endl;
	else
	{
		int index = 0;
		for (int i = 1; i < max.size(); i++)
			if (*max[i] < *max[index])
				index = i;
		cout << *max[index] << endl;
	}
	return 0;
}


// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<cstdio>
// #include<cctype>
// #include<hash_map>

// using namespace std;

// vector<string> a;
// vector<int> b;

// int find(vector<string> &a, string &s)
// {
// 	for (int i = 0; i < a.size(); i++)
// 		if (a[i] == s)
// 			return i;
// 	return -1;
// }

// char *gets()
// {
// 	char c;
// 	int i = 1;
// 	char *ret = new char[11];
// 	while (isspace(c = getchar()))
// 		;
// 	ret[0] = c;
// 	while (!isspace(c = getchar()))
// 	{
// 		ret[i] = c;
// 		i++;
// 	}
// 	ret[i] = '\0';
// 	return ret;
// }


// bool cmp(int x, int y)
// {
// 	return a[x] < a[y] ? 1 : 0;
// }


// int main(void)
// {
// 	const char *ERROR = "DuiYouNe!";
// 	string s, n1, n2;
// 	char *x;
// 	//vector<string> a;
// 	//vector<int> b;
// 	int n, j;
// 	cin >> s >> n;
// 	for (int i = 0; i < n; i++)
// 	{
// 		x = gets();
// 		n1 = x;
// 		delete []x;
// 		delete []gets();
// 		delete []gets();
// 		delete []gets();
// 		x = gets();
// 		n2 = x;
// 		delete []x;
// 		// cin >> n1 >> n2 >> n2 >> n2 >> n2;
// 		string *target = NULL;
// 		if (n1 == s)
// 			target = &n2;
// 		if (n2 == s)
// 			target = &n1;
// 		if (target)
// 		{
// 			j = find(a, *target);
// 			if (-1 == j)
// 			{
// 				a.push_back(*target);
// 				b.push_back(0);
// 			}
// 			else
// 				b[j]++;
// 		}
// 	}

// 	vector<int> max(1, 0);
// 	for (int i = 0; i < b.size(); i++)
// 		if (b[i] >= b[max[0]])
// 		{
// 			if (b[i] != b[max[0]])
// 				max.clear();
// 			max.push_back(i);
// 		}
// 	if (max.size() == 1)
// 		if (0 != b[max[0]])
// 			cout << a[max[0]] << endl;
// 		else
// 			cout << ERROR << endl;
// 	int index = 0;
// 	for (int i = 1; i < max.size(); i++)
// 		if (a[max[i]] < a[max[index]])
// 			index = i;
// 	cout << a[max[index]] << endl;

// 	return 0;
// }