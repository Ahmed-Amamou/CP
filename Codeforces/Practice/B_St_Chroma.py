t= int(input())
while t:
    t-=1
    n,x = map(int,input().split())
    ans = []
    if x == 0:
        ans = [str(i) for i in range(n-1,-1,-1)]
        print(' '.join(ans))
        continue
    last = -1
    for i in range(0,x):
        ans.append(str(i))
        last = i
    for i in range(n-1,last,-1):
        ans.append(str(i))
    print(' '.join(ans))