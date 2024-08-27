#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int test() {
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
    }

    set<ll> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(prime.find(a[i] + a[j]) == prime.end()) {
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll t;
    cin >> t;
    while(t--) {
        test();
    }
    return 0;
}