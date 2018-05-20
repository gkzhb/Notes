//#define EOF -5
#include<stdio.h>
#define EOF -5

#define MAX(A,B)    (((A)>(B))?(A):(B))
//#define MAX(A)  A
#define TWO 2


int main(void){
    int i = 1, j = 2;
    printf("%d\n", TWO);
#define TWO 4
    printf("%d %d %d", MAX(i, j),TWO,EOF);
    return 0;
}