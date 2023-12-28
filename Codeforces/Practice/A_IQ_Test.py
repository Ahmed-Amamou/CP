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

#go through the matrix two lines at a time 
# check if there already exists a 2*2 square of same color
def check2by2square(matrix):
    for i in range(3):
        for j in range(3):
            if matrix[i][j]==matrix[i+1][j]==matrix[i][j+1]==matrix[i+1][j+1]:
                return True
    return False
                                                                                                                        # i,j i,j+1 i+1,j
                                                                                                                        # i,j i,j+1 i+1,j+1
                                                                                                                        # ij i+1,j i+1,j+1
                                                                                                                        # i,j+1 i+1,j i+1,j+1

matrix=[]
for i in range(4):
    L=insr()
    matrix.append(L)
# print(matrix)
# print(check2by2square(matrix))
if check2by2square(matrix):
    print("YES")
    exit()
for i in range(3):
    for j in range(3):
        # print(i,j)
        if (matrix[i][j]==matrix[i][j+1]==matrix[i+1][j]) or matrix[i][j]==matrix[i][j+1]==matrix[i+1][j+1] or matrix[i][j]==matrix[i+1][j]==matrix[i+1][j+1] or matrix[i][j+1]==matrix[i+1][j]==matrix[i+1][j+1]:
            print("YES")
            exit()
print("NO")
    
            
            
