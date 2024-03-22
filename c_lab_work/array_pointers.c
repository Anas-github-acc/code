#include<stdio.h>
int *max_min(int *arr);
int main(){
    int size=6;
    int arr[size];
    printf("Enter 6 values for array : ");
    for(int i=0;i<size;++i){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    //max and min value
    int *xarr=arr,max=0,min=1000;
    float avg=0;
    for(int i=0;i<6;++i){
        if(*xarr>max)
        max=*xarr;
        if(*xarr<min)
        min=*xarr;
        avg+=*xarr;
        xarr++;
    }
    
    avg/=6;
    printf("max = %d\nmin = %d\naverage = %f",max,min,avg);
    return 0;
}
// output:
// Enter 6 values for array : 4 5 5 43 34 4

// max = 43
// min = 4
// average = 15.833333