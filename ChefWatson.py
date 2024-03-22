N,M= map(int,input().split())
MI=set(map(int,input().split()))
mii=-1
ans=[]
start=0
for i in range(M):
    f,p,*s=input().split()
    p=[int(f),int(p)]
    flag=0
    end=len(ans)
    j=start
    if(p[0] in MI):
        MI.remove(p[0])
        mii+=1
        start=mii+1
        end=mii
        j=0
    if(i==0):
        ans.append(p)
        continue
    if(j==end):
        pass
    else:
        while( p[1]<=ans[j][1] ):
            j+=1
            if(j==end):
                break
    ans.insert(j,p)
for i in ans:
    print(i[0],end=' ')
