#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define ll long long int

void merge(ll arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(ll arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(ll a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int n = 100000;

    ll arr[n];

    for( int i=0; i<n;i++) {
      arr[i]=n-i;
    }

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    time_t time1, time2; 
    time(&time1); 
    mergeSort(arr, 0, arr_size - 1);
    // printArray(arr, arr_size);
    time(&time2); 
    printf("Difference is %.2f seconds", 
           difftime(time2, time1));
    return 0;
}
