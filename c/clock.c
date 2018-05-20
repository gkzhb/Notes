#include <stdio.h>
#include <time.h>

int maintain(double dur, double start);

int main(void)
{
    double time, n;
    time = (double)clock();
    puts("Please enter the seconds you hope this program will run:");
    scanf("%lf", &n);
    maintain(n, time);
    printf("The program runs %.2lf seconds.", ((double)clock() - time) / CLOCKS_PER_SEC);
    return 0;
}

int maintain(double dur,double start)
{
    while (dur-((double)clock()-start)/CLOCKS_PER_SEC>0)
        ;
    return 0;
}