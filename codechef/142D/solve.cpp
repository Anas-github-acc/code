#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll Solve(ll arr[], ll n) {
  ll bitwise_or = 0;
  ll ans=0;
  for(int i=0; i<n; i++) {
    bitwise_or |= arr[i];
    if( ((bitwise_or + 1) & (bitwise_or)) == 0LL){
      ans = i + 1;
    }
  },
  if( ans == 0LL ){
    return n;
  }
  return n - ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n];
        for(int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            arr[i] = x;
        }
        sort(arr, arr+n);
        cout << Solve(arr, n) <<endl;
    }
}