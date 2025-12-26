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


def solve():
    # Write your solution here
    L = read_strs()
    answer = 0
    for couple in L:
        couple = tuple(map(int,couple.split('-')))
        # print(couple)
        for i in range(couple[0],couple[1]+1):
            string = str(i)
            # print(string[:len(string)//2])
            # print(string[len(string)//2:])
            if (len(string)%2 == 0) and (string[:len(string)//2] == string[len(string)//2:]):
                answer += i
    print(answer)
    pass

def main():
    # Uncomment for multiple test cases
    # t = read_int()
    # for _ in range(t):
    #     solve()
    
    solve()

if __name__ == "__main__":
    main()
