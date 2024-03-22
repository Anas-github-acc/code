from sys import stdin
input=lambda : stdin.readline().strip()

def test():
    s=input()
    n=len(s)
    minx:int=0
    l:int=0
    f_dup:int=0
    f_term=s[0]
    setx=list()
    for i in range(n):
        if s[i] not in setx:
            setx.append(s[i])
        if s[i]==f_term:
            f_dup=l-1
        print(setx, f_dup)
        l=l+1
        if len(setx)>2:
            if(minx==0):
                minx=l
            else:
                minx=min(l,minx)
            del setx[0]
            l=l-f_dup
    print(minx)		

for _ in range(int(input())):
    test()

# from sys import stdin
# input=lambda : stdin.readline().strip()


# def test():
# 	s=input()
# 	n=len(s)
# 	if(n%2==1):
# 		print("NO")
# 		return
# 	ans="YES"
# 	for i in range(n//2):
# 		num:int=abs(ord(s[i])-ord(s[n-i-1]))
# 		if num in (1,2):
# 			continue
# 		else:
# 			ans="NO"
# 	print(ans)

# for _ in range(int(input())):
#     test()