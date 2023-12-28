a1,a2,a3,a4=map(int,input().split())
s=input()
D={1:[a1,0],2:[a2,0],3:[a3,0],4:[a4,0]} #Dictionnaire key are strip numbers
                    #values are sum of calories each one

for i in s:
    i=int(i)
    D[i][1]+=D[i][0]

somme=0
for j in (D.values()):
    somme+=j[1]
print(somme)
