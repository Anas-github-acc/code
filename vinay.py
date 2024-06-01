from sys import stdin
input=lambda :stdin.readline()
from collections import defaultdict

def test():
    n = int(input().strip())
    s = input().strip()
    e=0
    dic = defaultdict(int)
    t=0
    for i in range(n):
        if s[i] == '0':
            t-=1
        else:
            t+=1
        if t == 0:
            e+=1
        if t in dic:
            e+=dic[t]
        dic[t]+=1
    print(e+n*(n+1)//2)

for _ in range(int(input())):
    test()