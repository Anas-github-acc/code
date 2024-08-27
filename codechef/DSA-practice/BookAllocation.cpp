#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

bool isPossible(vector<int> v, int n, int m, int mid) {
  int t_m = 1;
  int t_sum = 0;
  for(int x: v) {
    if(x+t_sum <= mid) {
      t_sum += x;
    }else{
      t_m++;
      if(t_m > m || x > mid) {
        return false;
      }
      t_sum = x;
    }
  }
  return true;
}

int AllocateBook(vector<int> v, int n, int m) {
  int s=0;
  int sum = accumulate(v.begin(), v.end(), 0);
  int e=sum;
  int ans=-1;
  int mid=(e+s)/2;

  while(s<=e){
    if(isPossible(v, n, m, mid)) {
      ans=mid;
      e=mid-1;
    }else{
      s=mid+1;
    }
    mid=(e+s)/2;
  }
  return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
      int n, m;
      cin >> n >> m;
      vector<int> v;
      for(int i = 0; i < n; i++) {
          int x;
          cin >> x;
          v.push_back(x);
      }
      cout << AllocateBook(v, n, m) << endl;
    }
    return 0;
}