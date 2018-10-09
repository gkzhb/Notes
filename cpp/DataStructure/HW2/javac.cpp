#include <iostream>
#include <string>

using std::string;

string javac(string x)
{
	static const string err = "Error!";
	string ans;
	bool flag = false;	
		// flag 标记 变量名类型	false: C++	true: java
	string::iterator i = x.begin();
	int j, sublen;
	while (islower(*i))
		i++;
	if (i == x.begin() || *(x.end() - 1) == '_')
		return err;
	if (i != x.end() && '_' != *i)
		if (isupper(*i))
			flag = true;
		else
			return err;
	ans = x.substr(0, i - x.begin());
	while (i != x.end())
	{
		if (flag)
		{
			if (!isupper(*i))
				return err;
			ans.push_back('_');
			ans.push_back(tolower(*i));
		}
		else
		{
			if (*i != '_')
				return err;
			i++;
			if (islower(*i))
				ans.push_back(toupper(*i));
			else
				return err;
		}
		i++;
		j = i - x.begin();
		while (i != x.end() && islower(*i))
			i++;
		sublen = i - x.begin() - j;
		if (sublen)
			ans.append(x, j, sublen);
	}
	return ans;
}

int main(void)
{
	string x;
	while (std::cin >> x)
		std::cout << javac(x) << std::endl;
	return 0;
}