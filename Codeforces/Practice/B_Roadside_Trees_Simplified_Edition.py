n=int(input())
L=[]
for i in range(n):
    L.append(int(input()))
units=L[0] + 1
for i in range(1,n):
    if L[i]>=L[i-1]:
        units+=L[i]-L[i-1] + 2
    else:
        units+=L[i-1] - L[i]  + 2

print(units)