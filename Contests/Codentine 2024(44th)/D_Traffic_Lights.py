import math
import random
import sys
import string
 # input = sys.stdin.readline
 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(str,input().split())))
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
n, x = invr()
res=pos=0
for _ in range(n):
    triplet = inlt()
    triplet[1] = int(triplet[1])
    triplet[2] = int(triplet[2])
    res += triplet[1] - pos
    pos = triplet[1]
    if triplet[0] == 'R':
        if (res // triplet[2]) % 2 == 0:
            res += triplet[2] - (res % triplet[2])
    elif (res // triplet[2]) % 2 != 0:
        res += triplet[2] - (res % triplet[2]) 
print(res + x - pos)
      
    