from sys import stdin, stdout
from collections import defaultdict
input=lambda :stdin.readline()


def test():
    n,m = map(int, input().split())
    matrix = [[0]*m for _ in range(n)]
    for i in range(n):
        matrix[i] = list(map(int, input().split()))

    A=[[]*n]
    K=[[]*n]

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                A[i].append(j)
            elif matrix[i][j] == 2:
                K[i].append(j)
            elif matrix[i][j] == 3:
                A[i].append(j)
                K[i].append(j)

    # print(A, K)
    
    for y1 in range(m):
      val=0
      for y2 in range(len(A[0])):
          val+=abs(A[0][y2]-y1)
      for y2 in range(len(K[0])):
          val-=abs(K[0][y2]-y1)
      print(abs(val), end=" ")
    print()
            


for _ in range(int(input())):
    test()