from sys import stdin, stdout
import math
input=lambda :stdin.readline()

def test():
    # n:int=int(input())
    # f=sorted(list(map(int,input().strip().split())))
    n,x=2,1000
    f = [1, 1]
    if(f[0]>=x):
        print(0)
        return ""
    mean_x = x
    diff = 0
    ans = 0
    for i in range(1,n+1):
        try:
            diff += f[i] - f[0]
        except:
            ans+=(mean_x - f[0] + 1)*i
            break

        m = mean_x - (x-(diff))//(i+1)
        mean_x = (x-(diff))//(i+1)
        ans += i*m
        print(f"m={m} mean_x={mean_x} diff={diff} ans={ans}")
    print(ans)
    # sf = sum(f)
    # flag = n
    # ans = 0
    # loop=0
    # while flag:
    #     print(sf,end=" ")
    #     sf-=(f.pop()+loop)
    #     print(((x-sf)//flag)*flag)
    #     ans+=((x-sf)//flag)*flag
    #     loop += 1
    #     flag -=1
        # print(f"sf={sf} {flag}")
        # print(flag)
    # print(ans)

    

for _ in range(int(input())):
    test()