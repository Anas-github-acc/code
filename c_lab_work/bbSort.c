#include<stdio.h>
#include<stdbool.h>
bool bubblesort(int *arr,int n);

bool bubblesort(int *arr,int n){
    bool swap=false;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            arr[i]+=arr[i+1];
            arr[i+1]=arr[i]-arr[i+1];
            arr[i]-=arr[i+1];
            swap=true;
        }
    }
    return swap; 
}
#include<stdio.h>

int main(){
    int n;
    printf("Enter numbrs : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the values of array : ");
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;++i){
        bool swap=bubblesort(arr,n);
        if(swap==false)
        break;
    }
    printf("sorted array : ");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
    return 0;
}
/*output:
Enter numbrs : 7
Enter the values of array : 23 43 1 2 52 2 324
sorted array : 1 2 2 23 43 52 324
*/