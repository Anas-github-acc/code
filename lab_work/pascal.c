#include<stdio.h>
#include<math.h>
int main(){
    for(int i=1;i<=7;i++){
        //output spaces
        for(int j=1;j<=7-i;j++){
            printf(" ");
        }
        int l=1;
        for(int k=1;k<=i;k++){
            printf("%3d",l);
            l=l*(i-k)/k;//nCr
        }
        printf("\n");
    }
    return 0;
}
