from sys import stdin, stdout
input=lambda :stdin.readline()

def test():
    n = int(input())
    a = [i for i in input().strip()]

    reoccur=0
    for i in range(n):
        if(i<n-1 and a[i] == a[i+1]):
            reoccur+=1

    rndScore = 0
    for i in range(n):
        if(i<n-1 and a[i] != a[i+1]):
            rndScore+=1

    score=0
    f=0
    for i in range(reoccur):
        if(rndScore==0 or rndScore==1):
            score+=rndScore
            break
        f+=1
        if(f<3):
            score+=rndScore
            continue
        f=0
        rndScore-=1
    
    print(score)

    
    
    

for _ in range(int(input())):
    test()