#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

int main(void)
{
    srand(time(0));
    ofstream output;
    output.open("hanoi.in");
	int n = rand() % 4 + 1, x;
	output << n << endl;
	vector<int> a[3];
	for (int i = 0; i < n; i++)
	{
		x = rand() % 3;
		a[x].push_back(i + 1);
	}
	for (int i = 0; i < 3; i++)
	{
		output << a[i].size() << ' ';
		for (int j = 0; j < a[i].size(); j++)
			output << a[i][j] << ' ';
		output << endl;
		a[i].clear();
	}
	for (int i = 0; i < n; i++)
	{
		x = rand() % 3;
		a[x].push_back(i + 1);
	}
	for (int i = 0; i < 3; i++)
	{
		output << a[i].size() << ' ';
		for (int j = 0; j < a[i].size(); j++)
			output << a[i][j] << ' ';
		output << endl;
		a[i].clear();
	}

    output.close();

    return 0;
}