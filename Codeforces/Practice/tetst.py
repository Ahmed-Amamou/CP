a = "ffrffffrrfflfffff"
x = 0
y = 0
j =0
L = [[0,1],[1,0],[0,-1],[-1,0]]
direction = L[j%4]
for c in a:
    if(c == 'r'):
        j+=1
        direction = L[j]
    elif(c=='l'):
        j-=1
        direction = L[j]
    else:
        x+=direction[0]
        y+=direction[1]
print(x,y)
res = ""
if(y>0):
    res+="f"*y
if(y<0):
    res+="rr"+'f'*abs(y)
if(y>0 and x>0):
    res+='r' + "f"*x
if(y<0 and x>0):
    res+='l' + "f"*x
if(y>0 and x<0):
    res+='l' + "f"*x
if(y<0 and x<0):
    res+='r' + "f"*x
print(res)
    
    