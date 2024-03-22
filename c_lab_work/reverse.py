def anas_split(x):
    bypass_array=[]
    initial=0
    for i in range(len(x)):
        if x[i] == " " or x[i] == "$":
            bypass_array.append(x[initial:i])
            initial=i+1
    return bypass_array
sentence=input("Enter your  sentence: ")
sentence = anas_split(sentence+"$")

for j in range(len(sentence)):
    for i in range(len(sentence[j])-1,-1,-1):
        print(sentence[j][i],end="")
    print(end=" ")