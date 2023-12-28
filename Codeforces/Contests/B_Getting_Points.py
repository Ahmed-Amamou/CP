import math
L=[]

t = int(input())
for _ in range(t):
    n, b, c, d = map(int, input().split())

    # Each day: 1 lesson and 2 tasks max
    rac = (n - n % 7) // 7 + 1
    rac -= 1 if n % 7 == 0 else 0
    left = 1
    right = rac
    ans = rac

    while left <= right:
        mid = (left + right) // 2
        if b <= ((mid + 1) // 2) * c + d * mid:
            ans = mid
            right = mid - 1
        else:
            left = mid + 1

    rac2 = (ans + 1) // 2
    ttt = rac2 * c + d * ans
    b -= ttt
    tmp = rac2
    b = max(b, 0)
    tmp += b // c
    tmp += b % c != 0
    print(math.ceil(n - tmp))
