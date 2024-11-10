#include<stdio.h>

typedef struct vinay{
    int a;
    char b;
    int* x;
} vinay_short;

int main(){
    int x = 16;
    vinay_short anas = {10,'a',NULL};
    vinay_short devyash = {20,'b', &anas.a};

    printf("%d\n", *devyash.x);
    printf("%d\n",anas.a);
    return 0;
}