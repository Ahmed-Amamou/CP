t = int(input())
while t:
    t -= 1
    n = int(input())
    s = input()
    count_zero = 0
    count_one = 0
    for i in range(n):
        if s[i] == '0':
            count_zero += 1
        else:
            count_one += 1
    print(count_one*n + count_zero - count_one)