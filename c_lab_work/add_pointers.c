#include<stdio.h>

int add(int *,int *);
int main(){
    int *p1,*p2,x=0,y=0;
    p1=&x,p2=&y;
    printf("Enter the two numbers to add : ");
    scanf("%d %d",&x,&y);
    printf("add = %d",add(p1,p2));
}
int add(int *a,int *b ){
    return *a + *b;
}