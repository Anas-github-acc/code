#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include <math.h>

#define ld long int
#define ud unsigned int

// generating random numbers using Linear Congruential Generator
// i learned it in maths classes so i thought of using it here
void LCG(ud r[], ud n, int seed){
    ud a = (ud)pow(7, 5);
    ud m = (ud)pow(2, 31) - 1;
    int c = 0;
    int p = n;
    int q = 0;
    int x[2] = {0};
    x[0] = seed;
    r[0] = p + (q - p) * (x[0] / (double)m);

    for(ud i = 1; i < n; i++){
        x[1] = (a * x[0] + c) % m;
        x[0] = x[1];
        r[i] = p + (q - p) * (double)(x[1] / (double)m);
    }
}

// generating prime numbers upto 2^15 using Sieve of Eratosthenes with
// time complexity : O(nloglogn)
// this will only run once in the start of the program so we dont have to
// worry about looping for finding if the number is prime or not
bool prime[100000];
void SieveOfEratosthenes(bool prime[], int n)
{
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

// this find the number of prime numbers in a composite number
int primeInComposite(int n){
    int count = 0;
    int a[4] = {2,3,5,7};
    while(n>0){
        int rem = n%10;
        for(int i=0; i<4; i++){
            if(rem == a[i]){
                count++;
                break;
            }
        }
        n = n/10;
    }
    return count;
}

void merge(ud arr[], int l, int m, int r)
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
      // checking all the possible condition for sorting
      // if both the no. is prime then sort them in ascending order 
      if(prime[L[i]] && prime[R[j]]){
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
      }
      // if both the no. is composite then sort them -
      else if(!prime[L[i]] && !prime[R[j]]){
        // check the number of prime digits in the composite number and sort ascendingly according to the number of prime digits
        if(primeInComposite(L[i]) < primeInComposite(R[j])){
          arr[k] = L[i];
          i++;
        }
        // if the number of prime digits are same then sort them in ascending order
        else if(primeInComposite(L[i]) > primeInComposite(R[j])){
          arr[k] = R[j];
          j++;
        } 
        else {
          if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
          }
          else {
            arr[k] = R[j];
            j++;
          }
        }
      }
      // if one of the no. is prime and other is composite then prime comes first
      else if(prime[L[i]] && !prime[R[j]]){
        arr[k] = L[i];
        i++;
      }
      else if(!prime[L[i]] && prime[R[j]]){
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

void mergeSort(ud arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
    return;
}

void printArr(ud A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int Solve(){
    int p =1<<15;
    int n =p-1;
    int q =0;
    ud arr[p];

    time_t seed;
    seed = time(NULL);
    LCG(arr, n, seed);
    for(ud i=0;i<=p;i++) {
      arr[i] = rand() % (p - q + 1) + q;
    }
    printf("Generated Array upto 2^15 : \n");
    printArr(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("\nSorted Array : \n");
    printArr(arr, n);
    return 0;
}

int main(){
  int t = 1;
  memset(prime, 1, sizeof(prime)); // this will set array to true
  SieveOfEratosthenes(prime, 1<<15); // function to generate prime numbers upto 2^15
  while(t--){
    Solve();
  }
  return 0;
}