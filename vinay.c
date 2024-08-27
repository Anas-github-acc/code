// from sys import stdin, stdout
// input=lambda :stdin.readline()

// prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199}

// def is_prime(n):
//     return prime[n]

// def test():
//     n:int = int(input())
//     a = list(map(int, input().split()))

//     for i in range(n):
//         for j in range(i+1, n):
//             if (a[i] + a[j]) not in prime:
//                 print(i+1, j+1)
//                 return    
//     print(-1)
//     return

// for _ in range(int(input())):
//     test()

// convert this to c

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

set<ll> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

bool is_prime(ll n) {
    return prime.count(n);
}

void test() {
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(prime.count(a[i] + a[j]) == 0) {
                cout << i+1 << " " << j+1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
}