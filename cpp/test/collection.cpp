#include <iostream>
#include<algorithm>
#include <vector>
bool space(char x)
{
	return x == ' ';
}

bool not_space(char x)
{
	return x != ' ';
}

template<class Out>
void split(const std::string& s,Out os)
{
	typedef std::string::const_iterator iter;
	iter i = s.begin();
	while (i != s.end())
	{
		i = find_if(i, s.end(), not_space);
		iter j = find_if(i, s.end(), space);
		if (i!=s.end())
			*os++ = std::string(i, j);
		i = j;
	}
	return;
}

int main(void)
{
	std::string s;
	getline(std::cin, s);
	std::vector<std::string> a;
	//split(s, ostream_iterator<std::string>(std::cout));
	split(s, back_inserter(a));
	return 0;
}