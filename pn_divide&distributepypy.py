# import sys
# sys.set_int_max_str_digits(1000000000)

# from math import comb
# def count_ways(n, k):
#     total = 0
#     for i in range(k):
#         total += ((-1) ** i) * comb(k, i) * ((k - i) ** n)
#     return total
# t = int(input())

# for _ in range(t):
#     n, k = map(int, input().split())
#     x = count_ways(n, k)
#     if x >= 1e5:
#         ans = "{:.6e}".format(x)
#     else:
#         ans = str(x)
#     print(ans)

from sys import stdin, stdout
input=lambda :stdin.readline()

def factorial(x):
    if x == 0 or x == 1:
        return 1
    f = 1
    for i in range(2, x + 1):
        f *= i
    return f

def binomial_coeff(n, k):
    return factorial(n) // (factorial(k) * factorial(n - k))

def test():
    n, r = map(int, input().split())
    total = 0
    for i in range(r + 1):
        sign = (-1) ** i
        term = binomial_coeff(r, i) * (r - i) ** n
        total += sign * term
    if total >= 1e5:
        ans_org = "{:.6e}".format(total)
    else:
        ans_org = total
    print(ans_org)

for _ in range(int(input())):
    test()