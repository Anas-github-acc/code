# cook your dish here
from sys import stdin, stdout
input=lambda :stdin.readline()


def isPrime(n):
    if n<=1:
        return False
    if n<=3:
        return True
    if n%2==0 or n%3==0:
        return False
    i=5
    while i*i<=n:
        if n%i==0 or n%(i+2)==0:
            return False
        i+=6
    return True

def find_nearest_prime(n):
    if isPrime(n):
        return n
    for i in range(n,2*n):
        if isPrime(i):
            return i
    return 0

def find_next_prime(n):
    for i in range(n+1,2*n):
        if isPrime(i):
            return i
    return 0
            

def TESTCASE():
    x=int(input())
    if(x==1 or x==1):
        print(6)
        return
    a=find_nearest_prime(x)
    print(a*find_next_prime(a))
    
    
t=int(input())
for _ in range(t):
    TESTCASE()