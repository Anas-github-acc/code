#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));  
    FILE *fp = fopen("./testcase/input4.txt", "w");
    int n = rand() * (RAND_MAX + 1) + rand();
    n = n % 500;
    // n = 500;
    fprintf(fp, "%d\n", n);
    for(int i=0;i<n;i++)
    {
        int x = rand() * (RAND_MAX + 1) + rand();
        int y = rand() * (RAND_MAX + 1) + rand();
        if (x > 100) {
            x = x % 100;
        }
        if (y > 60 ){
            y = y % 60;
        }
        if (x > 60){
            y = y % (x-30);
        }
        if (x > 50 ){
            y = y % (x-25);
        }
        if ( x > 45 ){
            y = y % (x-20);
        }
        if ( x > 20 ){
            y = y % (x-10);
        }
        if( x > 0){
            y = y % x;
        }
        if( x == 0 ){
            int temp = x;
            x = y;
            y = temp;
        }
        if(y > x) {
            printf("%d %d\n", x,y);
        }
        // printf("%d %d\n", x,y);
        fprintf(fp, "%d %d\n", x,y);
    }
    fprintf(fp,"\n");
}