#include <iostream>
using namespace std;

int inMST[7] = {0,1,2,3,4,5,6};
int notInMST[7] = {-1};
int adj[7][7] = {
  {0, 1, 1, 0, 0, 0, 0},
  {1, 0, 0, 1, 1, 0, 0},
  {1, 0, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 1, 0, 0},
  {0, 1, 1, 1, 0, 1, 0},
  {0, 0, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 0, 1, 0}
};

int MST(int a) {
  notInMST[0] = a;

  return -1;
}


int main() {
  MST(0);
  return 0;
}