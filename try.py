from sys import stdin, stdout
input=lambda :stdin.readline()

prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199}
def is_prime(n):
    return prime[n]

def test():
    n:int = int(input())
    a = list(map(int, input().split()))

    diff = [0] * n-1
    for i in range(n-1):
        diff[i] = a[i+1] - a[i]

    for i in range(n):
        # for j in range(i+1, n):
        #     if not is_prime(a[i] + a[j]):
        #         print(i+1, j+1)
        #         return    
        x = a[i]+diff[i]
        if not is_prime(x):
            print(i, i+1)
            return
    print(-1)
    return

for _ in range(int(input())):
    test()