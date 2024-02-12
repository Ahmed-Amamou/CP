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

n, q = invr()
arr = [0]*n
for _ in range(q):
    # print(arr)
    l = inlt()
    op = l[0]
    if op == 1:
        somme = 0
        for i in range(l[1]-1, l[2]):
            somme+= arr[i]
        print(somme)
    else:
        for i in range(l[1]-1, l[2]):
            if (i+1)%l[3] == l[4]:
                arr[i]+=l[5]
