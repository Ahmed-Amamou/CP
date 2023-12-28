t=int(input())
while(t>0):
    n=int(input())
    s=input()
    if("..." in s):
        print(2)
    else:
        print(s.count('.'))

    t-=1
        

