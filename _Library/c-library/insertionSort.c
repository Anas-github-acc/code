#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ll long long int

void insertionSort(ll arr[], ll n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(ll arr[], ll n)
{
    for (ll i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 100000;
    ll arr[n];

    for( ll i=0; i<n;i++) {
      arr[i]=n-i;
    }

    n = sizeof(arr) / sizeof(arr[0]);

    time_t time1, time2; 
    time(&time1);
    insertionSort(arr, n);
    // printArray(arr, n);
    time(&time2); 
    printf("Difference is %.2f seconds", 
           difftime(time2, time1));

    return 0;
}