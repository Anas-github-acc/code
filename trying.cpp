#include <bits/stdc++.h>

#define ll long long int
using namespace std;

// Kadane's Algorithm
int maxSubarray(int arr[], int n){
  int maxSoFar=INT_MIN, maxEndingHere=0;
  cout<<"n = "<<n<<endl;
  for(int i=0;i<n;i++){
    maxEndingHere=maxEndingHere+arr[i];
    if( maxSoFar<maxEndingHere){
      maxSoFar=maxEndingHere; 
    }
    if(maxEndingHere<0){
      maxEndingHere=0;
    }
    cout<<"--> "<< maxEndingHere<<endl;
  }
  return maxSoFar;
}

int main() {
    int arr[3] = {3,-1,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<maxSubarray(arr, size)<<endl;
    return 0;
}

// int main() {
//     ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
//     ll t;
//     cin >> t;
//     while(t--) {
//         test();
//     }
//     return 0;
// }