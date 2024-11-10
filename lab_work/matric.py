print("Enter the size of matrixs:")
m1 ,n1 = map(int, input().split())
m2 ,n2 = map(int, input().split())
mtx1 = [] 
mtx2 = []
print("Enter Matrix values respectively :")
for i in range(m1):
    row = list(map(int, input().split()))
    mtx1.append(row)
for i in range(m2):
    row = list(map(int, input().split()))
    mtx2.append(row)

result = [[0 for _ in range(len(mtx2[0]))] for _ in range(len(mtx1))]
for i in range(len(mtx1)):
    for j in range(len(mtx2[0])):
        for k in range(len(mtx2)):
            result[i][j] += mtx1[i][k]*mtx2[k][j]

for row in result:
    print(row)
