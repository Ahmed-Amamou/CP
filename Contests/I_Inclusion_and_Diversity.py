from math import * 
n = int(input())
print((factorial(n)//(factorial(n-n//2)*factorial(n//2)))% 998244353)