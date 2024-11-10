#include<stdio.h>
#include<math.h>
int rev(int num,int len){
    if(len==1)
    return num%10;
    int p=pow(10,len-1);
    if((len-1)%2==0)
    p++;
    return (num%10)*p+rev(num/10,len-1);
}
int main(){
    int n;
    printf("Enter the no.: ");
    scanf("%d",&n);
    int nlen=n,l=0;
    while(nlen!=0){
        l++;
        nlen/=10;
    }
    int rev(int n,int l);
    printf("reverse = %d",rev(n,l));
    return 0;
}
