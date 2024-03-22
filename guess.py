from sys import stdin, stdout
input=lambda :stdin.readline()

n,A,B=list(map(int,input().split()))
arr:int=list(map(int,input().split()))
f=arr[0]
S:int=0
for x in arr:
    S+=x
if (arr[0]*A)/S>=B:
    print(0)
    exit()
arr=sorted(arr[1:],reverse=True)
flag=False
for i in range(len(arr)):
    S-=arr[i]
    if (f*A)/S>=B:
        break
print(i+1 )