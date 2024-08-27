#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &v, int k, int mid) {
    int cows=1;
    int pos=v[0];

    for(int i=0;i<v.size();i++) {
      if(v[i]-pos>=mid) {
        cows++;
        if (cows==k) {
          return true;
        }
        pos=v[i];
      }
    }
    return false;
}

int aggressiveCows(vector<int> &v, int k) {
    sort(v.begin(), v.end());
    int s=0;
    int e=(v[v.size()-1]-v[0])/(k-1);
    int ans= -1;
    int mid=(e+s)/2;
    while(s<=e) {
      if (isPossible(v,k,mid)) {
        ans=mid;
        s=mid+1;
      }
      else{
        e=mid-1;
      }
      mid=(e+s)/2;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
      int n, k;
      cin >> n >> k;
      vector<int> v;
      for(int i = 0; i < n; i++) {
          int x;
          cin >> x;
          v.push_back(x);
      }
      cout << aggressiveCows(v, k) << endl;
    }
    return 0;
}