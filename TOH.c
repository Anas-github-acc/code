#include<stdio.h>
void tower_of_hanoi(int n,char from,char to,char aux)
{
    if(n==1){
        printf("Move disk 1 from %c to %c\n",from,to);
        return;
    }
    tower_of_hanoi(n-1,from,aux,to);
    printf("Move disk %d from %c to %c\n",n,from,to);
    tower_of_hanoi(n-1,aux,to,from);
}
int main()
{
    while (1){
        int n;
        printf("Enter the number of disks: ");
        scanf("%d",&n);
        tower_of_hanoi(n,'A','C','B');
    }
    return 0;
}