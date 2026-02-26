import sys
import math
import bisect
import heapq
from collections import defaultdict, deque, Counter
from itertools import accumulate, permutations, combinations

# Fast I/O
input = lambda: sys.stdin.readline().rstrip()

# Input helpers
def read_int():
    return int(input())

def read_ints():
    return list(map(int, input().split()))

def read_str():
    return input()

def read_strs():
    return list(input().split(','))

def get_dividers(n):
    L = []
    for i in range(2,n+1):
        if n %i ==0:
            L.append(i)
    
    return L


def solve():
    # Write your solution here
    ranges = read_strs()
    answer = 0
    for couple_str in ranges:
        start, end = map(int, couple_str.split('-'))
        for num in range(start, end + 1):
            s_num = str(num)
            divs = get_dividers(len(s_num))
            
            for d in divs:
                sub_len = len(s_num) // d
                sub = s_num[:sub_len]
                if s_num == sub * d:
                    answer += num
                    break
    print(answer)

def main():
    # Uncomment for multiple test cases
    # t = read_int()
    # for _ in range(t):
    #     solve()
    
    solve()
    print("End")

if __name__ == "__main__":
    main()
