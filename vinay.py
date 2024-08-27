def haming_distance(x:str,y:str):
    count=0
    for i in range(0,len(x)):
        if x[i]!=y[i]:
            count+=1
    return count

def testcase():
    n,m = list(map(int, input().split()))
    a=input().strip()
    b=input().strip()
    min_ham = 101
    for i in range(0,n-m+1):
        dis = haming_distance(a[i:i+m],b)
        min_ham = min(min_ham,dis)
    print(min_ham)

    
t:int=int(input())
while(t):
    t-=1
    testcase()