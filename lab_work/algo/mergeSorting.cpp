#include<iostream>
using namespace std;

int* merge(int arr1[], int arr2[], int n1, int n2) {
    int* arr = new int[n1 + n2];
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }
    while(i < n1) {
        arr[k++] = arr1[i++];
    }
    while(j < n2) {
        arr[k++] = arr2[j++];
    }
    return arr;
}

int* mergeSort(int arr[], int n) {
    if(n == 1) {
        return arr;
    }
    int mid = n / 2;
    int* left = new int[mid];
    int* right = new int[n - mid];
    for(int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for(int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
    left = mergeSort(left, mid);
    right = mergeSort(right, n - mid);
    return merge(left, right, mid, n - mid);
}
int* mergeSort(int arr[], int n){
    int mid = n/2;
    int* l = new int[mid];
    int* r = new int[n-mid];
    for(int i = 0; i < mid; i++){
        l[i] = arr[i];
    }
    for(int i = mid; i < n; i++){
        r[i-mid] = arr[i];
    }
    l = mergeSort(l, mid);
    r = mergeSort(r, n-mid);
    return merge(l, r, mid, n-mid);
}

int main() {
    return 0;
}