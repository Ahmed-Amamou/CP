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
t = inp()
while(t>0):    
    x = int(input().strip())
    
    a = []
    
    while x != 0:
        p = 1
        while (p << 1) <= x:
            p <<= 1
        
        if p == x:
            a.append(1)
            x -= p
        else:
            NEXT = p << 1
            if NEXT - x < x - p:
                a.append(-1)
                x = NEXT - x
            else:
                a.append(1)
                x -= p
        
        if x != 0:
            a.append(0)
    
    n = len(a)
    print(n)
    print(' '.join(map(str, a)))
    t-=1