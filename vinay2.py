def factorial(x):
    if x == 0 or x == 1:
        return 1
    f = 1
    for i in range(2, x + 1):
        f *= i
    return f

def binomial_coeff(n, k):
    return factorial(n) // (factorial(k) * factorial(n - k))

def distribution_ways(n, r):
    total = 0
    for i in range(r + 1):
        sign = (-1) ** i
        term = binomial_coeff(r, i) * (r - i) ** n
        total += sign * term
    return total

# Reading input
t = int(input())
results = []
for _ in range(t):
    n, r = map(int, input().split())
    if r > n:
        results.append(0)  # Impossible to give each person at least one ball
    else:
        results.append(distribution_ways(n, r))

# Printing results
for result in results:
    print(result)