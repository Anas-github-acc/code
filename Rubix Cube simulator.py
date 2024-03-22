def algo(mtx,crn):
    if(crn==2):
        crn=3
    elif(crn==3):
        crn=2
    x=mtx[3]
    mtx[3]=mtx[2]
    mtx[2]=x
    if(crn==0):
        x=mtx[1]
    else:
        x=mtx[0]
    i=0
    while(i<4):
        if(i==crn):
            i+=1
            continue
        if(i==3):
            mtx[3]=x
            break
        if(i==crn-1):
            if(crn==3):
                mtx[i]=x
            else:
                mtx[i]=mtx[i+2]
        else:
            mtx[i]=mtx[i+1]
        i+=1
    x=mtx[3]
    mtx[3]=mtx[2]
    mtx[2]=x


import numpy as np
f=[0,0,0,0,0,0]

for i in range(6):
    f[i]=np.empty(4,dtype='O')
    for j in range(4):
        f[i][j]=chr(97+i)+str(j+1)

def print_matrix():
    matrix=f'''\t[{f[0][0]} {f[0][1]}]
\t[{f[0][2]} {f[0][3]}]\n
[{f[4][0]} {f[4][1]}] [{f[1][0]} {f[1][1]}] [{f[5][0]} {f[5][1]}]
[{f[4][2]} {f[4][3]}] [{f[1][2]} {f[1][3]}] [{f[5][2]} {f[5][3]}]\n
\t[{f[2][0]} {f[2][1]}]
\t[{f[2][2]} {f[2][3]}]\n
\t[{f[3][0]} {f[3][1]}]
\t[{f[3][2]} {f[3][3]}]'''
    print(matrix)

print_matrix()
while True:
    face,corner=[int(x) for x in input("--> ").strip().split()]
    if(face<0 or face >5 or corner<0 or corner>3):
        continue
    algo(f[face],corner)
    print_matrix()

