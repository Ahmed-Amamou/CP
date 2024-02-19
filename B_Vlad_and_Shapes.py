import math
import random
import sys
import string
 # input = sys.stdin.readline
 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():                              #For taking string inputs. Actually it returns a List of Characters, instead of a string,
    s = input()                          # which is easier to use in Python, because in Python, Strings are Immutable.
    return(list(s[:len(s) ]))
def invr():
    return(map(int,input().split())) #For taking space seperated integer variable inputs//
 
def construct_graph(num_nodes, edges):
    graph = {node: [] for node in range(1, num_nodes + 1)}
 
    for edge in edges:
        node1, node2 = edge
        graph[node1].append(node2)
        graph[node2].append(node1)
 
    return graph
#############################################
def is_square(grid):
    rows = len(grid)
    cols = len(grid[0])

    # Find the bounding box of ones
    min_row, max_row, min_col, max_col = float('inf'), 0, float('inf'), 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == '1':
                min_row = min(min_row, i)
                max_row = max(max_row, i)
                min_col = min(min_col, j)
                max_col = max(max_col, j)

    # Check if the bounding box is a square
    side_length = max(max_row - min_row, max_col - min_col) + 1

    for i in range(min_row, max_row + 1):
        for j in range(min_col, max_col + 1):
            if grid[i][j] != '1':
                return False

    return side_length * side_length == sum(row.count('1') for row in grid)

t = inp()
for _ in range(t):
    n=inp()
    L=[]
    for i in range(n):
        L.append(input())
    
    if(is_square(L)):
        print('SQUARE')
    else:
        print("TRIANGLE")