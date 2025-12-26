# Advent of Code - DAY 2

def solve(file):
    sum=0
    for line in file:
        x = list(map(int,line.split()))
        asc, desc, diff = True,True,True
        for i in range(1,len(x)):  
            if(x[i]<=x[i-1]):
                asc=False
            if(x[i]>=x[i-1]):
                desc=False
            if(abs(x[i]-x[i-1])>3): diff = False
        if((asc or desc) and diff): sum+=1
    return sum

if __name__ == '__main__':
    with open("DAY 2 - input.txt","r") as file:
        ans = solve(file)
        print(ans)
