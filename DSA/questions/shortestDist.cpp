#include <bits/stdc++.h>

#define ll long long int
using namespace std;
class MyQueue {
  public:
    int size;
    int f;
    int r;
    int *arr;

    bool isFull() {return r==size-1;}
    bool isEmpty() {return f==r;}
    bool enqueue(int val) {
      if (isFull()) {return 0;}
      else{
        r++;
        arr[r] = val;
      }
      return 1;
    }
    int dequeue() {
      int a=-1;
      if (isEmpty()) {return -1;}
      else{
        f++;
        a=arr[f];
      }
      return a;
    }
};

int test() {
  int n,q;
  cin>>n>>q;

  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  
  // matrix representation of graph
  int g[n][n] = {0};
  for(int i=0; i<n; i++) {
    for(int j=0;j<n;j++) {
      if(j>i && j<=i+a[i]){
        g[i][j]=1;
        continue;
      }
      g[i][j] = 0;
    }
  }

  // printing graph
  // for(int i=0;i<n;i++){
  //   for(int j:g[i]){
  //     cout<<j<<" ";
  //   }
  //   cout<<endl;
  // }

  for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    x--;
    y--;

    MyQueue q;
    q.size = 5*100000 + 1;
    q.r = q.f = 0;
    q.arr = new int[q.size];

    vector<int> par;
    int vst[n] = {0};
    vst[0]=x;
    q.enqueue(x);
    while(!q.isEmpty()) {
      int node = q.dequeue();

      for(int j=0;j<n;j++) {
        if(g[node][j] == 1 && vst[j] == 0) {
          vst[j] = 1;
          q.enqueue(j);
        }
      }
    }
  }
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