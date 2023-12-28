t=int(input())
while(t>0):
    a,b,c=map(int,input().split())
    ans={"first":0,"second":0,"third":0}
    if a%2==0 and b%2==0 and c%2==0 or a%2!=0 and b%2!=0 and c%2!=0:
        print("1 1 1")
    else:
        if a%2==0 and b%2==0 or a%2!=0 and b%2!=0 :
            ans["third"]=1
        elif a%2==0 and c%2==0 or a%2!=0 and c%2!=0:
            ans["second"]=1
        elif b%2==0 and c%2==0 or b%2!=0 and c%2!=0:
            ans["first"]=1

        print(" ".join(map(str, ans.values())))
            




    t-=1
