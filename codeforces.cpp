#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using i64 = long long;
#define rep(i,n) for(int i=0; i<int(n); i++)
using namespace std;
 
void testcase(){
    int N; cin >> N;
    vector<int> A(N*2); rep(i,N*2) cin >> A[i];
    int cnt = 0;
    rep(i,N*2) cnt += A[i];
    int m = min(cnt, N*2-cnt);
    cout << (cnt%2) << ' ' << m << '\n';
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    rep(t,T) testcase();
    return 0;
}