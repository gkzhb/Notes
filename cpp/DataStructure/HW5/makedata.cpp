#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
    srand(time(0));
    ofstream output;
    output.open("count.in");
    output << rand() % 5000 << endl;
    output.close();

    return 0;
}