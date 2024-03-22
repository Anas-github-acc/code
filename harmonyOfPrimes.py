def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True
    
def sumOfFactors(n):
    sum = 0
    d = 2

    while d <= n:
        if n % d == 0 and isPrime(d):
            sum += d
            n //= d
        else:
            d += 1

    return sum
print(sumOfFactors(20))