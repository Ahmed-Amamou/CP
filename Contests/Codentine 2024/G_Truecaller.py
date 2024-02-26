d = {}
n = int(input())
for _ in range(n):
    name, number = input().split()
    d[name] = {}
    for i in number:
        if i not in d[name]:
            d[name][i] = 0
        d[name][i] += 1


q = int(input())
g = {}
for _ in range(q):
    for k, v in d.items():
        g[k] = v.copy()
    # g = d.copy()
    # print("mahdi", g['Mahdi'])
    selected = n
    names = {i:0 for i in d.keys()}
    known = list(input().split()[1])
    for i in known:
        for name, number in g.items():
            if selected <=0:
                break
            if names[name] != -1 :
                if i in number and number[i]>0:
                    number[i]-=1
                    names[name] += 1
                else:
                    names[name] = -1
                    selected -= 1
    if selected <= 0:
        print("NONE")
    elif selected > 1:
        print("MANY")
    else:
        for name, target in names.items():
            if target != -1:
                print(name)
                break
    
    