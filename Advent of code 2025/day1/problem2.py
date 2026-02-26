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
    return list(input().split())

def solve():
    # Write your solution here
    position = 50
    result=  0
    for line in sys.stdin:
        
        line = line.rstrip('\n')
        direction = line[0]
        value = int(line[1:])
        # print(f"Direction: {direction}, Value: {value}")
        
            
        if (direction =='R'):
            for i in range(value):
                position +=1
                position%=100
                if((position )==0):
                    result+=1
        elif (direction =='L'):
            for i in range(value):
                position -=1
                position%=100
                if((position)==0):
                    result+=1
                
        
    # print(cnt)
    print(result)

def main():
    # Uncomment for multiple test cases
    # t = read_int()
    # for _ in range(t):
    #     solve()
    
    solve()

if __name__ == "__main__":
    main()
