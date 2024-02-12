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
def somG(r,n):
    sum = 0
    if (r == 1):
    
        sum = n
    
    else:
    
        sum = (1 - r**n) / (1 - r)
    
    return sum

t = inp()
for _ in range(t):
    n = inp()
    for i in range(2,32):
        if(n/somG(2,i) - int(n/somG(2,i)) == 0.0):
            print(int(n/somG(2,i)))
            break;
        
    