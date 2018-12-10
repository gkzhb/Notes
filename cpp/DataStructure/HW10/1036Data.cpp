#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
	srand(time(NULL));
	ofstream fout("1036.in");
	fout << rand() % 1000 + 1 << endl;
	return 0;
}