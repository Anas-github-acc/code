
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        k=2+k;
        if(a[0] > k && a[1] > k)
            cout<<-1<<endl;
        else
            cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}