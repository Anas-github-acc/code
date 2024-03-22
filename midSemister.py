def binary_search():

def bs(arr, low, high, x, flag):
    if(flag==2):
        qmid=[]
    if high >= low:
        mid = (high + low) // 2
        if arr[mid] == x:
            if(flag==1):
                return mid
            else:
                if(mid==low or mid==high):
                    qmid.append(mid)
                else:
                    while(arr[mid]==arr[mid+1]):
                        qmid.append(mid+1)
                        if(mid+1==high):
                            break
                    while(arr[mid]==arr[mid-1]):
                        qmid.append(mid-1)
                        if(mid-1==low):
                            break
                return qmid
        elif arr[mid] > x:
            if(mid==low):
                return -1
            while(arr[mid-1]==arr[mid]):
                if(mid-1==low):
                    return -1
                mid-=1
            return bs(arr, low, mid - 1, x, flag)
        else:
            if(mid==high):
                return -1
            while(arr[mid+1]==arr[mid]):
                if(mid+1==high):
                    return -1
                mid+=1
            return bs(arr, mid + 1, high, x, flag) 
    else:
        return -1

def qs(arr,arr2, low, high):
  if low < high:
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i = i + 1
            (arr[i], arr[j]) = (arr[j], arr[i])
            (arr2[i], arr2[j]) = (arr2[j], arr2[i])
    (arr[i + 1], arr[high]) = (arr[high], arr[i + 1])
    (arr2[i + 1], arr2[high]) = (arr2[high], arr2[i + 1])
    pivot = i+1
    qs(arr,arr2, low, pivot - 1)
    qs(arr,arr2, pivot + 1, high)    
    
exam=[]
ans=[]
t:int=int(input())
while(t):
    frm=[]
    tom=[]
    t-=1
    n,m=[int(x) for x in input().strip().split()]
    for i in range(m):
        a,b=input().strip().split()
        frm.append(int(a))
        tom.append(int(b))
    qs(frm,tom,0,len(frm)-1)
    lex=0
    for i in range(n):
        if(bs(frm,0,m-1,i,1)>-1):
            continue
        else:
            lex+=1
            exam.append(i)
    qs(tom,frm,0,m-1)
    lan=0
    print(tom,exam)
    for i in range(lex):
        list=bs(tom,0,m-1,exam[i],2)
        if(list[0]>-1):
            if(bs(ans,0,lan-1,frm[i],1)):
                pass
            else:
                lan+=1
                for i in lst:
                    ans.append(frm[i])
    ans+=exam
    for i in sorted(ans):
        print(i,end=" ")