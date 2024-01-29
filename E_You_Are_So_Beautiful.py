for i in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    for j in range(n):
        l=0
        r=1+j
        while(j<=n):
            if(a.count(a[l:r])):
