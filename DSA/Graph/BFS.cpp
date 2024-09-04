/*
1.BFS Spanning tree of a graph is best method to find BFS traversal of a graph
-------------------------------------------------------
 
2.BFS traversal of a graph -- below code
*/

#include <iostream>
using namespace std;

class queue {
  public:
    int size;
    int f;
    int r;
    int *arr;

    bool isFull() {
      return r==size-1;
    }

    bool isEmpty() {
      return f==r;
    }

    bool enqueue(int val) {
      if (isFull()) {
        cout<<"Queue is full"<<endl;
        return 0;
      }else{
        r++;
        arr[r] = val;
      }
      return 1;
    }

    int dequeue() {
      int a=-1;
      if (isEmpty()) {
        cout<<"Queue is empty"<<endl;
      }else{
        f++;
        a=arr[f];
      }
      return a;
    }
};

int main () {
  queue q;
  q.size = 400;
  q.r = q.f = 0;
  q.arr = (int*) malloc(q.size * sizeof(int));

  int node;
  int i=0;
  int visited[7] = {0};
  int adj[7][7] = {
    {0, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0}
  };
  visited[i] = 1;
  cout<<i<<" ";
  q.enqueue(i);
  while(!q.isEmpty()) {
    int node = q.dequeue();
    for (int j=0; j<7; j++) {
      if(adj[node][j] == 1 && visited[j] == 0) {
        cout<<j<<" ";
        visited[j] = 1;
        q.enqueue(j);
      }
    }
  }


  return 0;
}