from sys import stdin, stdout
input=lambda :stdin.readline()

from collections import Counter, defaultdict

def nCr(n, r):
    if n<r:
        return 0
    if r==0:
        return 1
    if r==1:
        return n
    if r>n-r:
        r = n-r
    ans = 1
    for i in range(1,r+1):
        ans = ans*(n-r+i)//i
    return ans

# def solve(counter):
#     zeros = counter[0]

#     counter = dict(sorted(counter.items(), key=lambda item: item[1],reverse=True))

#     max_value = list(counter.values())[0]
#     if(list(counter.keys())[0] == 0 and len(counter)>1):
#         max_value+=list(counter.values())[1]
#     elif(zeros>0 and len(counter)>1):
#         max_value+=zeros
        
#     ans = nCr(max_value,2)
#     for i in range(1, len(counter)):
#         if (i==1 and list(counter.keys())[0] == 0):
#             continue
#         if(list(counter.values())[i] > 1 and list(counter.keys())[i] != 0):
#             ans+=nCr(list(counter.values())[i],2)
#     return ans

# equal pairs ---
# def test():
#     n=int(input())
#     a=list(map(int, input().split()))

#     counter = Counter(a)
    
#     print(solve(counter))

# equal pairs (hard) ---
# def test():
#     n=int(input())
#     dic = defaultdict(int)
#     dic[0] = n
#     for _ in range(n):
#         x,y = list(map(int, input().split()))
#         dic[y]+=1
#         dic[0]-=1
#         print(solve(dic), end=' ')
#     print()

def test():
    x,y = list(map(int, input().split()))
    a = list(map(int, input().split()))
    for _ in range(y):
        mina = min(a)
        maxa = max(a)
        a.remove(mina)
        a.remove(maxa)
        a.append(mina+maxa)
        # print(a)
    print(*a)


for _ in range(int(input())):
    test()