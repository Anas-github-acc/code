//  --------- string comprssion : Interview Important

//-------- sum of 2 arrays
// #include <bits/stdc++.h>

// #define ll long long int
// using namespace std;

// vector<ll> solve(vector<ll> &v1, vector<ll> &v2) {
//   ll i = v1.size();
//   ll j = v2.size();
//   ll carry = 0;

//   vector<ll> v3;
//   while(i >= 0 || j >= 0) {
//     i--;
//     j--;
//     if (i < 0 && j < 0) {
//       if(carry > 0) {
//         v3.insert(v3.begin(), carry);
//       }
//     } else if(i < 0) {
//       v3.insert(v3.begin(), (v2[j] + carry)%10);
//     } else if (j < 0) {
//       v3.insert(v3.begin(), (v1[i] + carry)%10);
//     } else {
//       v3.insert(v3.begin(), (v2[j] + v1[i] + carry)%10);
//       carry = (v2[j] + v1[i])/10;
//     }
//   }

//   return v3;
// }

// int main() {
//     ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
//     ll t;
//     cin >> t;
//     while(t--) {
//         ll n, m;
//         cin >> n >> m;
//         vector<ll> v1;
//         vector<ll> v2;
//         for(int i = 0; i < n; i++) {
//             ll x;
//             cin >> x;
//             v1.push_back(x);
//         }
//         for(int i = 0; i < m; i++) {
//             ll x;
//             cin >> x;
//             v2.push_back(x);
//         }
//         vector<ll> v3 = solve(v1, v2);
//         for(int i: v3){
//             cout << i << " ";
//         }
//     }
// }


//-------- merge 2 array
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> mergeArr(vector<int> &v1, vector<int> &v2) {
//   vector<int> v3;

//   auto i = v1.begin();
//   auto j = v2.begin();
//   while( i != v1.end() || j != v2.end()) {
//     if((*i <= *j) || j == v2.end()){
//       v3.push_back(*i);
//       i++;
//     } else {
//       v3.push_back(*j);
//       j++;
//     }
//   }
//   return v3;
// }

// int main(){
//   vector<int> v1 = {1, 4, 5, 5, 7};
//   vector<int> v2 = {2, 3, 5, 6, 8, 9};

//   vector<int> v3;

//   v3 = mergeArr(v1, v2);
//   for(int i: v3){
//     cout << i << " ";
//   }
//   return 0;
// }