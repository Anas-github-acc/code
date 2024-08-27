# Nearly Equal
# def haming_distance(x:str,y:str):
#     count=0
#     for i in range(0,len(x)):
#         if x[i]!=y[i]:
#             count+=1
#     return count

# def testcase():
#     n,m = list(map(int, input().split()))
#     a=input().strip()
#     b=input().strip()
#     min_ham = 101
#     for i in range(0,n-m+1):
#         dis = haming_distance(a[i:i+m],b)
#         min_ham = min(min_ham,dis)
#     print(min_ham)

    
# t:int=int(input())
# while(t):
#     t-=1
#     testcase()

# Redundanrt Array
# from sys import stdin, stdout, setrecursionlimit
# from collections import Counter
# input=lambda :stdin.readline()
# setrecursionlimit(10**6)

# def test():
#     n:int = int(input())
#     a = sorted(list(map(int, input().split())))
#     c = Counter(a)
#     max_val = max(c.values())
#     c_keys = list(c.keys())
#     min_cal = 4 * 10**10 + 1
#     for x in c:
#         min_cal = min(min_cal, (n-c[x])*x)
#         if c[x] == max_val:
#             break

#     print(min_cal)

# for _ in range(int(input())):
#     test()

# Amphibian Escape
from sys import stdin, stdout
input=lambda :stdin.readline()

def test():
    n,k,h = list(map(int, input().split()))
    miss = h//k
    if (h/k*10) % 10 == 0:
        miss -= 1
    rem_half = (n-h+2)*(n-h+1)//2
    print(n*(n-1)//2 - (miss)*(n-1) + rem_half if n-h+1>0 else 0)
    

for _ in range(int(input())):
    test()