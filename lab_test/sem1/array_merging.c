#include<stdio.h>
void place(int arr[],int n)
{
    int temp[2*n];
    int j=0;
    for(int i=0;i<n;++i){
        temp[j]=arr[i];
        j++;
        temp[j]=arr[i+n];
        j++;
    }
    for(int i=0;i<2*n;++i){
        printf("%d ",temp[i]);
    }
}
void place(int arr[],int n);
int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[2*n];
    printf("Enter the element: ");
    for(int i=0;i<2*n;++i){
        scanf("%d",&arr[i]);
    }
    place(arr,n);
    return 0;
}