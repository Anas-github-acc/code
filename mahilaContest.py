def find_duplicate(a):
    from collections import Counter 
    a=Counter(a)
    a=sorted(a.items(), key=lambda pair: pair[1], reverse=True)
    return a[0][0]

print(find_duplicate([2,34,4,34,5]))