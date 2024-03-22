# cook your dish here
def testcase(t):
    n=int(input())
    x=int(input())
    A=list(map(int,input().split()))
    xor=0
    for i in range (0,n):
      xor=xor|A[i] 

t=int(input())
while(t):
    t-=1
    result = testcase(t)
    print(result)  