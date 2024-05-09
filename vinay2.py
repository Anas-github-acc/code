from sys import stdin
input=lambda : stdin.readline().strip()

def test():
    n,l,r=list(map(int,input().split()))
    print(2**l-1+(n-l),2**r-1+2**(r-1)*(n-r))
    
test()