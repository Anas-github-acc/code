from sys import stdin, stdout
input=lambda :stdin.readline()

def test():
    n:int=int(input())
    p=list(map(int,input().strip().split()))
    for i in range(n):
        print()
    

for _ in range(int(input())):
    test()