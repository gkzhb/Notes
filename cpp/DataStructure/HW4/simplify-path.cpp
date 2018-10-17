#define LOCAL
#ifdef LOCAL
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#endif


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ans;
        string tmp;
        string::const_iterator i = path.begin(), j = i + 1;
        if (*i != '/')
            return "";
        while (i != path.end())
        {
            while (path.end() != i && '/' == *i)
                i++;
            j = i;
            while (path.end() != j && '/' != *j)
                j++;
            if (i != j)
            {
                tmp = path.substr(i - path.begin(), j - i);
                if (tmp != ".")
                    if (tmp != "..")
                        ans.push_back(tmp);
                    else
                        if (!ans.empty())
                            ans.pop_back();
                i = j;
            }
        }
        tmp.clear();
        if (ans.empty())
            return "/";
        for (vector<string>::const_iterator x = ans.begin(); x != ans.end(); x++)
            tmp = tmp + "/" + *x;
        
        return tmp;
    }
};

#ifdef LOCAL
int main(void)
{
    string s;
    cin >> s;
    Solution a;
    cout << a.simplifyPath(s) << endl;

    return 0;
}
#endif