//     void sort(int *arr,int n);
void sort(int *arr,int n){
    void swap(int i,int *arr);
    for(int i=1;i<n;++i){
        swap(i,arr);
    }
    return;
}
void swap(int i,int *arr){
    if(arr[i-1]>arr[i]){
        arr[i]+=arr[i-1];
        arr[i-1]=arr[i]-arr[i-1];
        arr[i]-=arr[i-1];}
    else
    return ;
    if(i==1){
        return ;
    }
    swap(i-1,arr);
}